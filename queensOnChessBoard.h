#pragma once
#define dimen 4
#include <vector>
class queensOnChessBoard
{
public:
	void start();
	void placeInitialQueens(int queenNum,  int currentArr[dimen][dimen]);
	bool placeRemainingQueens(int queenNum, int currentArr[dimen][dimen]);
	bool queensAround(int x, int y, int currentArr[dimen][dimen]);
	void printArray(int arr[dimen][dimen]);
	queensOnChessBoard();
	~queensOnChessBoard();
};

