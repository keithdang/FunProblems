//Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent), 
//write code to calculate the number of ways of representing n cents.
#include "coinExchange.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
void coinExchange::start()
{
	int cents = 27;
	std::vector<struct coinList> combinationList;//
	coinList tmpList;
	convertToCoins(cents, combinationList, tmpList, 5);
	cout << "Combinations to represent " << cents << " in coins: " << combinationList.size() << endl;
	for (int i = 0; i < combinationList.size(); i++)
	{
		cout << "Q:" << combinationList[i].quarters << " , D:" << combinationList[i].dimes << " , N:" << combinationList[i].nickles << " , P:" << combinationList[i].pennies << endl;
	}
}
void coinExchange::convertToCoins(int value, std::vector<struct coinList>& combinationList, struct coinList currentList, int currencyOrder)
{
	switch (currencyOrder)
	{
		case 1:currentList.pennies++;
			break;
		case 2:currentList.nickles++;
			break;
		case 3:currentList.dimes++;
			break;
		case 4:currentList.quarters++;
			break;
	}
	if (value >= 25 && currencyOrder > 3)
	{
		convertToCoins(value - 25, combinationList, currentList, 4);
	}
	if (value >= 10 && currencyOrder > 2)
	{
		convertToCoins(value - 10, combinationList, currentList, 3);
	}
	if (value >= 5 && currencyOrder > 1)
	{
		convertToCoins(value - 5, combinationList, currentList, 2);
	}
	if (value >= 1)
	{
		convertToCoins(value - 1, combinationList, currentList, 1);
	}
	if (value == 0)
	{
		combinationList.push_back(currentList);
	}
}
coinExchange::coinExchange()
{
}


coinExchange::~coinExchange()
{
}
