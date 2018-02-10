//3.1 Describe how you could use a single array to implement three stacks
#pragma once

class array3Stacks
{
public:
	void start();
	void push(int arr[], int stack, int val);
	int pop(int arr[], int stack);
	void printArr(int arr[], int arrSize);
	array3Stacks();
	~array3Stacks();
};

