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
	void DrawAll();
	void ControlShip();
	void MoveEnemies();
	void Shoot();
	bool CollidingWithAnEnemyAndKilledIt(std::shared_ptr<Sprite> missile);
private:
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Sprite> ship;
	std::vector<std::shared_ptr<Sprite>> enemies;
	std::vector<std::shared_ptr<Sprite>> missiles;
	std::shared_ptr<Sprite> win;
	std::shared_ptr<Sprite> lose;
	int enemycount;
	float timeBetweenShots;
	float enemyMoveTime;
	float direction;
	bool lost;
};

