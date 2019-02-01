#pragma once
#include <memory>
#include "Texture.h"
#include <string>

class Sprite
{
public:
	float x, y, scaling;
	Sprite(std::string source, float x, float y, float scaling = 1);
	void Draw();
	void Move(float x, float y);
	void MoveTo(float x, float y);
	~Sprite();
	std::shared_ptr<Texture> texture;
};
