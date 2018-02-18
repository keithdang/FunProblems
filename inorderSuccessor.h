#pragma once
#include "binaryTree.h"
class inorderSuccessor : public binaryTree
{
public:
	void start();
	int successor(struct node **ref);
	int goToMostLeft(struct node **ref);
	void createUniqueTree(struct node **ref);
	inorderSuccessor();
	~inorderSuccessor();
};

