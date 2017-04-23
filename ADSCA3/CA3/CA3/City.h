#pragma once
#include<iostream>
#include<string>
using namespace std;

class City {
	friend class TreeNode;
	friend class BinarySearchTree;
private:
	pair<double, double> coordinates;
	string name;
	int population;
	double averageTemperature;
public:
	City();
	City(string, int, pair<double, double>, double);
	friend ostream& operator<<(ostream&, City& city);
	bool operator<(City&);
	bool operator>(City&);
	pair<double, double> getCoordinates();
};