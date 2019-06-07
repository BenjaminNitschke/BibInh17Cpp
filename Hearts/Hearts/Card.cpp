﻿#include "stdafx.h"
#include "Card.h"
#include "Utility.h"

std::function<void(std::shared_ptr<Card> card, int index)> Card::cardSelected;

Card::Card(int color, int value) : color(color), value(value)
{
	sprite = std::make_shared<Sprite>("./" + abbrev.at(value) + abbrev.at(color) + ".png" , 0, 0, scaling);
	width = sprite->texture->width * scaling;
	height = sprite->texture->height * scaling;
}