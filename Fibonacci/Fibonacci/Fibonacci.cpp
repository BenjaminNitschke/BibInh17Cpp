#include "pch.h"
#include <iostream>

void show_numbers(const int n)
{
	int last = 1;
	int current = 1;
	int next;

	if (n == 1)
		std::cout << "\nThe first number of the Fibonacci Series:\n";
	else
		std::cout << "\nThe first "<< n << " numbers of the Fibonacci Series:\n";

	for (auto i = 1; i <= n; ++i)
	{
		if (i == 1)
		{
			std::cout << last;
			continue;
		}
		if (i == 2)
		{
			std::cout << " " << current;
			continue;
		}

		next = last + current;
		last = current;
		current = next;
		std::cout << " " << next;
	}

	std::cout << std::endl;
}

int main()
{
	int n;
	std::cout << "How many Fibonacci Numbers to display?\n";
	std::cin >> n;
	show_numbers(n);

	return 0;
}
