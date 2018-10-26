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
		x += addX;
		y += addY;
	}
private:
	std::shared_ptr<Texture> texture;
	int x;
	int y;
};

