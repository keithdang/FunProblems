//2.2 Implement an algorithm to find the nth to last element of a singly linked list
#include "linkNthToLast.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
using namespace std;

struct nodeNL
{
	int key;
	nodeNL *next;
};
void linkNthToLast::start()
{
	cout << "Nth to last element of Linked List\n";
	struct nodeNL *root=NULL;
	root = createMultipleNodes(root, 10, 10);
	//printNodes(root);
	root = nthToLast(root, 6);
	printNodes(root);
	//printNthToLast(root, 5);
}
struct nodeNL *linkNthToLast::createMultipleNodes(struct nodeNL *node, int amount, int rndmRange)
{
	int randVal;
	for (int i = 0; i < amount; i++)
	{
		randVal = rand() % rndmRange;
		node = insertAtStart(node, randVal);
	}
	return node;
}
struct nodeNL *linkNthToLast::newNode(int val)
{
	struct nodeNL *temp = (struct nodeNL *)malloc(sizeof(new nodeNL));
	temp->key = val;
	temp->next = NULL;
	return temp;
}
struct nodeNL *linkNthToLast::insertAtStart(struct nodeNL *node, int val)
{
	if (node == NULL)
	{
		node = newNode(val);
	}
	else
	{
		struct nodeNL *temp = (struct nodeNL *)malloc(sizeof(new nodeNL));
		temp->next = node;
		temp->key = val;
		node = temp;
	}
	return node;
}
void linkNthToLast::printNodes(struct nodeNL *node)
{
	while (node != NULL)
	{
		cout << node->key << "\n";
		node = node->next;
	}
}
void linkNthToLast::printNthToLast(struct nodeNL *node, int element)
{
	cout << "Printing nth to last element\n";
	int count = 0;
	while (node != NULL && count < element)
	{
		node = node->next;
		count++;
	}
	while (node != NULL)
	{
		cout << node->key << "\n";
		node = node->next;
	}
}
struct nodeNL *linkNthToLast::nthToLast(struct nodeNL *node, int element)
{
	int count = 0;
	cout << "Nth to last element\n";
	struct nodeNL *p1 = node;
	struct nodeNL *p2 = node;
	struct nodeNL *head = p1;
	while (count < element)
	{
		p2 = p2->next;
		count++;
	}
	while (p2 != NULL)
	{
		p2 = p2->next;
		p1 = p1->next;
	}
	return p1;

}
linkNthToLast::linkNthToLast()
{
}
linkNthToLast::~linkNthToLast()
{
}
