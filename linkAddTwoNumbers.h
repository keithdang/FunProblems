#pragma once

class linkAddTwoNumbers
{
public:
	void start();
	struct nodeAdd *insertAtStart(struct nodeAdd *node, int val);
	struct nodeAdd *insertAtEnd(struct nodeAdd *node, int val);
	struct nodeAdd *newNode(int val);
	struct nodeAdd *linkAddTwoNumbers::createMultipleNodes(struct nodeAdd *node, int amount, int rndmRange);
	void printNodes(struct nodeAdd *node);
	struct nodeAdd *addNodes(struct nodeAdd *node, struct nodeAdd *node2);
	struct nodeAdd *addRecursively(struct nodeAdd *node, struct nodeAdd *node2, bool bCarried);
	linkAddTwoNumbers();
	~linkAddTwoNumbers();
};

