#include "stdafx.h"
#include "Tower.h"

Tower::~Tower()
{
}

Tower::Tower(int xIndex, int yIndex, float attacksPerSec, float damage, float range, Sprite sprite, bool* iPressed)
{
	this->xIndex = xIndex;
	this->yIndex = yIndex;
	this->attacksPerSec = attacksPerSec;
	this->damage = damage;
	this->range = range;
	this->sprite = sprite;
	this->iPressed = iPressed;
	this->sprite.setPos(xIndex * 80 + 40, yIndex * 80 + 40);
	lastAttackTime = glfwGetTime();
	canShoot = false;
}

void Tower::AddEnemy(Enemy* enemy)
{
	enemies.push_back(enemy);
	lines.push_back(Line(Point(xIndex * 80 + 40, yIndex * 80 + 40), enemy->GetPos()));
}

void Tower::RemoveEnemy(Enemy* enemy)
{
	std::vector<Enemy*>::iterator pos = std::find(enemies.begin(), enemies.end(), enemy);
	if (pos != enemies.end())
	{
		int index = pos - enemies.begin();
		//lines.erase(lines.begin() + index);
		//enemies.erase(pos);
	}
}

float DistanceBetween(Point a, Point b)
{
	float deltaX = b.x - a.x;
	float deltaY = b.y- a.y;

	return (deltaX * deltaX) + (deltaY * deltaY);
}

void Tower::CalculateLines()
{
	distanceToEnemies.clear();
	float distance = 1000000000;
	for (int i = 0; i < enemies.size(); i++)
	{
		float tmp = DistanceBetween(enemies[i]->GetPos(), Point(xIndex * 80 + 40, yIndex * 80 + 40));
		distanceToEnemies.push_back(tmp);
		if (tmp < distance)
		{
			distance = tmp;
			indexOfNearestEnemy = i;
		}
	}

	for (int i = 0; i < lines.size(); i++)
	{
		lines[i].SetPoint(1, enemies[i]->GetPos().x, enemies[i]->GetPos().y);
	}
}

void Tower::Draw()
{
	DrawSprite();
	if(*iPressed)
		DrawLine();
}

void Tower::Attack()
{
	double now = glfwGetTime();
	if ((now - lastAttackTime) > ((double)1 / (double)attacksPerSec))
	{
		canShoot = true;
		lastAttackTime = now;
	}
}

void Tower::DrawSprite()
{
	sprite.Draw();
}

void Tower::DrawLine()
{
	for (int i = 0; i < lines.size(); i++)
	{
		if(i == indexOfNearestEnemy && distanceToEnemies[i] <= range*range)
			lines[i].Draw(1, 0, 0, 0.9f);
		else
			lines[i].Draw(0, 0, 0, 0.1f);
	}

	if (canShoot && (glfwGetTime() - lastAttackTime) < 0.25f)
	{
		if (distanceToEnemies[indexOfNearestEnemy] <= range*range)
		{
			std::cout << "Fire: " << glfwGetTime() << std::endl;
			Line tmp = Line(Point(xIndex * 80 + 40, yIndex * 80 + 40), enemies[indexOfNearestEnemy]->GetPos());
			RemoveEnemy(enemies[indexOfNearestEnemy]);

			tmp.Draw(1, 1, 0, 1);
		}
	}
	else
	{
		canShoot = false;
	}
}