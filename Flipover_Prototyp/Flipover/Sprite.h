#pragma once
#include <memory>
#include "Texture.h"

class Sprite
{
public:
	Sprite(std::shared_ptr<Texture> texture, int x, int y)
		: texture(texture), x(x), y(y) {}
	void Draw(int offsetX = 0);
	void Move(float addX, float addY)
	{
		x += addX;
		y += addY;
	}
	float x;
	float y;
	int GetWidth() { return texture->width;}
	int GetHeight() { return texture->height;}
	float DistanceTo(std::shared_ptr<Sprite> other, float xOffset)
	{
		float distanceX = abs(x + xOffset - other->x);
		float distanceY = abs(y - other->y);
		return sqrt(distanceX*distanceX + distanceY*distanceY);
	}
private:
	std::shared_ptr<Texture> texture;
};
