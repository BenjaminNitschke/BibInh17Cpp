#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

string target = "METHINKS IT IS LIKE A WEASEL";
string chars = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string get_random_string(int length, int min, int max)
{
	string s;

	for (int i = 0; i < length; i++)
	{
		s += chars[rand() % 27];
	}

	return s;
}

int get_fitness(string s)
{
	int fitness = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == target[i])
		{
			fitness++;
		}
	}

	return fitness;
}

string get_best_children(string s, int amount, float diff)
{
	vector<string> children;
	for (int i = 0; i < amount; i++)
	{
		string child = s;
		for (int j = 0; j < s.length(); j++)
		{
			if ((double)rand() / RAND_MAX < diff)
			{
				//if (child[j] == target[j]) continue;
				child[j] = chars[rand() % 27];
			}
		}
		children.push_back(child);
	}

	int index = 0;
	for (int i = 1; i < children.size(); i++)
	{
		if (get_fitness(children[i]) > get_fitness(children[index]))
		{
			index = i;
		}
	}

	return children[index];
}

int main()
{
	srand(time(nullptr));
	string s = get_random_string(28, 65, 90);
	int counter = 0;

	while (true)
	{
		string bestChild = get_best_children(s, 1000, .1);
		cout << get_fitness(bestChild) << " " << bestChild << "\n";
		s = bestChild;

		if (get_fitness(bestChild) == 28)
		{
			cout << "\n" << counter << " iterations\n";
			return 0;
		}
		counter++;
	}
}
