//8.2
//Imagine a robot sitting on the upper left hand corner of an NxN grid.
//The robot can only move in two directions : right and down.How many possible paths are there for the robot ?
#include "recursiveRobot.h"
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
void recursiveRobot::start()
{
	std::cout << "Moving robot across "<<dimen<<"x"<<dimen<<" Matrix"<<endl;
	int arr[dimen][dimen];
	int numPaths = 0;
	bool bFinalPathReached=false;
	moveRobot(0, 0, numPaths, true,bFinalPathReached);
	moveRobot(0, 0, numPaths, false, bFinalPathReached);
	cout << "Paths:" << numPaths << endl;
}
void recursiveRobot::printArray(int arr[dimen][dimen])
{
	for (int i = 0; i < dimen; i++)
	{
		for (int j = 0; j < dimen; j++)
		{
			cout << i << "," << j << endl;
		}
	}
}
void recursiveRobot::moveRobot(int x, int y, int& paths, bool goRight, bool& finalPathReached)
{
	if (x == (dimen - 1) && y == (dimen - 1))
	{
		//cout << "Final path reached" << endl;
		finalPathReached = true;
	}
	if (goRight)
	{
		if (x < (dimen-1))
		{
			//cout << "Robot moves right"<<endl;
			moveRobot(x + 1, y,paths, true,finalPathReached);
			moveRobot(x + 1, y,paths, false,finalPathReached);
			if (finalPathReached)
			{
				finalPathReached = false;
				paths++;
			}
		}
		else
		{
			//cout << "Edge reached"<<endl;
		}
	}
	else
	{
		if (y < (dimen - 1))
		{
			//cout << "Robot moves down" << endl;
			moveRobot(x, y+1,paths, true, finalPathReached);
			moveRobot(x, y+1,paths, false, finalPathReached);
			if (finalPathReached)
			{
				finalPathReached = false;
				paths++;
			}
		}
		else
		{
			//cout << "Edge reached" << endl;
		}
	}
}
recursiveRobot::recursiveRobot()
{
}


recursiveRobot::~recursiveRobot()
{
}
