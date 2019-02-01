#include "stdafx.h"
#include "Player.h"
#include "Utility.h"
#include <algorithm>

void Player::SortHand()
{
	std::vector<std::vector<std::shared_ptr<Card>>> tmp = std::vector<std::vector<std::shared_ptr<Card>>>(4);

	for (auto c : hand)
	{
		if (c->color == spades)
			tmp[0].push_back(c);
		else if (c->color == diamonds)
			tmp[1].push_back(c);
		else if (c->color == hearts)
			tmp[2].push_back(c);
		else if (c->color == clubs)
			tmp[3].push_back(c);
	}

	hand.clear();

	for (auto v : tmp)
	{
		std::sort(v.begin(), v.end(), [](std::shared_ptr<Card> a, std::shared_ptr<Card> b) {return a->value < b->value; });
		for (auto c : v)
			hand.push_back(c);
	}
}

void Player::DrawHand() const
{
	const auto cardWidth = hand[0]->sprite->texture->width * scaling;
	const auto cardCount = hand.size();
	const auto init = cardWidth / 3 * floor(cardCount / 2) + 640;

	for (int i = 0; i < cardCount; i++)
	{
		hand[i]->sprite->MoveTo(init - cardWidth / 3 * i, 720);
		hand[i]->sprite->Draw();
	}
}
