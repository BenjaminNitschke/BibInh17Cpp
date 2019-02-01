#pragma once
#include <vector>
#include "Card.h"

class Trick
{
public:
	std::vector<Card*> cards;
	Trick();
};
