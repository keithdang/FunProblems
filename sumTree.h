#pragma once
#include "binaryTree.h"
#include <vector>
class sumTree: public binaryTree
{
public:
	struct linkedVector
	{
		std::vector<int> path;
		struct linkVector *next;
	};
	void start();
	int inorderSum(struct node **ref);
	void createDesiredTree(struct node **ref);
	bool getSumPathLink(struct node **ref, int num, std::vector<std::vector<int>> &path);
	bool findPathLink(struct node **ref, int num, std::vector<std::vector<int>> &path, int& pathNum);
	void printVecNodes(std::vector<std::vector<int>>  path, int num);

	bool getSumPath(struct node **ref, int num, std::vector<int> &path);
	bool findPath(struct node **ref, int num, std::vector<int> &path);
	bool sumVecPeth(std::vector<int> path,int num);

	void sumNodes(struct node **ref);
	sumTree();
	~sumTree();
};

