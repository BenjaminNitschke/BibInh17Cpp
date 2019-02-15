#pragma once
#include <vector>
#include "Card.h"

class Player
{
private:
	void SortCategory();
public:
	std::vector<std::shared_ptr<Card>> hand = std::vector<std::shared_ptr<Card>>();
	std::vector<std::shared_ptr<Card>> selectedCards = std::vector<std::shared_ptr<Card>>();
	Player();
	~Player(){}
	void DisplayHand();
	void ArrangeHand();
	void SortHand();
	void PushCardsIntoHand(std::vector<std::shared_ptr<Card>> category, std::vector<std::shared_ptr<Card>>* hand);
};
	

