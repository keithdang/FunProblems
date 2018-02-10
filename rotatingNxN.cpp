#include "rotatingNxN.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
#define dimen 3
void rotatingNxN::start()
{
	std::cout << "Rotating NxN matrix\n";
	int arr[dimen][dimen] = { { 1,2,3 },{ 1,0,3 },{ 3,4,5 } };
	printMatrix(arr);
	cout << "\n";
	printRotated(arr);
	cout << "\n";
	rotateMatrix(arr);
}
void rotatingNxN::printMatrix(int arr[dimen][dimen])
{
	for (int i = 0; i < dimen; i++)
	{
		for (int j = 0; j < dimen; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void rotatingNxN::printRotated(int arr[dimen][dimen])
{

	for (int i = 0; i < dimen; i++)
	{
		for (int j = 0; j < dimen; j++)
		{
			cout << arr[j][(dimen - 1) - i] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void rotatingNxN::rotateMatrix(int arr[dimen][dimen])
{
	int rotated[dimen][dimen];
	for (int i = 0; i < dimen; i++)
	{
		for (int j = 0; j < dimen; j++)
		{
			rotated[(dimen - 1) - j][i] = arr[i][j];
		}
	}
	printMatrix(rotated);
}
rotatingNxN::rotatingNxN()
{
}


rotatingNxN::~rotatingNxN()
{
}
