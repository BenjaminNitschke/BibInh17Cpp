// Fibonacci-Test.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n, n1 = 0, n2 = 1, nNext = 0;

	cout << "Gib die Anzahl Nummern ein: ";
	cin >> n;

	cout << "Zahlenfolge: ";

	for (int i = 1; i <= n; i++)
	{
		if (i == 1) 
		{
			cout << " " << n1;
			continue;
		}

		if (i == 2)
		{
			cout << n2 << " ";
			continue;
		}

		nNext = n1 + n2;
		n1 = n2;
		n2 = nNext;

		cout << nNext << " ";
	}
	//return 0;
};