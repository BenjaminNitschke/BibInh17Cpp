#pragma once
#include <memory>
#include "Texture.h"

class Sprite
{
public:
	float x, y;
	Sprite(const char* source, float x, float y);
	void Draw();
	void Move(float x, float y);
	~Sprite();
private:
	std::shared_ptr<Texture> texture;
};
