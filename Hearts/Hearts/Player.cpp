#include "stdafx.h"
#include "Player.h"
#include <algorithm>

void Player::SortHand()
{
	std::vector<std::shared_ptr<Card>> club = std::vector<std::shared_ptr<Card>>();
	std::vector<std::shared_ptr<Card>> heart = std::vector<std::shared_ptr<Card>>();
	std::vector<std::shared_ptr<Card>> diamond = std::vector<std::shared_ptr<Card>>();
	std::vector<std::shared_ptr<Card>> spade = std::vector<std::shared_ptr<Card>>();

	for (std::shared_ptr<Card> c : hand)
	{
		if (c->color == clubs)
			club.push_back(c);
		else if (c->color == hearts)
			heart.push_back(c);
		else if (c->color == diamonds)
			diamond.push_back(c);
		else if (c->color == spades)
			spade.push_back(c);
	}

	hand.clear();

	std::sort(club.begin(), club.end(), [](std::shared_ptr<Card> card1, std::shared_ptr<Card> card2) {return card1->value < card2->value; });
	std::sort(heart.begin(), heart.end(), [](std::shared_ptr<Card> card1, std::shared_ptr<Card> card2) {return card1->value < card2->value; });
	std::sort(diamond.begin(), diamond.end(), [](std::shared_ptr<Card> card1, std::shared_ptr<Card> card2) {return card1->value < card2->value; });
	std::sort(spade.begin(), spade.end(), [](std::shared_ptr<Card> card1, std::shared_ptr<Card> card2) {return card1->value < card2->value; });

	hand.reserve(club.size() + heart.size() + diamond.size() + spade.size());

	hand.insert(hand.end(), club.begin(), club.end());
	hand.insert(hand.end(), heart.begin(), heart.end());
	hand.insert(hand.end(), diamond.begin(), diamond.end());
	hand.insert(hand.end(), spade.begin(), spade.end());
}
