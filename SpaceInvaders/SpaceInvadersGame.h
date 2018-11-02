#pragma once
#include "Game.h"
#include "Sprite.h"
#include <vector>

class SpaceInvadersGame : public Game
{
public:
	SpaceInvadersGame(int width, int height, const char* name);
	~SpaceInvadersGame();
	void RunSpaceInvaders();
	void ControlShip();
	void MoveEnemies();
	void DrawAll();
private:
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Sprite> ship;
	std::vector<std::shared_ptr<Sprite>> enemies;
	std::shared_ptr<Texture> enemyTexture;
};
