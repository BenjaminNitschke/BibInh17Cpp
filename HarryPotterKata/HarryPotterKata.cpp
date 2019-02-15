// HarryPotterKata.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;


enum BookType
{
	BOOK1,
	BOOK2,
	BOOK3
};


float CalculatePrize(vector<BookType> books)
{
	int book1Amount = 0;
	int book2Amount = 0;
	int book3Amount = 0;	
	
	float prize = 0;

	for (int i = 0; i < books.size(); i++)
	{
		if (books[i] == BOOK1)
			book1Amount++;
		else if (books[i] == BOOK2)
			book2Amount++;
		else if (books[i] == BOOK3)
			book3Amount++;
	}

	int book1 = book1Amount;
	int book2 = book2Amount;
	int book3 = book3Amount;

	for (int i = 0; i < book1Amount; i++)
	{
		if (book2 > 0 && book3 > 0 && book1 > 0)
		{
			book1--;
			book2--;
			book3--;
			prize += 21.60f;
		}
		else if (book2 > 0 && book3 == 0 && book1 > 0)
		{
			book1--;
			book2--;
			prize += 15.20f;
		}
		else if (book2 == 0 && book3 > 0 && book1 > 0)
		{
			book1--;
			book3--;
			prize += 15.20f;
		}
		else if (book2 == 0 && book3 == 0 && book1 > 0)
		{
			book1--;
			prize += 8.0f;
		}
	}

	for (int i = 0; i < book2Amount; i++)
	{
		if (book1 > 0 && book3 > 0 && book2 > 0)
		{
			book1--;
			book2--;
			book3--;
			prize += 21.60f;
		}
		else if (book1 > 0 && book3 == 0 && book2 > 0)
		{
			book1--;
			book2--;
			prize += 15.20f;
		}
		else if (book1 == 0 && book3 > 0 && book2 > 0)
		{
			book2--;
			book3--;
			prize += 15.20f;
		}
		else if (book1 == 0 && book3 == 0 && book2 > 0)
		{
			book2--;
			prize += 8.0f;
		}
	}

	for (int i = 0; i < book3Amount; i++)
	{
		if (book1 > 0 && book2 > 0 && book3 > 0)
		{
			book1--;
			book2--;
			book3--;
			prize += 21.60f;
		}
		else if (book1 > 0 && book2 == 0 && book3 > 0)
		{
			book1--;
			book3--;
			prize += 15.20f;
		}
		else if (book1 == 0 && book2 > 0 && book3 > 0)
		{
			book2--;
			book3--;
			prize += 15.20f;
		}
		else if (book1 == 0 && book2 == 0 && book3 > 0)
		{
			book3--;
			prize += 8.0f;
		}
	}

	return prize;
}

int main()
{
	float prize = CalculatePrize(vector<BookType>({ BOOK1, BOOK1, BOOK2, BOOK3, BOOK3, BOOK3 }));
	cout << prize << endl;
    return 0;
}

