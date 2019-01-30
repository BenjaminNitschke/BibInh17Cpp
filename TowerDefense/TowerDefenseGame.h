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
	void ControlSelectedSlot();
	void ControlMissles();
	void ControlShip();
	void MoveEnemies();
	void DrawAll();
	double DistanceTo(Sprite * missile, Sprite * enemie);
private:
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Texture> slot;
	std::shared_ptr<Texture> slot_way;
	std::shared_ptr<Texture> slot_grass;
	std::shared_ptr<Sprite> slot_selected;
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
	int map[9][16] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0 },
		{ 0, 0, 0, 2, 1, 0, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 2, 1, 0, 2, 2, 2, 2, 2, 0, 1, 2, 2, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};

};

