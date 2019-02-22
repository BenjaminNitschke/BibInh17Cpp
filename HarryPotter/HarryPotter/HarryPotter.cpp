#include "pch.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

float calcualte_price(int shoppingCart[], int amount)
{
	std::cout << amount << std::endl;
	std::vector<std::pair<int, int>> amounts = std::vector<std::pair<int, int>>();
	float sum = 0;

	for (int i = 1; i <= 5; i++)
	{
		amounts.push_back(std::pair<int, int>(i, 0));
	}

	for (int i = 0; i < amount; i++)
	{
		for (int p = 0; p < amounts.size(); p++)
		{
			if (amounts[p].first == shoppingCart[i])
				amounts[p].second++;
		}
	}

	std::sort(amounts.begin(), amounts.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) {return p1.second < p2.second;});

	sum += amounts[0].second * 28.0f;
	for (int i = 1; i < amounts.size(); i++)
	{
		amounts[i].second -= amounts[0].second;
	}
	sum += amounts[1].second * 25.6f;
	for (int i = 2; i < amounts.size(); i++)
	{
		amounts[i].second -= amounts[1].second;
	}
	sum += amounts[2].second * 21.6f;
	for (int i = 3; i < amounts.size(); i++)
	{
		amounts[i].second -= amounts[2].second;
	}
	sum += amounts[3].second * 15.2f;
	for (int i = 4; i < amounts.size(); i++)
	{
		amounts[i].second -= amounts[3].second;
	}
	sum += amounts[4].second * 8.0f;

	return sum;
}


TEST_CASE("Harry Potter Book Store", "[HP]")
{
	int none[1] = {};
	REQUIRE(calcualte_price({}, 0) == 0.0f);
	int one[] = { 1 };
	REQUIRE(calcualte_price(one, 1) == 8.0f);
	int two[] = { 1,2 };
	REQUIRE(calcualte_price(two, 2) == 15.2f);
	int three[] = { 1,2,3 };
	REQUIRE(calcualte_price(three, 3) == 21.6f);
	int all[] = { 1,2,3,4,5 };
	REQUIRE(calcualte_price(all, 5) == 28.0f);
	int random[] = {1,1,1,1,2,2,3,3,4,5,4};
	REQUIRE(calcualte_price(random, 11) == 69.6f);
}