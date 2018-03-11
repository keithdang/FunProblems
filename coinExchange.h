#pragma once
#include <vector>
class coinExchange
{
public:
	struct coinList
	{
		int quarters=0;
		int dimes=0;
		int nickles=0;
		int pennies=0;
	};
	void start();
	void convertToCoins(int value, std::vector<struct coinList>& combinationList, struct coinList currentList, int currencyOrder);
	coinExchange();
	~coinExchange();
};

