#include "minBinaryTree.h"
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
using namespace std;
void minBinaryTree::start()
{
	cout << "Minimal Binary Tree";
	struct node *root = NULL;
	std::vector<int> vecNum= { 1,2,3,4,5,6,7,8 };
	root = createMinTree(vecNum, 0, vecNum.size() - 1);
	//createMinTree(&root);
	printInorder(&root);
}
void minBinaryTree::minInsert(struct node **ref, int val)
{
	if ((*ref) == NULL)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		(*ref) = temp;
		return;
	}
	if ((*ref)->left != NULL && (*ref)->right == NULL)
	{

	}
	if ((*ref)->left == NULL)
	{
		minInsert(&(*ref)->left, val);
	}
	else if ((*ref)->right == NULL)
	{
		minInsert(&(*ref)->right, val);
	}
	else
	{
		minInsert(&(*ref)->left, val);
	}
}
struct minBinaryTree::node *minBinaryTree::createMinTree(std::vector<int>& vecNum, int start, int end)
{
	if (end < start)
	{
		return NULL;
	}
	int mid = (start+end) / 2;
	struct node *root = NULL;
	push(&root, vecNum[mid]);
	root->left = createMinTree(vecNum, start, mid-1);
	root->right = createMinTree(vecNum, mid + 1, end);
	return root;
}
minBinaryTree::minBinaryTree()
{
}


minBinaryTree::~minBinaryTree()
{
}
