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
	void move(int count, struct node **node1, struct node **node3, struct node **node2, int n1,int n3,int n2);
	hanoiTower();
	~hanoiTower();
};

