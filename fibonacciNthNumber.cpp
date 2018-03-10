#include "fibonacciNthNumber.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
using namespace std;
void fibonacciNthNumber::start()
{
	int place = 6;
	cout << "Generating the " << place << " Fibonacci number"<<endl;
	cout << fibNumber(place)<<endl;
}
int fibonacciNthNumber::fibNumber(int placement)
{
	if (placement == 0)
	{
		return 0;
	}
	else if (placement == 1)
	{
		return 1;
	}
	else
	{
		return (fibNumber(placement - 1) + fibNumber(placement-2));
	}
}
fibonacciNthNumber::fibonacciNthNumber()
{
}


fibonacciNthNumber::~fibonacciNthNumber()
{
}
