#pragma once
#include <Game.h>
#include <Texture.h>
#include <memory>
#include <Vector3.h>

class FpsGame : public Game
{
	std::shared_ptr<Texture> groundTexture;
	float rotation = 0;
	Vector3 movement = Vector3(0, 0, 0);

public:
	FpsGame() : Game("Fps")
	{
		groundTexture = std::make_shared<Texture>("Ground.png");
	}
	~FpsGame()
	{
	}
	void RunGame();
};

