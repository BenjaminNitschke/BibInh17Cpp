#include "stdafx.h"
#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <random>
#include <ctime>

Deck::Deck()
{
	for (auto i = hearts; i <= diamonds; ++i)
		for (auto j = seven; j <= ace; ++j)
			deck.push_back(std::make_shared<Card>(i, j));
}

void Deck::Shuffle()
{
	std::shuffle(deck.begin(), deck.end(), std::default_random_engine((unsigned int)time(nullptr)));
}

void Deck::PrintDeck()
{
	for (auto card : deck)
		std::cout << card->ToString().c_str() << "\n";
}

std::shared_ptr<Card> Deck::DrawTop()
{
	auto tmp = deck.back();
	deck.erase(deck.end() - 1);
	std::cout << "Deck has " << deck.size() << " Cards left in it." << std::endl;
	return tmp;
}
