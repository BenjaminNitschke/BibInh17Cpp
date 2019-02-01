#pragma once
#include <vector>
#include "Card.h"

class Deck
{
public:
	std::vector<std::shared_ptr<Card>> deck;
	Deck();
	void Shuffle();
	void PrintDeck();
};
