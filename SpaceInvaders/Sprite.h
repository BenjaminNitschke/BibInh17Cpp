#pragma once
#include <memory>
#include "Texture.h"
#include "Math.h";

class Sprite
{
public:
	Sprite(std::shared_ptr<Texture> texture, int x, int y)
		: texture(texture), x(x), y(y) {}
	std::shared_ptr<Texture> texture;
	int x;
	int y;
	void Draw();
	void Move(int addX, int addY)
	{
		if (x + addX - texture->width * .5f < 0)
		{
			x = 0 + texture->width * .5f;
			return;
		}
		if (x + addX + texture->width * .5f > 1280)
		{
			x = 1280 - texture->width * .5f;
			return;
		}
		x += addX;
		y += addY;
	}

	float DistanceTo(std::shared_ptr<Sprite> a, std::shared_ptr<Sprite> b)
	{
		return sqrt((b->x - a->x) * (b->x - a->x) + (b->y - b->texture->width * .5f - a->y) * (b->y - a->y));
	}
private:
	
};

