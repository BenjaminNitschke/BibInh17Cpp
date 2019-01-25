// SortingAlgorithms.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <random>
#include <iomanip>

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
		int r = randInRange(65, 90);
		tmp[i] = r;
	}
	return tmp;
}

vector<string> createRandomStrings(int amount, int stringLength)
{
	vector<string> tmp;

	for (int i = 0; i < amount; i++)
	{
		tmp.push_back(randomString(stringLength));
	}

	return tmp;
}

vector<string> bubbleSort(vector<string> strings)
{
	vector<string> tmp = strings;

	for (int j = 0; j < tmp.size(); j++)
	{
		for (int i = 0; i < tmp.size() - j - 1; i++)
		{
			if (tmp[i].compare(tmp[i+ 1]) > 0)
			{
				string s = tmp[i + 1];
				tmp[i + 1] = tmp[i];
				tmp[i] = s;
			}
		}
	}
	return tmp;
}

int main()
{
	vector<string> example = createRandomStrings(100, 6);

	cout << "Not sorted" << endl;
	for (int i = 0; i < example.size(); i++)
	{
		cout << setfill(' ') << setw(2) << i << ": " << example[i] << endl;
	}
	cout << endl;

	vector<string> exampleBubbleSorted = bubbleSort(example);
	cout << "Bubble Sort" << endl;
	for (int i = 0; i < exampleBubbleSorted.size(); i++)
	{
		cout << setfill(' ') << setw(2) << i << ": " << exampleBubbleSorted[i] << endl;
	}
	cout << endl;
	
    return 0;
}