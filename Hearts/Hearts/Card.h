#pragma once
#include <memory>
#include "Sprite.h"
#include "Utility.h"
#include <functional>

class Trick;
class Player;

class Card
{
public:
	static std::function<void(std::shared_ptr<Card> card, int index)> cardSelected;
	Card(int color, int value);
	int color, value;
	float width, height;
	std::shared_ptr<Sprite> sprite;
	std::string ToString() const
	{
		std::string val = names.at(value);
		std::string col = names.at(color);
		std::string tmp = "Card: " + val + " of " + col;
		return tmp;
	}
};
