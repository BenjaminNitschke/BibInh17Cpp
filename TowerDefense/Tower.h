#pragma once
#include "Line.h"
#include "Enemy.h"
class Tower
{
public:
	Tower(int xIndex, int yIndex, float attacksPerSec, float damage, Sprite sprite);
	~Tower();
	void AddEnemy(Enemy enemy);
	void RemoveEnemy(Enemy enemy);
	void CalculateLines();
	void Draw();
	template < typename T>
	std::pair<bool, int > findInVector(const std::vector<T>  & vecOfElements, const T  & element);
private:
	int xIndex;
	int yIndex;
	float attacksPerSec;
	float damage;
	Sprite sprite;
	std::vector<Line> lines;
	std::vector<Enemy> enemies;
};

// https://thispointer.com/c-how-to-find-an-element-in-vector-and-get-its-index/