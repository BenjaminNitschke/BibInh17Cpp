#include "stdafx.h"
#include "Player.h"
#include "Extension.h"
#include <iostream>
#include <algorithm>

Player::Player()
{

}

void Player::DisplayHand()
{
	for (int i = 0; i < hand.size(); i++)
	{
		hand[i]->cardGraphic->Draw();		
	}
}

void Player::ArrangeHand()
{
	if (hand.size() == 0) return;

	float cardWidth = hand[0]->cardGraphic->GetWidth() / 16;
	float width = hand.size() * cardWidth;
	float x = 1280 - ((1280 - width) / 2);
	for (int i = 0; i < hand.size(); i++)
	{
		x -= cardWidth;
		float y = 600;
		hand[i]->cardGraphic->x = x;
		hand[i]->cardGraphic->y = y;
	}
}

void Player::SortHand()
{
	std::sort(hand.begin(), hand.end(), [](std::shared_ptr<Card> card1, std::shared_ptr<Card> card2) {return card1->id > card2->id; });

}