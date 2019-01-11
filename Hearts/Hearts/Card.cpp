#include "stdafx.h"
#include "Card.h"
#include "Utility.h"

Card::Card(int color, int value) : color(color), value(value)
{
	sprite = std::make_shared<Sprite>(Utility::abbrev.at(value) + Utility::abbrev.at(color) + ".png" , 0, 0);
}