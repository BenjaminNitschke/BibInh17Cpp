#pragma once
#include <memory>
#include "Sprite.h"

class Card
{
private:
	
public:
	int value;
	int id;
	bool isHighlightable = true;
	bool isPlaced = false;
	std::string color;
	std::shared_ptr<Sprite> cardGraphic;
	Card(std::string id, std::string color, int value);
	Card(std::shared_ptr<Card> copy);
	~Card() {}
	
};