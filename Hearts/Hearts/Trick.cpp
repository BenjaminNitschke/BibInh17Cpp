#include "stdafx.h"
#include "Trick.h"

Trick::Trick()
{

}

void Trick::Draw()
{
	for (auto card : cards)
		card->sprite->Draw();
}
