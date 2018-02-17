#include "binaryTree.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
using namespace std;
void binaryTree::binStart()
{
	cout << "Binary Tree\n";
	struct node *root = NULL;
	createTree(&root, 10, 10);
	cout << "Inorder\n";
	printInorder(&root);
	//push(&root, 5);
	//push(&root, 6);
}
void binaryTree::createBalTree(struct node **ref)
{
	push(ref, 5);
	push(ref, 3);
	push(ref, 8);
	push(ref, 2);
	push(ref, 4);
	push(ref, 7);
	push(ref, 9);
	//push(ref, 1);
}
void binaryTree::createTree(struct node **ref, int amount, int range)
{
	int randNum;
	for (int i = 0; i < amount; i++)
	{
		randNum = (rand() % range)+1;
		push(ref, randNum);
	}
}
void binaryTree::push(struct node **ref, int val)
{
	if ((*ref) == NULL)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		(*ref) = temp;
	}
	else
	{
		if (val > (*ref)->data)
		{
			push(&(*ref)->right, val);
		}
		else if (val < (*ref)->data)
		{
			push(&(*ref)->left, val);
		}
	}
}
void binaryTree::printInorder(struct node **ref)
{
	if ((*ref) == NULL)
	{
		return;
	}
	{
		printInorder(&(*ref)->left);
		cout << (*ref)->data;
		printInorder(&(*ref)->right);
	}
}
binaryTree::binaryTree()
{
}


binaryTree::~binaryTree()
{
}
