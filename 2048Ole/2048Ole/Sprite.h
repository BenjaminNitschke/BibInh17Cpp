#pragma once
#include <memory>
#include "Texture.h"

class Sprite
{
public:
	Sprite(std::shared_ptr<Texture> texture, int x, int y)
		: texture(texture), x(x), y(y) {}
	void Draw();
	void Move(int addX, int addY)
	{
		if (x + addX < 100 || x + addX > 1200)
		{
			x = x;
		}
		else
		{
			x += addX;
		}
		y += addY;
	}
	void Shoot(int addX, int addY)
	{
		x += addX;
		y += addY;
	}
private:
	std::shared_ptr<Texture> texture;
	int x;
	int y;
};

