#pragma once
#include "binaryTree.h"
#include <vector>
class minBinaryTree : public binaryTree
{
public:
	void start();
	struct node *createMinTree(std::vector<int>& vecNum, int start, int end);
	void minInsert(struct node **ref,int val);
	minBinaryTree();
	~minBinaryTree();
};

