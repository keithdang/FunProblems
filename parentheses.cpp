//Implement an algorithm to print all valid(e.g., properly opened and closed) combinations of n - pairs of parentheses.
#include "parentheses.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;
void parentheses::start()
{
	cout << "Parentheses" << endl;
	int it = 3;
	printCombos(0, 0, it, "");
}
void parentheses::printCombos(int itL, int itR, int num, std::string current)
{
	string brack1 = "(";
	string brack2 = ")";
	if (itL < num)
	{
		string tmp=current + brack1;
		printCombos(itL + 1, itR, num, tmp);
	}
	if (itR < itL)
	{
		string tmp = current + brack2;
		printCombos(itL , itR+1, num, tmp);
	}
	if (itL == num && itR == num)
	{
		cout << current << endl;
	}
}
parentheses::parentheses()
{
}


parentheses::~parentheses()
{
}
