#pragma once
#include <vector>
class linkRemDupilcates
{
public:
	void start();
	struct nodeRd *insertAtStart(struct nodeRd *node, int item);
	void printNodes(struct nodeRd *node);
	bool findNodeOfValue(struct nodeRd *node, int val);
	bool deleteValInNode(struct nodeRd *node, int val);
	bool delDupInNode(struct nodeRd *node, std::vector<int> &buffer);
	void delDupUsingWhile(struct nodeRd *node);
	void delDupBetterWhile(struct nodeRd *node);
	linkRemDupilcates();
	~linkRemDupilcates();
};

