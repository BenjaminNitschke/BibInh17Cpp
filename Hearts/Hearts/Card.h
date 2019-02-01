#pragma once
#include <memory>
#include "Sprite.h"
#include "Utility.h"
#include <functional>
#include <iostream>

class Card
{
public:
	static std::function<void(Card* card)> playFunction;
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

	void Select() const
	{
		sprite->Move(0, -200);
	}

	void Deselect() const
	{
		sprite->Move(0, 200);
	}

	void Play()
	{
		std::cout << "Card played" << std::endl;
		sprite->MoveTo(640, 360);
		playFunction(this);
	}
};
