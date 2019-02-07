#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(int x, int y, int health, int speed, Sprite sprite, std::vector<Point> way)
{
	this->x = x;
	this->y = y;
	this->health = health;
	this->speed = speed;
	this->sprite = sprite;
	this->way = way;
}

Enemy::~Enemy()
{
}

void Enemy::Move()
{
	currentX = std::floor((x - 40) / 80);
	int yOffset = dirInY >= 0 ? -40 : 40;
	currentY = std::floor((y + yOffset) / 80);

	if (way[index + 1].x - currentX > 0) dirInX = 1;
	else if (way[index + 1].x - currentX < 0) dirInX = -1;
	else dirInX = 0;

	if (way[index + 1].y - currentY > 0) dirInY = 1;
	else if (way[index + 1].y - currentY < 0) dirInY = -1;
	else dirInY = 0;

	double now = glfwGetTime();
	delta += (now - lastTime) * speed;
	lastTime = now;

	if (delta >= 1)
	{
		delta--;
		index++;
	}
		
	x = (int)(way[index].x * 80 + 40 + (delta * 80 * dirInX));
	y = (int)(way[index].y * 80 + 40 + (delta * 80 * dirInY));
		
	sprite.setPos(x, y);

	if (index == 21)
	{
		index = 0;
	}
}

void Enemy::Draw()
{
	sprite.Draw();
}
