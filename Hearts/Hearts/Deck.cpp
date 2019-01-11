#include "stdafx.h"
#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <random>

Deck::Deck()
{
	for (auto i = 100; i < 104; ++i)
		for (auto j = 0; j < 13; ++j)
			deck.push_back(std::make_shared<Card>(i, j));
}

void Deck::Shuffle()
{
	std::shuffle(deck.begin(), deck.end(), std::default_random_engine(std::time(nullptr)));
}

void Deck::PrintDeck()
{
	for (auto card : deck)
		std::cout << card->ToString().c_str() << "\n";
}
