#pragma once
#include "binaryTree.h"
#include "vector"
class levelOrderTreeTran : public binaryTree
{
public:
	struct linkedList
	{
		int key;
		linkedList *next;
	};
	void start();
	int nLevels(struct node **ref);
	void printGivenLevel(struct node **ref, int level);
	void printLevels(struct node **ref);
	void createLevelLists(struct node **ref);
	void insertNodesAtGivenLevel(struct node **ref, struct linkedList **lvlList, int level);
	void pushLink(struct linkedList **ref, int val);
	levelOrderTreeTran();
	~levelOrderTreeTran();
};

