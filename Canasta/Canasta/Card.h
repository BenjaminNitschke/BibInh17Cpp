#pragma once
#include <memory>
#include "Sprite.h"

class Card
{
private:
	
public:
	int value;
	int id;
	std::string color;
	std::shared_ptr<Sprite> cardGraphic;
	Card(std::string id, std::string color, int value);
	Card(std::shared_ptr<Card> copy);
	~Card() {}
	
};