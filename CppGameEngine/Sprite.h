#pragma once
#include <memory>
#include "Texture.h"
#include <string>

class Sprite
{
public:
	float x, y;
	Sprite(std::string source, float x, float y);
	void Draw();
	void Move(float x, float y);
	~Sprite();
	std::shared_ptr<Texture> texture;
};
