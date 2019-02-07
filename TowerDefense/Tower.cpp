#include "stdafx.h"
#include "Tower.h"

Tower::Tower(int xIndex, int yIndex, float attacksPerSec, float damage, Sprite sprite)
{
	this->xIndex = xIndex;
	this->yIndex = yIndex;
	this->attacksPerSec = attacksPerSec;
	this->damage = damage;
	this->sprite = sprite;
	this->sprite.setPos(xIndex * 80 + 40, yIndex * 80 + 40);
}

Tower::~Tower()
{
}

void Tower::AddEnemy(Enemy enemy)
{
	enemies.push_back(enemy);
	lines.push_back(*(new Line(Point(xIndex * 80 + 40, yIndex * 80 + 40), enemy.GetPos())));
}

void Tower::RemoveEnemy(Enemy enemy)
{
	int index = findInVector(enemies, enemy).second;
	lines.erase(lines.begin() + index);
	enemies.erase(enemies.begin() + index);
}

void Tower::CalculateLines()
{
}

void Tower::Draw()
{
	sprite.Draw();

	for (int i = 0; i < lines.size(); i++)
	{
		lines[i].Draw();
	}
}

template < typename T>
std::pair<bool, int > Tower::findInVector(const std::vector<T>  & vecOfElements, const T  & element)
{
	std::pair<bool, int > result;

	// Find given element in vector
	auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);

	if (it != vecOfElements.end())
	{
		result.second = distance(vecOfElements.begin(), it);
		result.first = true;
	}
	else
	{
		result.first = false;
		result.second = -1;
	}

	return result;
}