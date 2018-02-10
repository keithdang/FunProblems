#include "removeDuplicates.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_set>

void removeDuplicates::start()
{
	std::string word = "aababcdeecdfgag";
	usingForLoops(word);
	usingForLoops("aaaaa");
	usingForLoops("aaaabbb");
	usingForLoops("");
}
void removeDuplicates::usingForLoops(std::string word)
{
	std::cout << "Removing Duplicates in string: " << word << "\n";
	char ch;
	for (int i = 0; i < word.length(); i++)
	{
		ch = word[i];
		for (int j = i+1; j < word.length(); j++)
		{
			if (ch == word[j])
			{
				word = word.substr(0, j) + word.substr(j + 1);
				j--;
			}
		}
	}
	std::cout << word;
}
removeDuplicates::removeDuplicates()
{
}


removeDuplicates::~removeDuplicates()
{
}
