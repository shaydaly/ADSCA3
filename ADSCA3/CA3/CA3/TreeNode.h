#pragma once
#include"City.h"
class TreeNode {
	friend class BinarySearchTree;

private:
	TreeNode* left;
	TreeNode* right;
	City city;
public:
	TreeNode(City);
	bool isLeaf();
};