#pragma once
#include "binaryTree.h"
class balancedTree : public binaryTree
{
public:
	void start();
	bool checkIfBalanced(struct node **ref);
	bool isPerfectTree(struct node **ref);
	balancedTree();
	~balancedTree();
};

