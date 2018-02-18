#pragma once
#include "binaryTree.h"
#include <vector>
class sumTree: public binaryTree
{
public:
	void start();
	int inorderSum(struct node **ref);
	bool getSumPath(struct node **ref, int num, std::vector<int> &path);
	bool findPath(struct node **ref, int num, std::vector<int> &path);
	bool sumVecPeth(std::vector<int> path,int num);
	sumTree();
	~sumTree();
};

