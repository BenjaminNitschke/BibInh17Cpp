#pragma once
#include "Sprite.h"

class Car
{
public:
	std::shared_ptr<Sprite> sprite;
	int index, speed;
	Car(std::shared_ptr<Sprite> sprite, int index, int speed) : sprite(sprite), index(index), speed(speed) {};
	~Car();
};