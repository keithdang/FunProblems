#pragma once
#include <vector>
class stringPermutation
{
public:
	void start();
	void permutate(std::string tmp, std::vector<std::string> wordList, std::vector<std::string>& listSet);
	stringPermutation();
	~stringPermutation();
};

