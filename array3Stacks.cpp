//3.1 Describe how you could use a single array to implement three stacks
#include "array3Stacks.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
#define stackSize 5
#define numStacks 3
using namespace std;
int stackIndex[] = { 0,0,0 };
void array3Stacks::start()
{
	cout << "3 Stacks in 1 array\n";
	int arrSize = stackSize*numStacks;
	int *arr;
	arr = new int[arrSize];
	memset(arr, 0, arrSize * sizeof(arr));
	push(arr, 1, 2);
	push(arr, 1, 8);
	push(arr, 0, 5);
	push(arr, 2, 4);
	push(arr, 0, 3);
	printArr(arr, arrSize);
	cout<<"\npop"<<pop(arr, 1)<<"\n";
	printArr(arr, arrSize);
}
void array3Stacks::push(int arr[], int stackNum, int val)
{
	int index = stackNum*stackSize + stackIndex[stackNum];
	stackIndex[stackNum]++;
	arr[index] = val;
}
int array3Stacks::pop(int arr[], int stackNum)
{
	int index = stackNum*stackSize + stackIndex[stackNum]-1;
	stackIndex[stackNum]--;
	int val = arr[index];
	arr[index] = 0;
	return val;
}
void array3Stacks::printArr(int arr[], int arrSize)
{
	cout << "Printing array\n";
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i]<<",";
	}
}
array3Stacks::array3Stacks()
{
}


array3Stacks::~array3Stacks()
{
}
