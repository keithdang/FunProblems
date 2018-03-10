#include "stringPermutation.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;
void stringPermutation::start()
{
	string word = "abcde";
	cout << "String permutation of "<<word<<endl;
	vector<string> wordList, listSet;
	for (int i = 0; i < word.size(); i++)
	{
		wordList.push_back(word.substr(i, 1));
	}
	permutate("",wordList, listSet);
}
void stringPermutation::permutate(std::string tmp, std::vector<std::string> wordList, std::vector<std::string>& listSet)
{
	for (int i = 0; i < wordList.size(); i++)
	{
		vector<string> wordListTmp=wordList;
		wordListTmp.erase(wordListTmp.begin() + i);
		if (wordList.size() <= 2)
		{
			listSet.push_back(tmp + wordList[0] + wordList[1]);
			cout << listSet.back() << endl;
			listSet.push_back(tmp + wordList[1] + wordList[0]);
			cout << listSet.back() << endl;
			break;
		}
		else
		{
			std::string wordTmp = tmp + wordList[i];
			permutate(wordTmp, wordListTmp, listSet);
		}
	}
}
stringPermutation::stringPermutation()
{
}


stringPermutation::~stringPermutation()
{
}
