#pragma once
#include "Sprite.h"
#include "Enemy.h"
#include <iostream>
class Bullet
{
public:
	Bullet(Sprite sprite, int x, int y, float speed, Enemy* enemy);
	~Bullet();
	void Draw();
	void Move();
	void Check();
private:
	Sprite sprite;
	int x;
	int y;
	float speed;
	Enemy* target;
	float CalculateAngleInRadian(Point p1, Point p2);
	const float  PI_F = 3.14159265358979f;
	bool hittedTarget = false;
	double lastTime = glfwGetTime();
};

