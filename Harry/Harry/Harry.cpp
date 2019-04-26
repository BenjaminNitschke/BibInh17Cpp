#include "pch.h"
#include <iostream>
#include <vector>

float CalculatePrice(std::vector<int> episodes)
{
	int e = 0;
	float discount = 0;
	for (int c = 0; c < episodes.size(); c++)
	{
		e += episodes.at(c) < 1 ? 0 : 1;
	}

	switch (e)
	{
	case 2:
		discount = .8;
		break;
	case 3:
		discount = 2.4;
		break;
	case 4:
		discount = 6.4;
		break;
	case 5:
		discount = 12;
		break;
	default:
		break;
	}
	//std::cout << "Anzahl der Bücher: " << e << " der Discount dafür: " << discount << " der Preis: " << (e * 8) - discount << std::endl;
	return (e * 8) - discount;
}

int main()
{
	std::vector<int> volAmount = { 3,2,5,5,3 };
	float price = 0;

	while ((volAmount.at(0) > 0 || volAmount.at(1) > 0 || volAmount.at(2) > 0 || volAmount.at(3) > 0 || volAmount.at(4) > 0))
	{
		price += CalculatePrice({ volAmount[0], volAmount[1], volAmount[2], volAmount[3], volAmount[4]});
		for (int c = 0; c < volAmount.size(); c++)
		{
			volAmount[c] --;
		}
	}	
	std::cout << "Die Buecher kosten: " << price << std::endl;
}