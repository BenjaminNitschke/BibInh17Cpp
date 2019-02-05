#include "stdafx.h"
#include "Player.h"
#include "Utility.h"
#include <algorithm>
#include <iostream>

Player::Player()
{
	Card::playFunction = [=](Card* card) {RepositionHand(); };
}

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

void Player::RepositionHand() const
{
	const auto cardWidth = hand[0]->width / 3;
	const auto cardCount = hand.size();
	const auto init = cardWidth * floor(cardCount / 2) + 640 - (cardCount % 2 == 0 ? cardWidth / 2 : 0);

	for (int i = 0; i < cardCount; i++)
		hand[i]->sprite->MoveTo(init - cardWidth * i, 720);
}

void Player::DrawHand() const
{
	for(auto c : hand)
		c->sprite->Draw();
}

void Player::SelectCard(float mouseX, float mouseY)
{
	for (int i = hand.size() - 1; i >= 0; i--)
	{
		if (mouseX > hand[i]->sprite->x - hand[i]->width / 2 && mouseX < hand[i]->sprite->x + hand[i]->width / 2 &&
			mouseY > hand[i]->sprite->y - hand[i]->height / 2 && mouseY < hand[i]->sprite->y + hand[i]->height / 2)
		{
			std::cout << i << std::endl;
			if (hand[i].get() != selectedCard || selectedCard == nullptr)
			{
				if (selectedCard != nullptr)
				{
					selectedCard->Deselect();
					selectedCard = nullptr;
				}
				hand[i]->Select();
				selectedCard = hand[i].get();
				return;
			}
			if (hand[i].get() == selectedCard)
			{
				selectedCard->Play();
				selectedCard = nullptr;
				hand.erase(hand.begin() + i);
				if(!hand.empty())
					RepositionHand();
				return;
			}
				
		}
		else
		{
			if (selectedCard == nullptr) continue;
			selectedCard->Play();
			hand.erase(hand.begin() + i);
			if(!hand.empty())
				RepositionHand();
			selectedCard = nullptr;
		}
	}
}
