#pragma once
#include <Game.h>
#include <Texture.h>
#include <memory>

class FirstPersonShooterGame : public Game
{
	std::shared_ptr<Texture> groundTexture;
	float rotation = 0;
public:
	FirstPersonShooterGame() : Game("FistPersonShooter")
	{
		//Load textures
		groundTexture = std::make_shared<Texture>("ground.png");
	};
	~FirstPersonShooterGame() 
	{
	}
	void RunGame();
};