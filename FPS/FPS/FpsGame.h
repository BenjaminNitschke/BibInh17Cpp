#pragma once
#include "Game.h"
#include <memory>
#include "Sprite.h"

class FpsGame : public Game
{
public:
	FpsGame(int width, int height, const char* name);
	~FpsGame();
	void RunGame();
	std::shared_ptr<Sprite> ground = std::make_shared<Sprite>("ground.png", 640, 360);
};

