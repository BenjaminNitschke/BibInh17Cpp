#pragma once
#include "Game.h"
#include "Sprite.h"
#include <vector>

class SpaceInvadersGame : public Game
{
public:
	SpaceInvadersGame(int width, int height, const char* name);
	~SpaceInvadersGame();
};
