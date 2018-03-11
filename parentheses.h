#pragma once
#include <string>
class parentheses
{
public:
	void start();
	void printCombos(int itL, int itR, int limit, std::string strCurrent);
	parentheses();
	~parentheses();
};

