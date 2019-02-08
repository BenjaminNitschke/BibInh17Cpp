#pragma once
#include <memory>
#include "Texture.h"

class Sprite
{
public:
	float x, y;
	Sprite(std::shared_ptr<Texture> texture, int x, int y)
		: texture(texture), x(x), y(y) {}
	void Draw();
	void Move(float x, float y);
	~Sprite();
	std::shared_ptr<Texture> texture;
	int GetWidth() { return texture->width; }
	int GetHeight() { return texture->height; }
};
