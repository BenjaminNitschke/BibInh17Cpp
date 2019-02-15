#pragma once
#include "Game.h"
#include "Player.h"
#include "Deck.h"

class HeartsGame : public Game
{
private:
	std::shared_ptr<Sprite> bg;
	std::vector<std::shared_ptr<Card>> stack;	
	bool ValidCard(std::shared_ptr<Card> card);
	void ReshuffleDeck();
public:
	static Player north, south;
	static Deck* deck;
	static std::shared_ptr<Sprite> back;
	HeartsGame(int width, int height, const char* name);
	void RunHearts();
	~HeartsGame()
	{
		delete deck;
	}
};
