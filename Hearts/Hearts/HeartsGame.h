#pragma once
#include "Game.h"

class HeartsGame : public Game
{
public:
	HeartsGame(int width, int height, const char* name);

	void RunHearts();
	
};
