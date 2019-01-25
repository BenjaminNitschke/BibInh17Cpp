#pragma once
#include "Game.h"
#include "Sprite.h"
#include <vector>

class TowerDefenseGame : public Game
{
public:
	TowerDefenseGame(int width, int height, const char* name);
	~TowerDefenseGame();
	void RunSpaceInvaders();
	void ControlMissles();
	void ControlShip();
	void MoveEnemies();
	void DrawAll();
	double DistanceTo(Sprite * missile, Sprite * enemie);
private:
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Texture> slot;
	std::vector<Sprite> slots;
	std::shared_ptr<Sprite> ship;
	std::vector<Sprite> enemies;
	std::shared_ptr<Texture> missile;
	std::vector<Sprite> missiles;
	int frames;
	int enemyDir;
	int enemySpeed;
	int enemyH;
	double lastTimeShoot;
	bool tower[16][9];

};

