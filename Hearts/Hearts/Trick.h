#pragma once
#include <vector>
#include "Card.h"
#include "Player.h"
#include <iostream>

class Trick
{
public:
	std::vector<Card*> cards;
	int color, points, winningValue;
	Player* winner;
	Trick();
	void Draw();
	void Add(Player* player, Card* card)
	{
		std::cout << "Penis" << std::endl;
		if (cards.empty())
		{
			color = card->color;
			winner = player;
		}
		cards.push_back(card);
		if (card->color == hearts)
			points++;
		else if (card->color == spades && card->value == queen)
			points += 13;
		if(card->color == color && card->value > winningValue)
		{
			winner = player;
			winningValue = card->value;
		}
	}
	bool Empty() const
	{
		return cards.empty();
	}
};
