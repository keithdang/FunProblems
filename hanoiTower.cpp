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
	int num = 4;
	struct node *stack1 = NULL;
	struct node *stack2 = NULL;
	struct node *stack3 = NULL;
	stack1 = createStack(stack1, num);
	printStack(stack1);
	cout << "\n";
	move(num, &stack1, &stack3, &stack2, 1, 3, 2);
	cout << "Printing stack 3";
	printStack(stack3);
}
void hanoiTower::move(int count, struct node **s1, struct node **s3, struct node **s2, int n1, int n3, int n2)
{
	if (count > 0)
	{
		move(count - 1, s1, s2, s3, n1, n2, n3);
		cout << "Move disk " << count << " from " << n1 << " to " << n3 << ".\n";
		popFromTo(s1, s3);
		move(count - 1, s2, s3, s1, n2, n3, n1);
	}
}
void hanoiTower::popFromTo(struct node **fromNode, struct node **toNode)
{
	while ((*fromNode)->next != NULL)
	{
		*fromNode = (*fromNode)->next;
	}
	*toNode = push(*toNode, (*fromNode)->num);
	*fromNode = (*fromNode)->prev;
	if ((*fromNode) != NULL)
	{
		(*fromNode)->next = NULL;
	}
}
struct hanoiTower::node *hanoiTower::createStack(struct node *node, int amount)
{
	for (int i = amount; i > 0; i--)
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
	cout << "\nPrinting from end to beg: ";
	do
	{
		cout << node->num;
		node = node->prev;
	} while (node != NULL);
}
hanoiTower::hanoiTower()
{
}


hanoiTower::~hanoiTower()
{
}
