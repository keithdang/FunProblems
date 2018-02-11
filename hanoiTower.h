#pragma once
class hanoiTower
{
public:
	struct node
	{
		int num;
		node *prev,*next;
	};
	void start();
	void printStack(struct node *node);
	struct node *createStack(struct node *node, int amount);
	struct node *push(struct node *node, int amount);
	void popFromTo(struct node **fromNode, struct node **toNode);
	hanoiTower();
	~hanoiTower();
};

