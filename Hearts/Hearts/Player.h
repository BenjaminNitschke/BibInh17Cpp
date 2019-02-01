#pragma once
#include <vector>
#include "Card.h"

class Player
{
public:
	std::vector<std::shared_ptr<Card>> hand = std::vector<std::shared_ptr<Card>>();
	void SortHand();
	void DrawHand() const;
};
