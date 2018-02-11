//A cleaner and successful version of the original stack plates problem 3.3
#include "stackPlates2.h"
#include "stackPlates.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
#define plateLimit 5
using namespace std;

void stackPlates2::start()
{
	cout << "Stackin plates\n";
	std::vector<struct node> stackPlates = createPlateStacks(39);
	struct node *root = &stackPlates[0];
	stackPlates[0] = *pop(&root);
	printPlatesEnd2Beg(&stackPlates[0]);
}
struct stackPlates2::node *stackPlates2::pop(struct node **node)
{
	int val;
	struct node *root = NULL;
	while ((*node)->next != NULL)
	{
		(*node) = (*node)->next;
	}
	val = (*node)->plateNum;
	root = (*node)->prev;
	(*node) = NULL;
	cout << "\nPop:" <<val;
	return root;
}
std::vector<struct stackPlates2::node> stackPlates2::createPlateStacks(int numPlates)
{
	std::vector<struct node> stacks;
	for (int i = 0; i < numPlates; i = i + 5)
	{
		int leftOverPlates = numPlates - i;
		struct node *root = NULL;
		if (leftOverPlates < 5)
		{
			stacks.push_back(*createPlates(&root, leftOverPlates, 10));
		}
		else
		{
			stacks.push_back(*createPlates(&root, 5, 10));
		}
	}
	for (int j = 0; j < stacks.size(); j++)
	{
		printPlatesEnd2Beg(&stacks[j]);
	}
	
	return stacks;
}
struct stackPlates2::node *stackPlates2::createPlates(struct node **node, int numPlates, int range)
{
	int randNum;
	for (int i = 0; i < numPlates; i++)
	{
		randNum = rand() % range;
		*node = push(node,randNum);
	}
	return *node;
}
struct stackPlates2::node *stackPlates2::push(struct node **node, int val)
{
	struct node *newPlate = (struct node*)malloc(sizeof(struct node));
	newPlate->plateNum = val;
	newPlate->next = NULL;
	if (*node == NULL)
	{
		*node = newPlate;
		newPlate->prev = NULL;
		return *node;
	}
	while ((*node)->next != NULL)
	{
		*node = (*node)->next;
	}
	(*node)->next = newPlate;
	newPlate->prev = *node;
	return newPlate;
}
void stackPlates2::printPlatesEnd2Beg(struct node *node)
{
	cout << "\nPrinting Plates\n";
	while (node != NULL)
	{
		cout << node->plateNum;
		node = node->prev;
	}
}
stackPlates2::stackPlates2()
{
}


stackPlates2::~stackPlates2()
{
}
