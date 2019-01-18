#include "stdafx.h"
#include "Card.h"
#include "Utility.h"

Card::Card(int color, int value) : color(color), value(value)
{
	sprite = std::make_shared<Sprite>(abbrev.at(value) + abbrev.at(color) + ".png" , 0, 0);
}