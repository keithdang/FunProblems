#pragma once
#include "binaryTree.h"
class balancedTree : public binaryTree
{
public:
	void start();
	bool checkIfBalanced(struct node **ref);
	bool isPerfectTree(struct node **ref);
	int nLevels(struct node **ref, bool& bIsBalanced);
	int maxNum(int n, int m);
	balancedTree();
	~balancedTree();
private:
	bool bBalanced = true;
};

