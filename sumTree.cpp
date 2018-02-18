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
	cout << "Finding paths of tree\n";
	struct node *root = NULL;
	createDesiredTree(&root);
	std::vector<int> path;
	int val = 18;
	std::vector<int> temp;
	std::vector<std::vector<int>> vecPath;
	vecPath.push_back(temp);
	if(getSumPathLink(&root, val, vecPath))
	{
		printVecNodes(vecPath, val);
	}
	sumNodes(&root);
}
void sumTree::sumNodes(struct node **ref)
{
	cout << "\nSumming all nodes in a tree\n";
	printInorder(ref);
	int count = inorderSum(ref);
	cout <<"\n"<< count << "\n";
}
void sumTree::createDesiredTree(struct node **ref)
{
	push(ref, 7);
	push(ref, 8);
	push(ref, 5);
	push(ref, 6);
	push(ref, 2);
	push(ref, 4);
	push(ref, 1);
}
void sumTree::printVecNodes(std::vector<std::vector <int>> path, int num)
{
	cout << "\nFound path(s) that sums to " << num << "\n";
	for (int i = 0; i < (path.size()-1); i++)
	{
		for (int j = 0; j < path[i].size(); j++)
		{
			cout << (path[i])[j];
		}
		cout << "\n";
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
bool sumTree::getSumPathLink(struct node **ref, int num, std::vector<std::vector<int>> &path)
{
	bool bSuccess = false;
	int numPath = 0;
	findPathLink(ref, num, path, numPath);
	if(path[0].size()>0)
	{
		bSuccess = true;
	}
	return bSuccess;
}
bool sumTree::findPathLink(struct node **ref, int num, std::vector<std::vector<int>> &path, int& pathNum)
{
    if ((*ref) == NULL)
	{
		return false;
	}
	path[pathNum].push_back((*ref)->data);
	bool bDonePath = ((*ref)->left == NULL) && ((*ref)->right == NULL);
	if (bDonePath && sumVecPeth(path[pathNum], num))
	{
		std::vector<int> newPath;
		path.push_back(path[pathNum]);

		pathNum++;
		path[pathNum].pop_back();
		return false;
	}
	if ((findPathLink(&(*ref)->left, num, path, pathNum)) || (findPathLink(&(*ref)->right, num, path,pathNum)))
	{
		return true;
	}
	path[pathNum].pop_back();
	return false;
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
