﻿#pragma once
#include <memory>
#include "Sprite.h"
#include "Utility.h"

class Card
{
public:
	Card(int color, int value);
	int color;
	int value;
	std::shared_ptr<Sprite> sprite;
	std::string ToString() const
	{
		std::string val = Utility::names.at(value);
		std::string col = Utility::names.at(color);
		std::string tmp = ("Card: " + val + " of " + col);
		return tmp;
	}
};
