//3.2 Push,pop,min element in O(1) time
#include "minElementInStack.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
using namespace std;
int minElement;
void minElementInStack::start()
{
	cout << "Min stack element\n";
	struct node *root = NULL;
	struct node *last = NULL;
	int num = 2;
	root = insertEnd(root, num);
	minElement = num;
	last = createList(root, 3, 10);
	printList(root);
	cout << "\nBeg:" << root->data<<"\n";
	cout << "\nEnd:" << last->data << "\n";
	cout << "\nMin:" << minElement << "\n";
}
void minElementInStack::printList(struct node *node)
{
	cout << "Printing List\n";
	while (node != NULL)
	{
		cout << node->data<<"\n";
		node = node->next;
	}
}
struct minElementInStack::node *minElementInStack::createList(struct node *node, int amount, int range)
{
	int randNum;
	for (int i = 0; i < amount; i++)
	{
		randNum = rand() % range;
		node = insertEnd(node, randNum);
		if (minElement > randNum)
		{
			minElement = randNum;
		}
	}
	return node;
}
struct minElementInStack::node *minElementInStack::insertEnd(struct node *node, int val)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = NULL;
	if (node == NULL)
	{
		newNode->prev = NULL;
		node = newNode;
		return node;
	}
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = newNode;
	newNode->prev = node;
	return newNode;
}




















/*
void minElementInStack::start()
{
	cout << "Min Element In Stack\n";
	struct node *root = NULL;
	root=insertEnd(root, 5);
	cout << root->data;
	root=insertEnd(root, 6);
	cout << root->data;
}	
struct minElementInStack::node *minElementInStack::newNode(int val)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = val;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
struct minElementInStack::node * minElementInStack::insertEnd(struct node *node, int val)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *last = node;
	temp->data = val; 
	temp->next = NULL;
	
	if (node == NULL)
	{
		temp->prev = NULL;
		node = temp;
		return node;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = temp;
	temp->prev = last;
	return temp;
}*/
minElementInStack::minElementInStack()
{
}


minElementInStack::~minElementInStack()
{
}
