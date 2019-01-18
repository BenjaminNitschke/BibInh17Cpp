#include "stdafx.h"
#include <iostream>
#include <string>
#include <random>
#include <array>

using namespace std;

int randInRange(int min, int max)
{
	return min + (_Random_device() % (max - min + 1));
}

string randomString(int length)
{
	string tmp(length, ' ');
	for (int i = 0; i < length; i++)
	{
		int r = randInRange(64, 90);
		if (r == 64)
		{
			tmp[i] = 32;
		}
		else
		{
			tmp[i] = r;
		}
	}
	return tmp;
}

int calGoal(string goal, string input)
{
	int sum = 0;
	for (int i = 0; i < goal.length(); i++)
	{
		if (goal[i] == input[i])
		{
			sum++;
		}
	}
	return sum;
}

string nextGeneration(string current, int amountOfChildren, int mutationRate)
{
	vector<string> children(amountOfChildren, current);

	for (int i = 0; i < amountOfChildren; i++)
	{
		for (int j = 0; j < children[i].length(); j++)
		{
			int r = randInRange(0, 100);
			if (r <= mutationRate)
			{
				children[i][j] = randomString(1)[0];
			}
		}
	}

	int best = 0;
	int bestIndex = 0;
	for (int i = 0; i < amountOfChildren; i++)
	{
		int tmp = calGoal("METHINKS IT IS LIKE A WEASEL", children[i]);
		if (tmp > best)
		{
			best = tmp;
			bestIndex = i;
		}
	}

	return children[bestIndex];
}

int main()
{
	string goal = "METHINKS IT IS LIKE A WEASEL";

	string seed = randomString(28);

	string tmp = seed;

	int mutationChance = 5;
	int amountOfChildren = 100;

	int score = 0;
	int generation = 0;

	while (score < goal.length())
	{
		tmp = nextGeneration(tmp, amountOfChildren, mutationChance);
		generation++;
		score = calGoal(goal, tmp);
		cout << generation << ": " << tmp << " -- " << score << endl;
	}

    return 0;
}