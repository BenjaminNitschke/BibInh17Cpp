#include "pch.h"
#include <iostream>

int main()
{
	std::cout << "Wie viele Zahlen wollen sie ausgegeben bekommen?\n";
	unsigned int input;
	std::cin >> input;
	int length = input;
	int array[200];
	array[0] = 1;
	array[1] = 1;
	std::cout << "Fibonacci Zahlen:\n";
	std::cout << "-----------------\n";
	std::cout << "1. Zahl: " << array[0] << "\n";
	std::cout << "2. Zahl: " << array[1] << "\n";

	for (int i = 2; i < input; i++)
	{
		array[i] = array[i - 1] + array[i - 2];
		std::cout << i+1 << ". Zahl: " << array[i] << "\n";
	}

	std::cout << "-----------------\n";

	/*const int length = 20;
	int array[length];
	array[0] = 1;
	array[1] = 1;
	std::cout << "Fibonacci Zahlen:\n";
	std::cout << "-----------------\n";
	std::cout << "1. Zahl: " << array[0] << "\n";
	std::cout << "2. Zahl: " << array[1] << "\n";

	for (int i = 2; i < length; i++)
	{
		array[i] = array[i - 1] + array[i - 2];
		std::cout << i+1 << ". Zahl: " << array[i] << "\n";
	}

	std::cout << "-----------------\n";*/
}
