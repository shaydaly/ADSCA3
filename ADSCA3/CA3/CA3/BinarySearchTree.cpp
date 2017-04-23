#include "BinarySearchTree.h"
#include <cmath> 
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

string BinarySearchTree::getRootName() {
	return root->city.name;
}

void BinarySearchTree::add(City cityInput)
{
	if (!searchTree(root, cityInput.coordinates)) {
	TreeNode * toAdd = new TreeNode(cityInput);
	if (root == nullptr) {
		root = toAdd;
	}
	else {
		add(toAdd, root);
	}
}
}

void BinarySearchTree::add(TreeNode *toAdd, TreeNode *addHere)
{
	if (toAdd->city < addHere->city) {
		if (addHere->left == nullptr) {
			addHere->left = toAdd;
		}
		else {
			add(toAdd, addHere->left);
		}
	}
	else if (toAdd->city > addHere->city) {
		if (addHere->right == nullptr) {
			addHere->right = toAdd;
		}
		else {
			add(toAdd, addHere->right);
		}
	}
}

bool BinarySearchTree::searchTree(string)
{
	return false;
}

bool BinarySearchTree::searchTree(TreeNode *node, string cityName)
{
	if (node == nullptr) {
		cout << "Unknown" << endl;
		return false;
	}
	else if (node->city.name.compare(cityName) == 0) {
		cout << node->city;
		return true;
	}
	else if (node->city.name.compare(cityName) < 0) {
		searchTree(node->left, cityName);
	}
	else if (node->city.name.compare(cityName)>0) {
		searchTree(node->left, cityName);
	}
}

bool BinarySearchTree::searchTree(TreeNode *node, pair<double, double> coordinates)
{
	if (node == nullptr) {
		return false;
	}
	else if (node->city.coordinates.first == coordinates.first && node->city.coordinates.second == coordinates.second) {
		return true;
	}
	else {
		return searchTree(node->left, coordinates) || searchTree(node->right, coordinates);
	}
}



bool BinarySearchTree::searchTree(pair<double, double>)
{
	return false;
}

int BinarySearchTree::height()
{
	return height(root);
}

int BinarySearchTree::height(TreeNode *node)
{
	if (node == nullptr) {
		return -1;
	}
	else if (node->isLeaf()) {
		return 0;
	}
	else {
		return 1 + std::max(height(node->left), height(node->right));
	}
}
void BinarySearchTree::printPretty()
{
	printPretty(root);
}
void BinarySearchTree::printPretty(TreeNode * node, int indent)
{
	if (node != nullptr) {
		if (node->right) {
			printPretty(node->right, indent + 4);
		}
		if (indent) {
			cout << setw(indent) << ' ';
		}
		if (node->right) cout << " /\n" << setw(indent) << ' ';
		cout << node->city << "\n ";
		if (node->left) {
			cout << setw(indent) << ' ' << " \\\n";
			printPretty(node->left, indent + 4);
		}
	}
}
void BinarySearchTree::inorder()
{
	if (root!= nullptr) {
		inorder(root);
	}
}

void BinarySearchTree::inorder(TreeNode *node)
{
	if (node != nullptr) {
		inorder(node->left);
		cout << node->city;
		inorder(node->right);
	}
}


TreeNode * BinarySearchTree::findMin(TreeNode *node)
{
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

TreeNode * BinarySearchTree::findMax(TreeNode *node)
{
	while (node->right != nullptr) {
		node = node->left;
	}
	return node;
}


/*
**************************************************************************************

*    Usage: Used
*    Title: Calculating the distance between 2 latitudes and longitudes that are saved in a text file?
*    Author: Edward
*    Date: 2014
*    Code version: NA
*    Availability: http://stackoverflow.com/questions/10198985/calculating-the-distance-between-2-latitudes-and-longitudes-that-are-saved-in-a
*
***********************************************************************************
*/
double BinarySearchTree::calculateDistance(pair<double, double> co1, pair<double, double>co2)
{
	double lat1d = co1.first, lon1d = co1.second, lat2d = co2.first, lon2d = co2.second;
	double lat1r, lon1r, lat2r, lon2r, u, v;
	lat1r = deg2rad(lat1d);
	lon1r = deg2rad(lon1d);
	lat2r = deg2rad(lat2d);
	lon2r = deg2rad(lon2d);
	u = sin((lat2r - lat1r) / 2);
	v = sin((lon2r - lon1r) / 2);
	return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


void BinarySearchTree::deleteNode(string cityName)
{
	deleteNode(root, cityName);
}

void BinarySearchTree::deleteNode(pair<double, double>)
{
}

TreeNode * BinarySearchTree::deleteNode(TreeNode *node, string cityName)
{
	if (node != nullptr) {
		if (cityName.compare(node->city.name) < 0) {
			node->left = deleteNode(node->left, cityName);
		}
		else if (cityName.compare(node->city.name) > 0) {
			node->right = deleteNode(node->right, cityName);
		}
		else {
			if (node->left == nullptr && node->right == nullptr) {
				delete node;
				node = nullptr;
			}
			else if (node->left == nullptr) {
				TreeNode * temp = node;
				node = node->right;
				delete temp;
			}
			else if (node->right == nullptr) {
				TreeNode * temp = node;
				node = node->left;
				delete temp;
			}
			else {
				TreeNode * temp = findMin(node->right);
				node->city = temp->city;
				node->right = deleteNode(node->right, temp->city.name);
			}
		}
	}
	return node;
}
void BinarySearchTree::citiesNearby(pair<double, double> coordinates, double distance)
{
	citiesNearby(root, coordinates, distance);
}
void BinarySearchTree::citiesNearby(TreeNode *node , pair<double, double> coordinates, double distance)
{
	if (node != nullptr) {
		if (calculateDistance(coordinates, node->city.coordinates) < distance) {
			cout <<"\nDistance between the entered co-ordinates and "<<node->city.name<<"::" << calculateDistance(coordinates, node->city.coordinates) << " KM" << endl;
		}
		citiesNearby(node->left, coordinates, distance);
		citiesNearby(node->right, coordinates, distance);
	}
}



void BinarySearchTree::randomCityGenerator() {
	double latitude = 0, longitude = 0, averageTemp =0.0;
	int population = 0;
	string cityName="";
	for (int i = 0; i < 100; i++) {
		latitude = (double)rand() / 180;
		longitude = (double)rand() / 180;
		averageTemp = (double)rand() / 180;
		population = rand() % 1000000000;
		cityName = "City" + std::to_string(population);
		City city  = City(cityName, population, make_pair(latitude, longitude), averageTemp);
		//cout << city << endl;
		add(city);
	}
}

// This function converts decimal degrees to radians
double BinarySearchTree::deg2rad(double deg) {
	return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double BinarySearchTree::rad2deg(double rad) {
	return (rad * 180 / pi);
}










