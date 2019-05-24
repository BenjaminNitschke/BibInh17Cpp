// FibonacciZahlen.cpp : Definiert den Einstiegspunkt für die 
#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

void fib(int amount)
{
	double *fibos = new double[amount];
	fibos[0] = 1;
	fibos[1] = 1;
	for (int i = 2; i < amount; i++)
		fibos[i] = fibos[i - 2] + fibos[i - 1];
	for (int i = 0; i < amount; i++)
		cout << setprecision(70) << fibos[i] << endl;
	delete[] fibos;
}

int main()
{
	cout << "Wie viel Fibonacci-Zahlen möchtest du haben?" << endl;
	int amount = 0;
	cin >> amount;
	cout << endl;
	fib(amount);
	cout << endl;
    return 0;
}
