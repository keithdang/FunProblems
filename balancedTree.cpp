#include "balancedTree.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
#include <math.h>
#include <cmath>
#include "binaryTree.h"
using namespace std;
void balancedTree::start()
{
	cout << "Balanced Tree\n";
	node *bal = NULL;
	createBalTree(&bal);
	//createTree(&bal, 8, 9);
	cout << "\nInorder Balanced\n";
	printInorder(&bal);

	if (isPerfectTree(&bal))
	{
		cout << "\nThis is a perfect tree\n";
	}
	bool bIsBalanced = true;
	int num = nLevels(&bal, bIsBalanced);
	cout <<"\nTree has "<<num << " levels\n";
	if (bIsBalanced)
	{
		cout << "Tree is balanced\n";
	}
	else
	{
		cout << "Tree is not balanced\n";
	}
	/*node *root = NULL;
	createTree(&root, 10, 10);
	cout << "Inorder Unbalanced\n";
	printInorder(&root);*/
}
int balancedTree::nLevels(struct node **ref, bool& bIsBalanced)
{
	int levels = 0;
	int leftCount = 0;
	int rightCount = 0;
	if ((*ref) != NULL)
	{
		levels = 1;
		if ((*ref)->left != NULL)
		{
			leftCount = nLevels(&(*ref)->left, bIsBalanced);
		}
		if ((*ref)->right != NULL)
		{
			rightCount = nLevels(&(*ref)->right, bIsBalanced);
		}
		int nMax = maxNum(leftCount, rightCount);
		if (abs(leftCount - rightCount) >= 2)
		{
			bBalanced = false;
			bIsBalanced = false;
		}
		levels += nMax;
	}
	return levels;
}
int balancedTree::maxNum(int n, int m)
{
	int num=0;
	if (m > n)
	{
		num = m;
	}
	else
	{
		num = n;
	}
	return num;
}
bool balancedTree::checkIfBalanced(struct node **ref)
{
	return true;
}
bool balancedTree::isPerfectTree(struct node **ref)
{
	bool bExist = true;
	bool bBothNodesExist = ((*ref)->left != NULL) && ((*ref)->right != NULL);
	bool bNeitherExist = ((*ref)->left == NULL) && ((*ref)->right == NULL);
	if (bBothNodesExist)
	{
		bExist = (isPerfectTree(&(*ref)->left) && isPerfectTree(&(*ref)->right));
	}
	else if(!bNeitherExist)
	{
		bExist = false;
	}
	return bExist;
}
balancedTree::balancedTree()
{
}


balancedTree::~balancedTree()
{
}
