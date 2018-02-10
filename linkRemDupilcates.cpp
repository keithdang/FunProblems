#include "linkRemDupilcates.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
using namespace std;
struct nodeRd
{
	int key;
	nodeRd *nextNode;
};
void linkRemDupilcates::start()
{
	cout << "Remove duplicates from unsorted linked list\n";
	struct nodeRd *root = NULL;
	root = insertAtStart(root, 15);
	root = insertAtStart(root, 12);
	root = insertAtStart(root,5);
	root = insertAtStart(root, 7);
	root = insertAtStart(root, 8);
	root = insertAtStart(root, 2);
	root = insertAtStart(root, 1);
	root = insertAtStart(root, 7);
	root = insertAtStart(root, 7);
	root = insertAtStart(root, 5);
	printNodes(root);
	cout << "Removing duplicates\n";
	std::vector<int> buffer;
	delDupUsingWhile(root);
	//delDupBetterWhile(root);
}

struct nodeRd *linkRemDupilcates::insertAtStart(struct nodeRd *head,int item)
{
	struct nodeRd *temp = (struct nodeRd *)malloc(sizeof(new nodeRd));
	temp->key = item;
	temp->nextNode = NULL;
	if (head != NULL)
	{
		temp->nextNode = head;
	}
	head = temp;
	return head;
}
void linkRemDupilcates::printNodes(struct nodeRd *node)
{
	while (node != NULL)
	{
		cout << node->key << "\n";
		node = node->nextNode;
	}
}
bool linkRemDupilcates::findNodeOfValue(struct nodeRd *node, int val)
{
	bool bFound = false;
	while (node != NULL)
	{
		if (node->key == val)
		{
			bFound = true;
		}
		node = node->nextNode;
	}
	return bFound;
}
bool linkRemDupilcates::deleteValInNode(struct nodeRd *node, int val)
{
	bool bFound = false;
	if (node != NULL)
	{
		if (node->key == val)
		{
			cout << "FOUND\n";
			bFound = true;
		}
		else
		{
			if (deleteValInNode(node->nextNode, val))
			{
				struct nodeRd *temp = (struct nodeRd *)malloc(sizeof(new nodeRd));
				temp = node->nextNode->nextNode;
				node->nextNode = temp;
			}
		}
	}
	return bFound;
}
bool linkRemDupilcates::delDupInNode(struct nodeRd *node, vector<int> &buffer)
{
	bool bFound = false;
	if (node != NULL)
	{
		if (buffer.size() == 0)
		{
			buffer.push_back(node->key);
		}
		else
		{
			for (int i = 0; i < buffer.size(); i++)
			{
				if (node->key == buffer[i])
				{
					cout << "FOUND\n";
					return true;
				}
			}
			if (!bFound)
			{
				buffer.push_back(node->key);
			}
		}
		if (delDupInNode(node->nextNode, buffer))
		{
			struct nodeRd *temp = (struct nodeRd *)malloc(sizeof(new nodeRd));
			temp = node->nextNode->nextNode;
			node->nextNode = temp;
			delDupInNode(node->nextNode, buffer);
		}
	}
	return bFound;
}
void linkRemDupilcates::delDupUsingWhile(struct nodeRd *node)
{
	std::unordered_set<int> buff;
	struct nodeRd *head = (struct nodeRd *)malloc(sizeof(new nodeRd));
	if (node != NULL)
	{
		buff.insert(node->key);
		head = node;
	}
	while (node != NULL)
	{
		if (node->nextNode != NULL)
		{
			std::unordered_set<int>::const_iterator got = buff.find(node->nextNode->key);
			if (got == buff.end())
			{
				buff.insert(node->nextNode->key);
				node = node->nextNode;
			}
			else
			{
				struct nodeRd *temp = (struct nodeRd *)malloc(sizeof(new nodeRd));
				temp = node->nextNode->nextNode;
				node->nextNode = temp;
			}
		}
		else
		{
			break;
		}
	}
	printNodes(head);
}
void linkRemDupilcates::delDupBetterWhile(struct nodeRd *node)
{
	if (node == NULL)
	{
		return;
	}
	struct nodeRd *previous = node;
	struct nodeRd *current = previous->nextNode;
	while (current != NULL)
	{
		struct nodeRd *runner = node;
		while (runner != current)
		{
			if (runner->key == current->key)
			{
				struct nodeRd *temp = current->nextNode;
				previous->nextNode = temp;
				current = temp;
				break;
			}
			runner = runner->nextNode;
		}
		if (runner == current)
		{
			previous = current;
			current = current->nextNode;
		}
	}
	/*std::unordered_set<int> buffer;
	struct nodeRd *previous = NULL;//(struct nodeRd *)malloc(sizeof(new nodeRd));
	struct nodeRd *head = (struct nodeRd *)malloc(sizeof(new nodeRd));
	
	while (node != NULL)
	{
		std::unordered_set<int>::const_iterator got = buffer.find(node->key);
		if (got == buffer.end())
		{
			buffer.insert(node->key);
			if (previous = NULL)
			{
				previous = node;
				head = previous;
			}
			else
			{
				previous = node;
			}
		}
		else
		{
			previous->nextNode = node->nextNode;
		}
		previous = previous->nextNode;
		node = node->nextNode;
	}
	printNodes(head);*/

}
linkRemDupilcates::linkRemDupilcates()
{
}


linkRemDupilcates::~linkRemDupilcates()
{
}
