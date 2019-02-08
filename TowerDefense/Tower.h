#pragma once
#include "Line.h"
#include "Enemy.h"
#include <algorithm>
class Tower
{
public:
	Tower(int xIndex, int yIndex, float attacksPerSec, float damage, Sprite sprite);
	~Tower();
	void AddEnemy(Enemy* enemy);
	void RemoveEnemy(Enemy* enemy);
	void CalculateLines();
	void Draw();
private:
	int xIndex;
	int yIndex;
	float attacksPerSec;
	float damage;
	Sprite sprite;
	std::vector<Line> lines;
	std::vector<Enemy*> enemies;
	void DrawLine();
	void DrawSprite();
};

// https://thispointer.com/c-how-to-find-an-element-in-vector-and-get-its-index/