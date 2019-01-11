#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Please enter a number to convert to a Roman Numeral: \n";
		int number;
		cin >> number;
		string result = "";
		// Algorithm
		//   Solution 1: if/else mess
		//   Solution 2: recursion
		//   Solition 3: array/dictionary
		vector<pair<string, int>> symbols = {
			{"M",1000},
			{"CM",900},
			{"D",500},
			{"CD",400},
			{"C",100},
			{"XC",90},
			{"L",50},
			{"XL",40},
			{"X",10},
			{"IX",9},
			{"V",5},
			{"IV",4},
			{"I",1}
		};
		for (auto pair : symbols)
			while (number >= pair.second) {
				result += pair.first;
				number -= pair.second;
			}

		// loop as long as we have a positive number
		//   go through all symbols (M, D, C, L, X, V, I)
		//     if number >= symbol value, add symbol, reduce number

		cout << "Result: "+result;
}