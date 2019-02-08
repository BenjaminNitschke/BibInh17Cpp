#pragma once
#include <vector>
#include "Card.h"

class Player
{
private:
	float handX, handY;
	std::shared_ptr<Sprite> backSprite;
public:
	Card* selectedCard = nullptr;
	Player() = default;
	Player(float handX, float handY, std::shared_ptr<Sprite> backSprite);

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
