#pragma once
#include "Game.h"
#include "Sprite.h"
#include "Point.h"
#include <vector>

class TowerDefenseGame : public Game
{
public:
	TowerDefenseGame(int width, int height, const char* name);
	~TowerDefenseGame();
	void RunSpaceInvaders();
	void CalculateSelectedSlot();
	void CalculateEnemyMovement();
	void DrawAll();
	double DistanceTo(Sprite * missile, Sprite * enemie);
private:
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Texture> slot;
	std::shared_ptr<Texture> slot_way;
	std::shared_ptr<Texture> slot_grass;
	std::shared_ptr<Sprite> slot_selected;
	std::vector<Sprite> slots;
	std::vector<Point> enemyWay;
	std::shared_ptr<Texture> enemy1;
	float enemy1_speed = 3;
	std::shared_ptr<Texture> enemy2;
	std::shared_ptr<Texture> enemy3;
	std::vector<Sprite> enemies;
	double lastTime;
	int slot_selected_x;
	int slot_selected_y;
	int map[9][16] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0 },
		{ 0, 0, 0, 2, 1, 0, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 2, 1, 0, 2, 2, 0, 2, 2, 0, 1, 2, 2, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 2, 2, 2, 0, 2, 2, 2, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};

};

