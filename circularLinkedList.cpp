#include "circularLinkedList.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
using namespace std;

void circularLinkedList::start()
{
	cout << "Circular Linked List\n";
	struct circularLinkedList::nodeCirc *root = createCorruptedCircularList();
	struct circularLinkedList::nodeCirc *circle = findingBeginning(root);
	cout << "Circle starts at: " << circle->key;
}
struct circularLinkedList::nodeCirc *circularLinkedList::createCorruptedCircularList()
{
	struct circularLinkedList::nodeCirc *root = NULL;
	struct circularLinkedList::nodeCirc *root2 = NULL;
	struct circularLinkedList::nodeCirc *head = NULL;
	struct circularLinkedList::nodeCirc *tail = NULL;
	struct circularLinkedList::nodeCirc *head2 = NULL;
	struct circularLinkedList::nodeCirc *tail2 = NULL;
	root2 = createMultipleNodes(root2, 8, 10);
	root = createMultipleNodes(root, 3, 10);
	head2 = root2;
	tail2 = endOfNode(root2);
	tail2->next = head2;
	head = connectTwoLists(root, head2);
	printNumNodes(head, 15);
	return head;
}
struct circularLinkedList::nodeCirc *circularLinkedList::findingBeginning(struct circularLinkedList::nodeCirc *head)
{
	struct circularLinkedList::nodeCirc *n1 = head;
	struct circularLinkedList::nodeCirc *n2 = head;
	while (n2->next != NULL)
	{
		n1 = n1->next;
		n2 = n2->next->next;
		if(n1==n2)
		{
			break;
		}
	}
	if (n2->next == NULL)
	{
		return NULL;
	}
	n1 = head;
	while (n1 != n2)
	{
		n1 = n1->next;
		n2 = n2->next;
	}
	return n2;
}
struct circularLinkedList::nodeCirc *circularLinkedList::connectTwoLists(struct circularLinkedList::nodeCirc *node, struct circularLinkedList::nodeCirc *node2)
{
	struct circularLinkedList::nodeCirc *head = node;
	while (node->next !=NULL)
	{
		node = node->next;
	}
	node->next = node2;
	return head;
}

void circularLinkedList::printNumNodes(struct circularLinkedList::nodeCirc *node, int amount)
{
	cout << "\nPrinting " << amount << " of nodes\n";
	int count = 0;
	while (count < amount)
	{
		cout << node->key << "\n";
		node = node->next;
		count++;
	}
}
struct circularLinkedList::nodeCirc *circularLinkedList::nodeActuallyBegins(struct circularLinkedList::nodeCirc *node)
{
	cout << "\nChecking...\n";
	unordered_set<int> buffer;
	while (node != NULL)
	{
		unordered_set<int>::const_iterator got = buffer.find(node->key);
		if (got == buffer.end())
		{
			buffer.insert(node->key);
			node = node->next;
		}
		else
		{
			break;
		}
	}
	cout << node->key;
	return node;
}
struct circularLinkedList::nodeCirc *circularLinkedList::endOfNode(struct circularLinkedList::nodeCirc *node)
{
	while (node->next != NULL)
	{
		node = node->next;
	}
	return node;
}
struct circularLinkedList::nodeCirc *circularLinkedList::newNode(int val)
{
	struct circularLinkedList::nodeCirc *temp = (struct circularLinkedList::nodeCirc *)malloc(sizeof(new circularLinkedList::nodeCirc));
	temp->key = val;
	temp->next = NULL;
	return temp;
}
struct circularLinkedList::nodeCirc *circularLinkedList::insertAtStart(struct circularLinkedList::nodeCirc *node, int val)
{
	if (node == NULL)
	{
		node = newNode(val);
	}
	else
	{
		struct circularLinkedList::nodeCirc *temp = (struct circularLinkedList::nodeCirc *)malloc(sizeof(new circularLinkedList::nodeCirc));
		temp->key = val;
		temp->next = node;
		node = temp;
	}
	return node;
}
struct circularLinkedList::nodeCirc *circularLinkedList::createMultipleNodes(struct circularLinkedList::nodeCirc *node, int amount, int range)
{
	cout << "Nodes\n";
	int randNum;
	for (int i = 0; i < amount; i++)
	{
		randNum = rand() % 10;
		node = insertAtStart(node, randNum);
	}
	printNodes(node);
	return node;
}
void circularLinkedList::printNodes(struct circularLinkedList::nodeCirc *node)
{
	while (node != NULL)
	{
		cout << node->key << "\n";
		node = node->next;
	}
}
circularLinkedList::circularLinkedList()
{
}


circularLinkedList::~circularLinkedList()
{
}
