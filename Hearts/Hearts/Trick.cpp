#include "stdafx.h"
#include "Trick.h"

Trick::Trick()
{
	Card::playFunction = [this](Card* card)
	{
		card->sprite->Move(640, 360);
		cards.push_back(card);
		delete card;
	};
}
