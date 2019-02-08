#include <stdafx.h>
#include <string>
#include "Card.h"
#include <iostream>

Card::Card(std::string id, std::string color, int setValue)
{
	this->cardGraphic = std::make_shared<Sprite>(std::make_shared<Texture>(("./PNG/" + id + color + ".png").c_str()), 640, 360,16);
	Card::id = setValue;
	Card::color = color;
	if (setValue == 2 || setValue == 14)
		value = 20;
	else if (setValue < 8)
		value = 5;
	else if (setValue < 14)
		value = 10;
	else
		value = 50;
	std::cout <<"|" << id << " hat den Value von: " << value << std::endl;
}

Card::Card(std::shared_ptr<Card> copy)
{
	this->value = copy->value;
	this->color = copy->color;
	this->id = copy->id;
	this->cardGraphic = std::make_shared<Sprite>(copy->cardGraphic->GetTexture(), 640, 360, 16);
}