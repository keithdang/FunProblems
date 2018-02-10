#include "anagrams.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
void anagrams::start()
{
	cout << "Anagrams\n";
	string word1 = "tacooo";
	string word2 = "coatoo";
	cout << word1 << " and " << word2 << " are ";
	map<char, int> anaMap1,anaMap2;
	bool checker = false;
	if (word1.length() == word2.length())
	{
		checker = true;
		for (int i = 0; i < word1.length(); i++)
		{
			anaMap1[word1[i]]++;
			anaMap2[word2[i]]++;
		}

		for (std::map<char, int>::iterator it = anaMap1.begin(); it != anaMap1.end(); ++it)
		{
			if (anaMap2[it->first] == NULL || anaMap1[it->first] != anaMap2[it->first])
			{
				checker = false;
				break;
			}
		}
	}
	if (!checker)
	{
		std::cout << "not ";
	}
	std::cout << "anagrams";
}

anagrams::anagrams()
{
}


anagrams::~anagrams()
{
}
