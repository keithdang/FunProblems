#include "rotatingSubstring.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
void rotatingSubstring::start()
{
	cout << "Rotating substring\n";
	string word1 = "waterbottle";
	string word2 = "erbottlewat";
	method2(word1, word2);
}
void rotatingSubstring::method1(string word1, string word2)
{
	string temp;
	for (int i = 0; i < word1.length(); i++)
	{
		if (word1[0] == word2[i])
		{
			temp = word2.substr(i) + word2.substr(0, i);
			if (word1.compare(temp) == 0)
			{
				std::cout << "yup";
			}
		}
	}
}
void rotatingSubstring::method2(string word1, string word2)
{
	string temp = word1 + word1;
	cout << temp << "\n";
	if (temp.find(word2) !=std::string::npos)
	{
		cout << "yup";
	}
}
rotatingSubstring::rotatingSubstring()
{
}


rotatingSubstring::~rotatingSubstring()
{
}
