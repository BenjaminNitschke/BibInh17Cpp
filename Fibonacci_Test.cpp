#include "pch.h"
#include <iostream>
#include <string>

void generateFibonacci(const int amount, int* target);
void fibonacci_recursive(int* target, int amount, const int num1, const int num2, int limit = 0);

int main()
{
	int amount;
	std::cout << "How many numbers would you like to be generated?" << "\n";
	std::cin >> amount;

	auto numbers = new int[amount];

	generateFibonacci(amount, numbers);

	std::cout << "\n" << "Here are your numbers" << "\n";

	for (auto i = 0; i < amount; ++i)
		std::cout << numbers[i] << " ";

	std::cout << "\n";

	delete numbers;

	return 0;
}

void generateFibonacci(const int amount, int* target)
{
	target[0] = 1;
	target[1] = 1;

	for (auto i = 2; i < amount; ++i)
		target[i] = target[i - 1] + target[i - 2];
}