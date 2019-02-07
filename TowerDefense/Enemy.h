#pragma once
#include "Sprite.h"
#include "Point.h"
#include <GLFW/glfw3.h>
#include <vector>
class Enemy
{
public:
	Enemy() {};
	Enemy(int x, int y, int health, int speed, Sprite sprite, std::vector<Point> way);
	~Enemy();
	void Move();
	void Draw();
private:
	Sprite sprite;
	int x;
	int y;
	int health;
	int speed;
	std::vector<Point> way;
	int currentX;
	int currentY;
	double delta = 0;
	double lastTime = 0;
	int index = 0;
	int dirInX = 0;
	int dirInY = 0;
};

