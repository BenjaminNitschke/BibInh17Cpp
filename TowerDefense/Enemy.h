#pragma once
#include "Sprite.h"
#include "Point.h"
#include <GLFW/glfw3.h>
#include <vector>
class Enemy
{
public:
	Enemy() {};
	Enemy(int x, int y, int health, float speed, Sprite sprite, std::vector<Point> way, int startIndex);
	~Enemy();
	void Move();
	void Draw();
	Point GetPos();
	bool operator==(Enemy comp) { return this->x == comp.x; }
private:
	Sprite sprite;
	int x;
	int y;
	int health;
	float speed;
	std::vector<Point> way;
	int currentX;
	int currentY;
	double delta = 0;
	double lastTime = 0;
	int index = 0;
	int dirInX = 0;
	int dirInY = 0;
};

