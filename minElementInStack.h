#pragma once
class minElementInStack
{
public:
	struct node
	{
		int data;
		node *prev;
		node *next;
	};
	void start();
	void printList(struct node *node);
	struct node *createList(struct node *node, int amount, int range);
	struct node *insertEnd(struct node *node, int val);
	minElementInStack();
	~minElementInStack();
};

