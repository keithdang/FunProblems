#include "uniqueCharInString.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;
void uniqueCharInString::start()
{
	std::cout << "Determining if a string has all unique characters\n";
	std::string word = "aabcdefgh";
	usingUnorderedSet(word);
}
void uniqueCharInString::usingMaps(std::string word)
{
	std::map<char, int> letters;
	bool foundDuplicate = true;
	for (int i = 0; i < word.length(); i++)
	{
		if (letters[word[i]] == NULL)
		{
			letters[word[i]] = 1;
		}
		else
		{
			foundDuplicate = false;
		}
	}
	if (foundDuplicate)
	{
		std:cout << word << " are all unique characters";
	}
}
void uniqueCharInString::usingUnorderedSet(std::string word)
{
	std::unordered_set<char> letters;
	bool foundDuplicate = true;
	for (int i = 0; i < word.length(); i++)
	{
		std::unordered_set<char>::const_iterator got=letters.find(word[i]);
		if (got == letters.end())
		{
			letters.insert(word[i]);
		}
		else
		{
			foundDuplicate = false;
		}
	}
	if (foundDuplicate)
	{
		std:cout << word << " are all unique characters";
	}
}
void uniqueCharInString::storingIntoChar(std::string word)
{

}
uniqueCharInString::uniqueCharInString()
{
}


uniqueCharInString::~uniqueCharInString()
{
}
