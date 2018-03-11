//Implement the “paint fill” function that one might see on many image editing programs.
//That is, given a screen(represented by a 2 dimensional array of Colors), a point, and a new color, 
//fill in the surrounding area until you hit a border of that color.’
#include "paintFill.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

void paintFill::start()
{
	cout << "Paint Filling"<<endl;
	int arr[dimen][dimen] = { {1,0,1,1},{1,1,0,1},{ 0,1,0,0 } ,{ 1,0,1,1 } };
	printArray(arr);
	std::tuple<int, int> point = { 1,1 };
	fill(0, point, arr);
	cout << endl;
	printArray(arr);
}
void paintFill::fill(int color, std::tuple<int, int> point, int arr[dimen][dimen])
{
	if (arr[std::get<0>(point)][std::get<1>(point)] != color)
	{
		arr[std::get<0>(point)][std::get<1>(point)] = color;
	}
	//up
	if (std::get<0>(point) > 0 && (arr[std::get<0>(point)-1][std::get<1>(point)] != color))
	{
		fill(color, { std::get<0>(point) - 1, std::get<1>(point) }, arr);
	}
	//left
	if (std::get<1>(point) > 0 && (arr[std::get<0>(point)][std::get<1>(point)-1] != color))
	{
		fill(color, { std::get<0>(point) , std::get<1>(point)-1 }, arr);
	}
	//down
	if (std::get<0>(point) < (dimen-1) && (arr[std::get<0>(point) + 1][std::get<1>(point)] != color))
	{
		fill(color, { std::get<0>(point) + 1, std::get<1>(point) }, arr);
	}
	//right
	if (std::get<1>(point) < (dimen-1) && (arr[std::get<0>(point)][std::get<1>(point)+1] != color))
	{
		fill(color, { std::get<0>(point) , std::get<1>(point) + 1 }, arr);
	}
}
void paintFill::printArray(int arr[dimen][dimen])
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
paintFill::paintFill()
{
}


paintFill::~paintFill()
{
}
