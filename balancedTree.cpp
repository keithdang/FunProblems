#include "balancedTree.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
#include "binaryTree.h"
using namespace std;
void balancedTree::start()
{
	cout << "Balanced Tree\n";
	node *bal = NULL;
	createBalTree(&bal);
	cout << "\nInorder Balanced\n";
	printInorder(&bal);

	if (isPerfectTree(&bal))
	{
		cout << "\nThis is a perfect tree\n";
	}
	/*node *root = NULL;
	createTree(&root, 10, 10);
	cout << "Inorder Unbalanced\n";
	printInorder(&root);*/
}
bool balancedTree::checkIfBalanced(struct node **ref)
{
	return true;
}
bool balancedTree::isPerfectTree(struct node **ref)
{
	bool bExist = true;
	bool bBothNodesExist = ((*ref)->left != NULL) && ((*ref)->right != NULL);
	bool bNeitherExist = ((*ref)->left == NULL) && ((*ref)->right == NULL);
	if (bBothNodesExist)
	{
		bExist = (isPerfectTree(&(*ref)->left) && isPerfectTree(&(*ref)->right));
	}
	else if(!bNeitherExist)
	{
		bExist = false;
	}
	return bExist;
}
balancedTree::balancedTree()
{
}


balancedTree::~balancedTree()
{
}
