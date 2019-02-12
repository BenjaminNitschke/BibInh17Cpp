#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet(Sprite sprite, int x, int y, float speed, Enemy* enemy)
{
	this->sprite = sprite;
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->target = enemy;
}

Bullet::~Bullet()
{
}

void Bullet::Draw()
{
	if (!hittedTarget)
	{
		Move();
		Check();
		sprite.Draw();
	}
}

void Bullet::Move()
{
	double now = glfwGetTime();
	Point p = target->GetPos();
	float distance = std::sqrt(((p.x-x)*(p.x - x)) + ((p.y - y)*(p.y - y)));
	float angle = CalculateAngleInRadian(Point(10, 0), Point(p.x - x, p.y -y));
	float deltaX = (std::cos(angle) * speed * (now - lastTime));
	float deltaY = (std::sin(angle) * speed * (now - lastTime));
	if (p.y < y) deltaY *= -1;
	lastTime = now;

	x += deltaX;
	y += deltaY;

	sprite.setPos(x, y);
}

void Bullet::Check()
{
	if (x > 1280)
		hittedTarget = true;
	if (x < 0)
		hittedTarget = true;
	if (y > 720)
		hittedTarget = true;
	if (y < 0)
		hittedTarget = true;

	Point p = target->GetPos();
	if (((p.x - x)*(p.x - x)) + ((p.y - y) * (p.y - y)) < 10 * 10)
	{
		hittedTarget = true;
		//delete this;
	}
}

float Bullet::CalculateAngleInRadian(Point p1, Point p2)
{
	float dotP =  (p1.x * p2.x) + (p1.y * p2.y);
	float p1Length = std::sqrt((p1.x * p1.x) + (p1.y * p1.y));
	float p2Length = std::sqrt((p2.x * p2.x) + (p2.y * p2.y));

	return std::acos(dotP / (p1Length * p2Length))/* * PI_F / 180.0f*/;
}