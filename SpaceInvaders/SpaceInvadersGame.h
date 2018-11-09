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
	void ControlMissles();
	void ControlShip();
	void MoveEnemies();
	void DrawAll();
	double DistanceTo(Sprite * missile, Sprite * enemie);
private:
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Sprite> ship;
	std::vector<Sprite> enemies;
	std::shared_ptr<Texture> missile;
	std::vector<Sprite> missiles;
	int frames;
	int enemyDir;
	int enemySpeed;
	int enemyH;
	double lastTimeShoot;
};

