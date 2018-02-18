#include "levelOrderTreeTran.h"
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
void levelOrderTreeTran::start()
{
	cout << "Level Order Tree Transversal\n";
	struct node *root = NULL;
	createBalTree(&root);
	printInorder(&root);
	printLevels(&root);
	createLevelLists(&root);
}
void levelOrderTreeTran::createLevelLists(struct node **ref)
{
	std::vector<struct linkedList> root;
	int height = nLevels(ref);
	cout << "\nHeight: " << height << "\n";
	for (int i = 1; i <= height; i++)
	{
		struct linkedList *temp = NULL;
		//cout << "\nPrinting level " << i << "\n";
		insertNodesAtGivenLevel(ref, &temp, i);
		root.push_back(*temp);
		//printGivenLevel(ref, i);
	}
}
void levelOrderTreeTran::pushLink(struct linkedList **ref, int val)
{
	if ((*ref) == NULL)
	{
		struct linkedList *temp = (struct linkedList*)malloc(sizeof(struct linkedList));
		temp->key = val;
		temp->next = NULL;
		(*ref) = temp;
	}
	else
	{
		pushLink(&(*ref)->next, val);
	}
}
void levelOrderTreeTran::printLevels(struct node **ref)
{
	int height = nLevels(ref);
	cout << "\nHeight: " << height << "\n";
	for (int i = 1; i <= height; i++)
	{
		cout << "\nPrinting level " << i << "\n";
		printGivenLevel(ref, i);
	}
}
void levelOrderTreeTran::insertNodesAtGivenLevel(struct node **ref, struct linkedList **lvlList, int level)
{
	if ((*ref) == NULL)
	{
		return;
	}
	if (level == 1)
	{
		pushLink(lvlList, (*ref)->data);
	}
	else
	{
		insertNodesAtGivenLevel(&(*ref)->left,lvlList, level - 1);
		insertNodesAtGivenLevel(&(*ref)->right,lvlList, level - 1);
	}
}
void levelOrderTreeTran::printGivenLevel(struct node **ref, int level)
{
	if ((*ref) == NULL)
	{
		return;
	}
	if (level == 1)
	{
		cout << (*ref)->data;
	}
	else
	{
		printGivenLevel(&(*ref)->left, level - 1);
		printGivenLevel(&(*ref)->right, level - 1);
	}
}
int levelOrderTreeTran::nLevels(struct node **ref)
{
	int levels = 0;
	int leftCount = 0;
	int rightCount = 0;
	if ((*ref) != NULL)
	{
		levels = 1;
		if ((*ref)->left != NULL)
		{
			leftCount = nLevels(&(*ref)->left);
		}
		if ((*ref)->right != NULL)
		{
			rightCount = nLevels(&(*ref)->right);
		}
		
		int nMax = max(leftCount, rightCount);
		levels += nMax;
	}
	return levels;
}
levelOrderTreeTran::levelOrderTreeTran()
{
}


levelOrderTreeTran::~levelOrderTreeTran()
{
}
