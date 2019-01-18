#include "pch.h"
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

string random;

char CreateRandomChar()
{
	char c;
	int r = rand() % 26 + 64;
	if (r == 64)
		c = ' ';
	else
		c = (char)r;

	return c;
}
string CreateRandomString()
{
	string ret;
	for (int i = 0; i < 28; i++)
	{
		ret += CreateRandomChar();
	}
	return ret;
}

int CalcFitness(string s)
{
	string solution = "METHINKS IT IS LIKE A WEASEL";
	int fitness = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == solution[i])
		{
			fitness++;
		}
	}
	return fitness;
}

string CreateChild(string root)
{
	string ret = "";
	
	for (int i = 0; i < root.length(); i++)
	{
		int r = rand() % 100;
		//cout << r << endl;
		if (r < 10)
			ret += CreateRandomChar();
		else
			ret += root[i];
	}	

	return ret;
}

int main()
{
	srand(time(NULL));
	string root = CreateRandomString();


	string nextRoot;
	string genRoot = root;
	int counter = 0;

	while (nextRoot != "METHINKS IT IS LIKE A WEASEL")
	{
		for (int i = 0; i < 1000; i++)
		{
			string child = CreateChild(genRoot);			

			if (CalcFitness(genRoot) < CalcFitness(child))
				nextRoot = child;

		}
		genRoot = nextRoot;

		counter++;
		cout << nextRoot.c_str() << "     " << CalcFitness(nextRoot) << " " << counter << endl;
	}
}