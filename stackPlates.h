#pragma once
#include <vector>
class stackPlates
{
public:
	struct node
	{
		int plateNum;
		node *prev;
		node *next;
	};
	void start();
	void printPlates(struct node *node);
	void printList(struct node *node);
	struct node *createPlates(struct node **node, int numPlates, int range, std::vector<struct node> &vecPlates);
	struct node *push(struct node **node, int val);
	stackPlates();
	~stackPlates();
};

