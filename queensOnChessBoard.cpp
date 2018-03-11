#include "queensOnChessBoard.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
void queensOnChessBoard::start()
{
	cout << "Queens on a chess board"<< endl;
	int arr[dimen][dimen] = { 0 };
	printArray(arr);
	std::vector<int[dimen][dimen]> arrList;
	placeInitialQueens(dimen,  arr);
}
void queensOnChessBoard::placeInitialQueens(int queenNum, int currentArr[dimen][dimen])
{
	queenNum--;
	for (int i = 0; i < dimen; i++)
	{
		currentArr[0][i] = 1;
		placeRemainingQueens(queenNum, currentArr);
		int arr[dimen][dimen] = { 0 };
		currentArr = arr;
	}
}
bool queensOnChessBoard::placeRemainingQueens(int queenNum, int currentArr[dimen][dimen])
{
	if (queenNum > 0)
	{
		for (int i = 0; i < dimen; i++)
		{
			for (int j = 0; j < dimen; j++)
			{
				if (!queensAround(i, j, currentArr))
				{
					queenNum--;
					currentArr[i][j] = 1;
					if (!placeRemainingQueens(queenNum, currentArr))
					{
						queenNum++;
						currentArr[i][j] = 0;
					}
					else
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	else
	{
		cout << endl;
		printArray(currentArr);
		return true;
	}
}
bool queensOnChessBoard::queensAround(int x, int y,int currentArr[dimen][dimen])
{
	bool bQueenFound=false;
	//horizontal
	for (int i = 0; i < dimen; i++)
	{
		if (currentArr[x][i] == 1)
		{
			bQueenFound = true;
			break;
		}
	}
	if (!bQueenFound)
	{
		//vertical
		for (int j = 0; j < dimen; j++)
		{
			if (currentArr[j][y] == 1)
			{
				bQueenFound = true;
				break;
			}
		}
		//diagonal
		if (!bQueenFound)
		{
			for (int k = 0; k < dimen; k++)
			{
				//checking upper left diagnoal limit
				if ((x - k) >= 0 && (y - k) >= 0)
				{
					if (currentArr[x-k][y-k] == 1)
					{
						bQueenFound = true;
						break;
					}
				}
				//checking upper right diagnoal limit
				if ((x - k) >= 0 && (y + k) < dimen)
				{
					if (currentArr[x - k][y + k] == 1)
					{
						bQueenFound = true;
						break;
					}
				}
				//checking lower left diagnoal limit
				if ((x + k) < dimen && (y - k) >= 0)
				{
					if (currentArr[x + k][y - k] == 1)
					{
						bQueenFound = true;
						break;
					}
				}
				//checking lower right diagnoal limit
				if ((x + k) < dimen && (y + k) < dimen)
				{
					if (currentArr[x + k][y + k] == 1)
					{
						bQueenFound = true;
						break;
					}
				}
			}
		}
	}
	return bQueenFound;
}
void queensOnChessBoard::printArray(int arr[dimen][dimen])
{
	for (int i = 0; i < dimen; i++)
	{
		for (int j = 0; j < dimen; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
queensOnChessBoard::queensOnChessBoard()
{
}


queensOnChessBoard::~queensOnChessBoard()
{
}
