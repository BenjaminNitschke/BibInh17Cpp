#include "pch.h"
#include <iostream>


int numbers[100];

void Calculate(int length)
{
	std::cout << numbers[0] << std::endl;

	for (int i = 1; i < length; i++)
	{
		numbers[i] = numbers[i - 2] + numbers[i - 1];
		std::cout << numbers[i] << std::endl;

		if (i == length-1)
		{
			std::cout << "Fertig!" << std::endl;
		}
	}
}

int main()
{
	std::cout << "Wie oft soll die Funktion ausgefuehrt werden?" << std::endl;
	unsigned int input;
	std::cin >> input;
	std::cout << "Ok!" << std::endl;

	numbers[0] = 1;
	numbers[1] = 1;

	Calculate(input);
}




