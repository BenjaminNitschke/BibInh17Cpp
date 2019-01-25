#include "stdafx.h"
#include "HeartsGame.h"
#include <memory>
#include "Sprite.h"
#include "Player.h"
#include "Deck.h"
#include <iostream>

HeartsGame::HeartsGame(int width, int height, const char * name) : Game(width, height, name)
{

}

void HeartsGame::RunHearts()
{
	Deck deck = Deck();
	deck.Shuffle();

	Player north = Player();
	Player east = Player();
	Player south = Player();
	Player west = Player();

	while (!deck.deck.empty())
	{
		north.hand.push_back(deck.deck.back());
		deck.deck.pop_back();
		east.hand.push_back(deck.deck.back());
		deck.deck.pop_back();
		south.hand.push_back(deck.deck.back());
		deck.deck.pop_back();
		west.hand.push_back(deck.deck.back());
		deck.deck.pop_back();
	}

	south.SortHand();

	const auto bg = std::make_shared<Sprite>("background.png", 640, 360);
	Run([=]()
	{
		bg->Draw();

		int i = 10;
		
		for(auto card : south.hand)
		{
			card->sprite->Move(i, i);
			card->sprite->Draw();
			std::cout << card->sprite->x;
			i += 10;
		}
	});
}

