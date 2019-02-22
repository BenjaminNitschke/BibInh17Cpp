#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

enum BookType
{
	BOOK1,
	BOOK2,
	BOOK3,
	BOOK4,
	BOOK5
};

int amountOfBooks = 5;

vector<BookType> booksAvailable(vector<int> bookAmout)
{
	vector<BookType> available = {};
	for (int i = 0; i < bookAmout.size(); i++)
	{
		if (bookAmout[i] > 0) available.push_back((BookType)i);
	}
	return available;
}

float calculatePrize(vector<BookType> books)
{
	vector<int> bookAmount = {0, 0 ,0 ,0 ,0};
	vector<float> priceFor = { 8.0f, 15.20f, 21.60f, 25.60f, 28.0f };
	float price = 0.0f;
	for (int i = 0; i < books.size(); i++)
	{
		for (int j = 0; j < amountOfBooks; j++)
		{
			if (books[i] == (BookType)j)
			{
				bookAmount[j]++;
				break;
			}
		}
	}
	for (int i = 0; i < books.size(); i++)
	{
		vector<BookType> available = booksAvailable(bookAmount);
		if (available.size() == 0) break;
		price += priceFor[available.size()-1];
		for (int j = 0; j < available.size(); j++)
		{
			bookAmount[available[j]]--;
		}
	}
	return price;
}

int main()
{
	vector<BookType> books = {BOOK1, BOOK1, BOOK1, BOOK1, BOOK2, BOOK2, BOOK3, BOOK3, BOOK4, BOOK5, BOOK4 };
	cout << calculatePrize(books) << endl;

	books = { BOOK2, BOOK2, BOOK1, BOOK4, BOOK4 };
	cout << calculatePrize(books) << endl;

    return 0;
}