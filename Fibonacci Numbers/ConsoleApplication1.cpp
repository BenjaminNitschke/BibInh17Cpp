// ConsoleApplication1.cpp : Definiert den Einstiegspunkt fuer die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int numberOfFibonaccis;
	int f1 = 0;
	int f2 = 1;
	int generatedFibonacci = 0;

	cout << "How many numbers?: ";
	cin >> numberOfFibonaccis;

	cout << "Generated fibonacci numbers: ";

	cout << f1 << " " << f2 << " ";

	for (int i = 1; i <= numberOfFibonaccis; ++i)
	{
		generatedFibonacci = f1 + f2;
		f1 = f2;
		f2 = generatedFibonacci;

		cout << generatedFibonacci << " ";
	}
	return 0;
}

