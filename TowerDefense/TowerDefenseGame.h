#pragma once
#include "Game.h"
#include "Sprite.h"
#include "Point.h"
#include "Line.h"
#include "Enemy.h"
#include "Tower.h"
#include <vector>

#define SCREEN_WIDTH 1280.0f
#define SCREEN_HEIGHT 720.0f

class TowerDefenseGame : public Game
{
public:
	TowerDefenseGame(int width, int height, const char* name);
	~TowerDefenseGame();
	void RunSpaceInvaders();
	void CalculateLines();
	void ChangeGoldAmount(int number);
	void CalculateMouseInput();
	void CalculateSelectedSlot();
	void CalculateEnemyMovement();
	void TowerAttack();
	void DrawAll();
	double DistanceTo(Sprite * missile, Sprite * enemie);
private:
	std::vector<Line> lines;
	std::shared_ptr<Sprite> background;
	std::shared_ptr<Texture> slot;
	std::shared_ptr<Texture> slot_way;
	std::shared_ptr<Texture> slot_grass;
	std::shared_ptr<Texture> slot_towerSelection;
	std::shared_ptr<Texture> tower1;
	std::shared_ptr<Texture> tower2;
	std::shared_ptr<Texture> tower3;
	std::vector<std::shared_ptr<Texture>> numbers;
	std::vector<Sprite> numbersDrawn;
	//std::vector<Sprite> towers;
	std::shared_ptr<Sprite> slot_selected;
	std::vector<Sprite> slots;
	std::vector<Point> enemyWay;
	std::shared_ptr<Texture> enemy1;
	std::shared_ptr<Texture> enemy2;
	std::shared_ptr<Texture> enemy3;
	//std::vector<Sprite> enemies;
	double lastTime;
	int slot_selected_x;
	int slot_selected_y;
	int map[9][16] = {
		{ 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0 },
		{ 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0 },
		{ 0, 0, 0, 2, 1, 0, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 2, 1, 0, 2, 2, 0, 2, 2, 0, 1, 2, 2, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 2, 2, 2, 0, 2, 2, 2, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};

	std::vector<Sprite> goldNumber1;
	std::vector<Sprite> goldNumber2;
	std::vector<Sprite> goldNumber3;
	int xGold;
	int yGold;
	int goldNumberPart1;
	int goldNumberPart2;
	int goldNumberPart3;

	std::vector<Enemy> enemies;
	std::vector<Tower> towers;
};