#include "TreeNode.h"

TreeNode::TreeNode(City city)
{
	TreeNode::city = city;
	left = nullptr;
	right = nullptr;
}

bool TreeNode::isLeaf()
{
	if (left == nullptr && right == nullptr) {
		return true;
	}
	return false;
}
