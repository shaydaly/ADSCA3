#pragma once
#include"TreeNode.h"
#include<algorithm>
#include<iomanip>
using namespace std;
class BinarySearchTree {
private:
	TreeNode* root;
	void add(TreeNode*, TreeNode*);
	TreeNode* deleteNode(TreeNode*, string);
	int height(TreeNode*);
	void inorder(TreeNode*);
	bool searchTree(TreeNode*, string);
	bool searchTree(TreeNode*, pair<double, double>);
	void printPretty(TreeNode*, int indent = 0);
	TreeNode * findMin(TreeNode *);
	TreeNode * findMax(TreeNode*);
	void citiesNearby(TreeNode*, pair<double, double>, double);
	double calculateDistance(pair<double, double>, pair<double, double>);

public:
	BinarySearchTree();
	void add(City);
	void deleteNode(string);
	void deleteNode(pair<double, double>);
	bool searchTree(string);
	bool searchTree(pair<double, double>);
	int height();
	void inorder();
	void printPretty();
	void citiesNearby(pair<double, double>, double);
	double deg2rad(double);
	double rad2deg(double);
	string getRootName();
};