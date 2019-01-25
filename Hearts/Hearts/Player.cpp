#include "stdafx.h"
#include "Player.h"
#include <algorithm>

void Player::SortHand()
{
	std::vector<std::vector<std::shared_ptr<Card>>> tmp = std::vector<std::vector<std::shared_ptr<Card>>>(4);

	for (std::shared_ptr<Card> c : hand)
	{
		if (c->color == clubs)
			tmp[0].push_back(c);
		else if (c->color == hearts)
			tmp[1].push_back(c);
		else if (c->color == diamonds)
			tmp[2].push_back(c);
		else if (c->color == spades)
			tmp[3].push_back(c);
	}

	hand.clear();

	for(auto v : tmp)
	{
		std::sort(v.begin(), v.end(), [](std::shared_ptr<Card> a, std::shared_ptr<Card> b) {return a->value < b->value; });
		for (auto c : v)
			hand.push_back(c);
	}
}
