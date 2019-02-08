#pragma once
#include "Sprite.h"

class Entity
{
public:
	std::shared_ptr<Sprite> sprite;
	int index, speed;
	Entity(std::shared_ptr<Sprite> sprite, int index, int speed) : sprite(sprite), index(index), speed(speed) {};
	~Entity();
};