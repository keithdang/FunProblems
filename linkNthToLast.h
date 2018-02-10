#pragma once
#include <vector>
class linkNthToLast
{
public:
	void start();
	struct nodeNL *newNode(int val);
	struct nodeNL *insertAtStart(struct nodeNL *node, int val);
	void printNodes(struct nodeNL *node);
	struct nodeNL *createMultipleNodes(struct nodeNL *node, int amount, int rndmRange);
	void printNthToLast(struct nodeNL *node, int element);
	struct nodeNL *nthToLast(struct nodeNL *node, int element);
	linkNthToLast();
	~linkNthToLast();
};

