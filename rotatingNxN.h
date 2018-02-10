#pragma once
#include <string>
#define dimen 3
class rotatingNxN
{
public:
	void start();
	void printMatrix(int arr[dimen][dimen]);
	void rotateMatrix(int arr[dimen][dimen]);
	void printRotated(int arr[dimen][dimen]);
	rotatingNxN();
	~rotatingNxN();
};

