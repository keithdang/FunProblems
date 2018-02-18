#include "inorderSuccessor.h"
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
void inorderSuccessor::start()
{
	cout << "Inorder Successor\n";
	struct node *root = NULL;
	createUniqueTree(&root);
	printInorder(&root);
	int num = successor(&(root->left->right->right));
}
void inorderSuccessor::createUniqueTree(struct node **ref)
{
	push(ref, 20);
	push(ref, 8);
	push(ref, 22);
	push(ref, 4);
	push(ref, 12);
	push(ref, 10);
	push(ref, 14);
}
int inorderSuccessor::successor(struct node **ref)
{
	int data;
	struct node *temp = NULL;
	if ((*ref)->right != NULL)
	{
		data=goToMostLeft(&(*ref)->right);	
	}
	else
	{
		while ((temp = (*ref)->parent) != NULL)
		{
			if (temp->left == (*ref))
			{
				break;
			}
			(*ref) = temp;
		}
		data = temp->data;
		/*
		data = ((*ref)->parent)->data;
		int numComp = ((*ref)->parent)->left->data;
		if ((*ref)->data != numComp)
		{
			data = 99;
		}*/
	}
	return data;
}
int inorderSuccessor::goToMostLeft(struct node **ref)
{
	while ((*ref)->left != NULL)
	{
		(*ref) = (*ref)->left;
	}
	return (*ref)->data;
}
inorderSuccessor::inorderSuccessor()
{
}


inorderSuccessor::~inorderSuccessor()
{
}
