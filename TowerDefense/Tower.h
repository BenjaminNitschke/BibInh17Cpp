#pragma once
#include "Line.h"
#include "Enemy.h"
#include "Bullet.h"
#include <iostream>
#include <algorithm>
class Tower
{
public:
	Tower(int xIndex, int yIndex, float attacksPerSec, float damage, float range, Sprite sprite, bool* iPressed);
	~Tower();
	void AddEnemy(Enemy* enemy);
	void RemoveEnemy(Enemy* enemy);
	void CalculateLines();
	void Draw();
	void Attack();
private:
	int xIndex;
	int yIndex;
	int indexOfNearestEnemy;
	float attacksPerSec;
	float damage;
	float range;
	Sprite sprite;
	bool* iPressed;
	double lastAttackTime;
	bool canShoot;
	std::vector<Line> lines;
	std::vector<Enemy*> enemies;
	std::vector<float> distanceToEnemies;
	std::vector<Bullet> bullets;
	std::shared_ptr<Texture> bullet1;
	void DrawLine();
	void DrawSprite();
};

// https://thispointer.com/c-how-to-find-an-element-in-vector-and-get-its-index/