#pragma once
#include <vector>
class stackPlates2
{
public:
	struct node
	{
		int plateNum;
		node *next, *prev;
	};
	void start();
	struct node *push(struct node **node, int val);
	struct node *createPlates(struct node **node, int numPlates, int range);
	void printPlatesEnd2Beg(struct node *node);
	std::vector<struct node> createPlateStacks(int numPlates);
	int popAt(std::vector<struct node> *stackPlates, int index);
	struct node *pop(struct node **node);
	stackPlates2();
	~stackPlates2();
};

