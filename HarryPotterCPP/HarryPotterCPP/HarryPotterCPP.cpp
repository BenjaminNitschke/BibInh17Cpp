#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

float prices[] = { 8, 15.2, 21.6, 25.6, 28 };
std::vector<int> books;
std::vector<int> amounts;
float total;

void get_amounts()
{
	for (auto i = 0; i < books.size(); i++)
		amounts[books[i] - 1]++;
}

void step()
{
	auto minAmount = amounts[0];
	if (minAmount != 0)
	{
		total += minAmount * prices[amounts.size() - 1];
		for (auto i = 0; i < amounts.size(); i++)
			amounts[i] -= minAmount;
	}
	amounts.erase(amounts.begin());
}

float calc(std::vector<int> b)
{
	total = 0;
	amounts = { 0, 0, 0, 0, 0 };
	books = b;
	get_amounts();
	std::sort(amounts.begin(), amounts.end());
	for (auto i = 0; i < 5; i++)
		step();
	return total;
}

TEST_CASE("Test", "T")
{
	std::vector<int> test1 = { };
	std::vector<int> test2 = { 1 };
	std::vector<int> test3 = { 1, 1 };
	std::vector<int> test4 = { 1, 2 };
	std::vector<int> test5 = { 1, 2, 3 };
	std::vector<int> test6 = { 3, 2, 1, 4, 5 };
	std::vector<int> test7 = { 2, 2, 1, 4, 4 };
	std::vector<int> test8 = { 1, 1, 1, 1, 2, 2, 3, 3, 4, 5, 4 };
	std::vector<int> test9 = { 1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5 };
	REQUIRE(calc(test1) == 0);
	REQUIRE(calc(test2) == 8);
	REQUIRE(calc(test3) == 16);
	REQUIRE(calc(test4) == 15.2f);
	REQUIRE(calc(test5) == 21.6f);
	REQUIRE(calc(test6) == 28);
	REQUIRE(calc(test7) == 36.8f);
	REQUIRE(calc(test8) == 69.6f);
	REQUIRE(calc(test9) == 112);
}