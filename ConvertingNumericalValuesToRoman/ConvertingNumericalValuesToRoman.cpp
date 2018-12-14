// ConvertingNumericalValuesToRoman.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.

#include "stdafx.h"
#include <iostream>
#include <map>
#include <math.h>
#include <sstream>

using namespace std;

const int length = 10;
int t[length];

map<int, char> numericToRoman = { { 1, 'I' }, { 5, 'V' }, { 10, 'X' }, { 50, 'L' }, { 100, 'C' }, { 500, 'D' }, { 1000, 'M' } };

int main()
{
	cout << "Converting numerical values to roman" << endl;
	cout << "Enter your number:" << endl;
	int number;
	cin >> number;

	stringstream output;

	if (number >= 1000)
	{
		int m = floor(number / 1000);
		number -= (1000 * m);
		for (int i = 0; i < m; i++)
			output << numericToRoman.find(1000)->second;
	}

	if (number >= 900)
	{
		number -= 900;
		output << numericToRoman.find(100)->second << numericToRoman.find(1000)->second;
	}

	if (number >= 500)
	{
		number -= 500;
		output << numericToRoman.find(500)->second;
	}

	if (number >= 400)
	{
		number -= 400;
		output << numericToRoman.find(100)->second << numericToRoman.find(500)->second;
	}

	if (number >= 100)
	{
		int m = floor(number / 100);
		number -= (100 * m);
		for (int i = 0; i < m; i++)
			output << numericToRoman.find(100)->second;
	}

	if (number >= 90)
	{
		number -= 90;
		output << numericToRoman.find(10)->second << numericToRoman.find(100)->second;
	}

	if (number >= 50)
	{
		number -= 50;
		output << numericToRoman.find(50)->second;
	}

	if (number >= 40)
	{
		number -= 40;
		output << numericToRoman.find(10)->second << numericToRoman.find(50)->second;
	}

	if (number >= 10)
	{
		int m = floor(number / 10);
		number -= (10 * m);
		for (int i = 0; i < m; i++)
			output << numericToRoman.find(10)->second;
	}

	if (number >= 9)
	{
		number -= 9;
		output << numericToRoman.find(1)->second << numericToRoman.find(10)->second;
	}

	if (number >= 5)
	{
		number -= 5;
		output << numericToRoman.find(5)->second;
	}

	if (number >= 4)
	{
		number -= 4;
		output << numericToRoman.find(1)->second << numericToRoman.find(5)->second;
	}

	if (number >= 1)
	{
		int m = floor(number / 1);
		number -= (1 * m);
		for (int i = 0; i < m; i++)
			output << numericToRoman.find(1)->second;
	}
	
	
	cout << output.str();
	cout << endl;

	return 0;
}


// cout << numericToRoman.find(1)->second;
// stringstream ss;
//
// ss << m;
//
// string s = ss.str();
// cout << s;