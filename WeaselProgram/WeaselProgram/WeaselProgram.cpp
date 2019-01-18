#include "pch.h"
#include <iostream>
#include <ctime>
#include <vector>

std::string target = "METHINKS IT IS LIKE A WEASEL";

char GetChar();
int CalculateFitness(std::string str);
std::vector<std::string> GetChildren(std::string seed, int childCount, int probability);

int probability = 10;
int childCount = 100;

int main()
{
	std::srand(time(nullptr));

	std::string seed;

	for (auto i = 0; i < 28; ++i)
		seed += GetChar();

	auto notReached = true;

	int iteration = 0;

	while (notReached)
	{
		
		std::vector<std::string> children = GetChildren(seed, 1000, 10);
		std::string highest_string;
		auto lowest_fit = 0;

		for(auto c : children)
		{
			int current_fit = CalculateFitness(c);
			if(current_fit > lowest_fit)
			{
				lowest_fit = current_fit;
				highest_string = c;
			}
			if (highest_string == target)
			{
				notReached = false;
				break;
			}
		}
		seed = highest_string;
		printf("%04d    %s\n", iteration, seed.c_str());
		++iteration;
	}
}


char GetChar()
{
	const auto tmp = std::floor(rand() % 27 + 64);
	if (tmp == 64)
		return 32;
	return tmp;
}

int CalculateFitness(std::string str)
{ 
	auto fitness = 0;
	for (auto i = 0; i < 28; ++i)
	{
		if (str[i] == target[i])
			++fitness;
	}
		
	return fitness;
}

std::vector<std::string> GetChildren(std::string seed, int childCount, int probability)
{
	std::vector<std::string> children;

	for (int i = 0; i < childCount; ++i)
	{
		std::string child = std::string(seed);
		for (auto j = 0; j < 28; ++j)
		{
			if (rand() % 100 < probability)
				child[j] = GetChar();
		}
		children.push_back(child);
		//std::cout << child.c_str() << "\n";
	}
	return children;
}