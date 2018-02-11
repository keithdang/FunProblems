#include "hanoiTower.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
using namespace std;

void hanoiTower::start()
{
	cout << "Hanoi tower problem";
	int num = 3;
	struct node *stack1 = NULL;
	struct node *stack2 = NULL;
	struct node *stack3 = NULL;
	stack1 = createStack(stack1, num);
	printStack(stack1);
	popFromTo(&stack1, &stack2);
	printStack(stack1);
	printStack(stack2);
}
void hanoiTower::popFromTo(struct node **fromNode, struct node **toNode)
{
	while ((*fromNode)->next != NULL)
	{
		*fromNode = (*fromNode)->next;
	}
	*toNode = push(*toNode, (*fromNode)->num);
	*fromNode= (*fromNode)->prev;
	(*fromNode)->next = NULL;
}
struct hanoiTower::node *hanoiTower::createStack(struct node *node, int amount)
{
	for (int i = 1; i <= amount; i++)
	{
		node = push(node, i);
	}
	return node;
}
struct hanoiTower::node *hanoiTower::push(struct node *node, int val)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->num = val;
	temp->next = NULL;
	if (node == NULL)
	{
		temp->prev = NULL;
		return temp;
	}
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = temp;
	temp->prev = node;
	return temp;
}
void hanoiTower::printStack(struct node *node)
{
	cout << "\nPrinting from beg to end: ";
	while (node->next != NULL)
	{
		cout << node->num;
		node = node->next;
	}
	cout << "\nPrinting from beg to end: ";
	while (node != NULL)
	{
		cout << node->num;
		node = node->prev;
	}
}
hanoiTower::hanoiTower()
{
}


hanoiTower::~hanoiTower()
{
}
