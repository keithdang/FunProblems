#pragma once

#define columns 5
#define rows 4
class zeroRowColMatrix
{
public:
	void start();
	void printMatrix(int arr[rows][columns]);
	void zeroMatrix(int arr[rows][columns]);
	void zeroMatrix2(int arr[rows][columns]);
	zeroRowColMatrix();
	~zeroRowColMatrix();
};

