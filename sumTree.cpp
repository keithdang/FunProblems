#include "sumTree.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include "binaryTree.h"
using namespace std;
void sumTree::start()
{
	cout << "Summing all nodes in a tree\n";
	struct node *root = NULL;
	createTree(&root, 9, 13);
	printInorder(&root);
	int count = inorderSum(&root);
	std::vector<int> path;
	int val = 27;
	if (getSumPath(&root, val, path))
	{
		cout << "\nFound path that sums to " << val << "\n";
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i];
		}
	}
}
bool sumTree::sumVecPeth(std::vector<int> path, int num)
{
	int total = 0;
	for (int i = 0; i < path.size(); i++)
	{
		total += path[i];
	}
	return (total == num);
}
bool sumTree::findPath(struct node **ref, int num, std::vector<int> &path)
{
	if ((*ref) == NULL)
	{
		return false;
	}
	path.push_back((*ref)->data);
	bool bDonePath = ((*ref)->left == NULL)  && ((*ref)->right==NULL);
	if (bDonePath && sumVecPeth(path, num))
	{
		return true;
	}
	if ((findPath(&(*ref)->left, num, path)) || (findPath(&(*ref)->right, num, path)))
	{
		return true;
	}
	path.pop_back();
	return false;
}
bool sumTree::getSumPath(struct node **ref, int num, std::vector<int> &path)
{
	bool bSuccess = false;
	if (findPath(ref, num, path))
	{
		bSuccess = true;
	}
	return bSuccess;
}
int sumTree::inorderSum(struct node **ref)
{
	int ret=0;
	if((*ref)!=NULL)
	{
		ret += inorderSum(&(*ref)->left);
		ret += (*ref)->data;
		ret += inorderSum(&(*ref)->right);
	}
	return ret;
}

sumTree::sumTree()
{
}


sumTree::~sumTree()
{
}
