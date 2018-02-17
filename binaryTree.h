#pragma once
class binaryTree
{
public:
	struct node
	{
		int data;
		node *left, *right;
	};
	void binStart();
	void push(struct node **ref, int val);
	void createTree(struct node **ref, int amount, int range);
	void createBalTree(struct node **ref);
	void printInorder(struct node **ref);
	binaryTree();
	~binaryTree();
};

