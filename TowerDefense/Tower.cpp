#include "stdafx.h"
#include "Tower.h"

Tower::~Tower()
{
}

Tower::Tower(int xIndex, int yIndex, float attacksPerSec, float damage, Sprite sprite)
{
	this->xIndex = xIndex;
	this->yIndex = yIndex;
	this->attacksPerSec = attacksPerSec;
	this->damage = damage;
	this->sprite = sprite;
	this->sprite.setPos(xIndex * 80 + 40, yIndex * 80 + 40);
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
		enemies.erase(pos);

}

void Tower::CalculateLines()
{

	for (int i = 0; i < lines.size(); i++)
	{
		lines[i].SetPoint(1, enemies[i]->GetPos().x, enemies[i]->GetPos().y);
	}
}

void Tower::Draw()
{
	DrawSprite();
	DrawLine();
}

void Tower::DrawSprite()
{
	sprite.Draw();
}

void Tower::DrawLine()
{
	for (int i = 0; i < lines.size(); i++)
	{
		lines[i].Draw();
	}
}