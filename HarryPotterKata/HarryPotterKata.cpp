#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "HarryPotterKata.h"
using namespace std;
const double costPerBook = 8.0;
double discount[] = { 0, 0, 0.05, 0.10, 0.20, 0.30 };
double FindBestPrice(std::vector<int> booksToBuy)
{
	double totalPrice = 0;
	std::vector<int> books = booksToBuy;
	do
	{
		std::vector<int> rest;
		std::vector<int> uniques;
		for (auto book : books)
			if(std::find(uniques.begin(), uniques.end(), book) != uniques.end())
				rest.push_back(book);
			else
				uniques.push_back(book);
		totalPrice += uniques.size() * costPerBook *
			(1-discount[uniques.size()]);
		books = rest;
	} while (books.size() > 0);
	return totalPrice;
}

void BuyBooks(std::vector<int> booksToBuy, double expectedPrice)
{
	cout << "Buying books: ";
  for (auto book : booksToBuy)
		cout << book << ", ";
	auto price = FindBestPrice(booksToBuy);
	cout << "Price=" << price << " Expected Price: " << expectedPrice << endl;
	if (price != expectedPrice)
		throw "ExpectedPrice wasn't price";
}

int main()
{
	BuyBooks({}, 0);
	BuyBooks({ 1 }, 8);
	BuyBooks({ 1, 1 }, 16);
	BuyBooks({ 1, 2 }, 15.2);
	BuyBooks({ 1, 2, 3 }, 21.6);
	BuyBooks({ 3, 2, 1, 4, 5 }, 28);
	BuyBooks({ 2, 2, 1, 4, 4 }, 36.8);
	BuyBooks({ 1, 1, 1, 1, 2, 2, 3, 3, 4, 5, 4 }, 69.6);
	BuyBooks({
		1, 1, 1,
		2, 2,
		3, 3, 3, 3, 3,
		4, 4, 4, 4, 4,
		5, 5, 5 }, 112);
}
