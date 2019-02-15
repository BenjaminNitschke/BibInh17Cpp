#include "stdafx.h"
#include "Player.h"
#include "Utility.h"
#include <algorithm>


Player::Player(float handX, float handY, std::shared_ptr<Sprite> backSprite) : handX(handX), handY(handY), backSprite(backSprite)
{
	
}

void Player::SortHand()
{
	std::vector<std::vector<std::shared_ptr<Card>>> tmp = std::vector<std::vector<std::shared_ptr<Card>>>(4);

	for (auto& c : hand)
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
		for (auto& c : v)
			hand.push_back(c);
	}
}

void Player::RepositionHand() const
{
	const auto cardWidth = hand[0]->width / 3;
	const auto cardCount = hand.size();
	const auto init = cardWidth * floor(cardCount / 2) + handX - (cardCount % 2 == 0 ? cardWidth / 2 : 0);

	for (int i = 0; i < cardCount; i++)
		hand[i]->sprite->MoveTo(init - cardWidth * i, handY);
}

void Player::DrawHand() const
{
	for (auto c : hand)
	{
		if (handY == 720)
			c->sprite->Draw();
		else
		{
			backSprite->MoveTo(c->sprite->x, c->sprite->y);
			backSprite->Draw();
		}
	}
}

void Player::SelectCard(float mouseX, float mouseY)
{
	for (int i = 0; i < hand.size(); i++)
	{
		if (mouseX > hand[i]->sprite->x - hand[i]->width / 2 && mouseX < hand[i]->sprite->x + hand[i]->width / 2 &&
			mouseY > hand[i]->sprite->y - hand[i]->height / 2 && mouseY < hand[i]->sprite->y + hand[i]->height / 2)
		{
			Card::cardSelected(hand[i], i);
			return;
		}
	}
}
