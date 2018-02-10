/*You have two numbers represented by a linked list, where each node contains a single digit. 
The digits are stored in reverse order, such that the 1’s digit is at the head of the list. 
Write a function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
Output: 8 -> 0 -> 8
3+5=8, 1+9=10 5+2=7 from the carry:7+1=8*/
#include "linkAddTwoNumbers.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
using namespace std;
struct nodeAdd
{
	int key;
	nodeAdd *next;
};
void linkAddTwoNumbers::start()
{
	cout << "Adding two numbers\n";
	struct nodeAdd *p1 = NULL;
	struct nodeAdd *p2 = NULL;
	struct nodeAdd *sumNode = NULL;
	p1 = createMultipleNodes(p1, 3, 10);
	p2 = createMultipleNodes(p2, 3, 10);
	printNodes(p1);
	printNodes(p2);
	//addNodes(p1, p2);
	sumNode = addRecursively(p1, p2, false);
	printNodes(sumNode);
}
struct nodeAdd *linkAddTwoNumbers::addRecursively(struct nodeAdd *node, struct nodeAdd *node2, bool bCarried)
{
	struct nodeAdd *result = NULL;
	int sum;
	if (node != NULL && node2 != NULL)
	{
		sum = node->key + node2->key;
		if (bCarried)
		{
			sum++;
			bCarried = false;
		}
		if (sum > 10)
		{
			sum = sum % 10;
			bCarried = true;
		}
		result = insertAtEnd(result, sum);
		result->next = addRecursively(node->next, node2->next, bCarried);
	}
	return result;
}
struct nodeAdd *linkAddTwoNumbers::addNodes(struct nodeAdd *node, struct nodeAdd *node2)
{
	struct nodeAdd *sumNode = NULL;
	bool bCarryTheOne=false;
	int sum;
	while (node != NULL || node2 != NULL)
	{
		sum = node->key + node2->key;
		if (bCarryTheOne)
		{
			sum++;
			bCarryTheOne = false;
		}
		if (sum >= 10)
		{
			bCarryTheOne = true;
			sum = sum % 10;
		}
		sumNode = insertAtEnd(sumNode, sum);
		node = node->next;
		node2 = node2->next;
		
	}
	printNodes(sumNode);
	return sumNode;
}
struct nodeAdd *linkAddTwoNumbers::insertAtEnd(struct nodeAdd *node, int val)
{

	if (node == NULL)
	{
		node = newNode(val);
	}
	else
	{
		node->next = insertAtEnd(node->next,val);
	}
	return node;
}
struct nodeAdd *linkAddTwoNumbers::createMultipleNodes(struct nodeAdd *node, int amount, int rndmRange)
{
	int randVal;
	for (int i = 0; i < amount; i++)
	{
		randVal = rand() % rndmRange;
		node = insertAtStart(node, randVal);
	}
	return node;
}
struct nodeAdd *linkAddTwoNumbers::insertAtStart(struct nodeAdd *node, int val)
{
	if (node == NULL)
	{
		node = newNode(val);
	}
	else
	{
		struct nodeAdd *temp = (struct nodeAdd *)malloc(sizeof(new nodeAdd));
		temp->key = val;
		temp->next = node;
		node = temp;
	}
	return node;
}
struct nodeAdd *linkAddTwoNumbers::newNode(int val)
{
	struct nodeAdd *temp = (struct nodeAdd *)malloc(sizeof(new nodeAdd));
	temp->key = val;
	temp->next = NULL;
	return temp;
}
void linkAddTwoNumbers::printNodes(struct nodeAdd *node)
{
	cout << "Printing nodes\n";
	while (node != NULL)
	{
		cout << node->key << "\n";
		node = node->next;
	}
}
linkAddTwoNumbers::linkAddTwoNumbers()
{
}


linkAddTwoNumbers::~linkAddTwoNumbers()
{
}
