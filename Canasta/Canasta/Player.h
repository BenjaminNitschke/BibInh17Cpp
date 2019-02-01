#pragma once
#include <vector>
#include "Card.h"

class Player
{
private:

public:
	std::vector<std::shared_ptr<Card>> hand = std::vector<std::shared_ptr<Card>>();
	Player();
	~Player(){}
	void GetStartHand();
	void DisplayHand();
};
	

