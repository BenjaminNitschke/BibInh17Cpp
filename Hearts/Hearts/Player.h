#pragma once
#include <vector>
#include "Card.h"

class Player
{
private:
	Card* selectedCard = nullptr;
public:
	Player();

	std::vector<std::shared_ptr<Card>> hand = std::vector<std::shared_ptr<Card>>();
	void SortHand();
	void RepositionHand() const;
	void DrawHand() const;
	void SelectCard(float mouseX, float mouseY);
	~Player()
	{
		if(selectedCard != nullptr)
			delete selectedCard;
	}
};
