//3.3 Imagine a (literal) stack of plates. If the stack gets too high, it might topple. 
//Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. 
//Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks, 
//and should create a new stack once the previous one exceeds capacity. 
//SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return 
//the same values as it would if there were just a single stack).
//FOLLOW UP
//Implement a function popAt(int index) which performs a pop operation on a specific sub - stack.
#include "stackPlates.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
#define plateLimit 5
using namespace std;
void stackPlates::start()
{
	cout << "Stacking plates\n";
	std::vector<struct node> setsOfStacks;
	struct node *root = NULL;
	struct node *last = NULL;
	//root = push(root, 7);
	//last = root;

	last = createPlates(&root, 8, 10, setsOfStacks);
	//setsOfStacks.push_back(*root);
	//cout << setsOfStacks[0].plateNum;
	//printList(root);
	for (int i = 0; i < setsOfStacks.size(); i++)
	{
		printList(&setsOfStacks[i]);
	}
	
	//printPlates(root);
	//printPlates(&setsOfStacks[1]);
	//printPlates(&setsOfStacks[0]);
	
	cout <<"last node"<< last->plateNum;
}
void stackPlates::printPlates(struct node *node)
{
	cout << "Printing Plates\n";
	while (node != NULL)
	{
		cout << node->plateNum<<"\n";
		node = node->next;
	}
}
void stackPlates::printList(struct node *node)
{
	struct node *last = NULL;
	cout << "\nTransversing forward direction\n";
	while (node != NULL)
	{
		cout << node->plateNum;
		last = node;
		node = node->next;
	}
	cout << "\nTransversing reverse direction\n";
	while (last != NULL)
	{
		cout << last->plateNum;
		last = last->prev;
	}
}
struct stackPlates::node *stackPlates::createPlates(struct node **node, int numPlates, int range, std::vector<struct node> &vecPlates)
{
	int randNum;
	bool bCreateNewPlateStack=false;
	struct node *last = *node;
	struct node *newPlateStack = NULL;
	int countStacks = 1;
	for (int i = 0; i < numPlates; i++)
	{
		randNum = rand() % range;
		if (i >= plateLimit*countStacks)
		{
			newPlateStack = push(&newPlateStack, randNum);
			if (!bCreateNewPlateStack)
			{
				last = newPlateStack;
				bCreateNewPlateStack = true;
			}
		}
		else
		{
			*node = push(node, randNum);
		}
	}
	if (bCreateNewPlateStack)
	{
		vecPlates.push_back(**node);
		vecPlates.push_back(*last);
	}
	else
	{
		vecPlates.push_back(**node);
	}
	
	return *node;
}
struct stackPlates::node *stackPlates::push(struct node **node, int val)
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
stackPlates::stackPlates()
{
}


stackPlates::~stackPlates()
{
}
