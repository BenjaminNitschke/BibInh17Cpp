

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int zahl;
	int lastNumber = 0;
	int newNumber = 1;
	int transverNumber;
	cout << "Fibonacci" << endl;
	cout << "Anzahl?" <<endl;
	cin >> zahl;	
	for (int i = 0; i < zahl; i++)
	{
		cout << newNumber << endl;	
		transverNumber = newNumber;
		newNumber += lastNumber;
		lastNumber = transverNumber;
	}	
	cin >> zahl;
    return 0;
}


