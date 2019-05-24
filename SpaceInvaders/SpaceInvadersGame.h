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
	void FireMissile();
	void HandleMissiles();
	bool CollidingWithEnemyAndKilledIt(std::shared_ptr<Sprite> missile);
	void MoveEnemies();
	void DrawAll();
private:
	double lastTimeShot;
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Sprite> ship;
	std::shared_ptr<Texture> missileTexture;
	std::vector<std::shared_ptr<Sprite>> activeMissiles;
	std::vector<std::shared_ptr<Sprite>> enemies;
	float enemiesPosition = 0;
	bool enemiesMovingRight = true;
	bool aiMovingRight = false;
};

