#pragma once
class circularLinkedList
{
public:
	struct nodeCirc
	{
		int key;
		nodeCirc *next;
	};
	void start();
	void printNodes(struct nodeCirc *node);
	void printNumNodes(struct nodeCirc *node, int amount);
	struct nodeCirc *newNode(int val);
	struct nodeCirc *insertAtStart(struct nodeCirc *node,int val);
	struct nodeCirc *createMultipleNodes(struct nodeCirc *node,int amount, int range);
	struct nodeCirc *nodeActuallyBegins(struct nodeCirc *node);
	struct nodeCirc *endOfNode(struct nodeCirc *node);
	struct nodeCirc *connectTwoLists(struct nodeCirc *node, struct nodeCirc *node2);
	struct nodeCirc *findingBeginning(struct nodeCirc *node);
	struct nodeCirc *createCorruptedCircularList();
	circularLinkedList();
	~circularLinkedList();
};

