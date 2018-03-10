#pragma once
#include <string>
#define dimen 3
class recursiveRobot
{
public:
	void start();
	void printArray(int arr[dimen][dimen]);
	void moveRobot(int x, int y,int& paths, bool rightOrDown,bool& finalPathReached);
	recursiveRobot();
	~recursiveRobot();
};

