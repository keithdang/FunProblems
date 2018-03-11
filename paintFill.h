#pragma once
#define dimen 4
#include <tuple>
class paintFill
{
public:
	void start();
	void fill(int color, std::tuple<int, int> point, int arr[dimen][dimen]);
	void printArray(int arr[dimen][dimen]);
	paintFill();
	~paintFill();
};

