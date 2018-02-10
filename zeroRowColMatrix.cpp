//pg 48 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.
#include "zeroRowColMatrix.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#define columns 5
#define rows 4
using namespace std;
void zeroRowColMatrix::start()
{
	cout << "0 entire row and column of matrix\n\n";
	int arr[rows][columns] = { {1,2,3,4,5},{1,0,3,4,5},{ 1,2,3,4,5 } ,{ 1,2,3,0,5 } };
	printMatrix(arr);
	//zeroMatrix(arr);
	zeroMatrix2(arr);
}
void zeroRowColMatrix::printMatrix(int arr[rows][columns])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void zeroRowColMatrix::zeroMatrix(int arr[rows][columns])
{
	std::vector<std::tuple<int, int>> zeroCoords;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (arr[i][j] == 0)
			{
				zeroCoords.push_back({ i,j });
			}
		}
	}
	for (int p = 0; p < zeroCoords.size(); p++)
	{
		for (int k = 0; k < rows; k++)
		{
			arr[k][std::get<1>(zeroCoords[p])] = 0;
			for (int m = 0; m < columns; m++)
			{
				arr[std::get<0>(zeroCoords[p])][m] = 0;
			}
		}
	}
	printMatrix(arr);
}
void zeroRowColMatrix::zeroMatrix2(int arr[rows][columns])
{
	int *zeroRow = new int[rows];
	int *zeroCol = new int[columns];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (arr[i][j] == 0)
			{
				zeroRow[i] = 1;
				zeroCol[j] = 1;
			}
		}
	}
	for (int k = 0; k < rows; k++)
	{
		for (int m = 0; m < columns; m++)
		{
			if (zeroRow[k] == 1 || zeroCol[m] == 1)
			{
				arr[k][m] = 0;
			}
		}
	}
	printMatrix(arr);
}
zeroRowColMatrix::zeroRowColMatrix()
{
}


zeroRowColMatrix::~zeroRowColMatrix()
{
}
