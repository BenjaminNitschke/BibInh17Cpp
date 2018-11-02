#pragma once
#include <memory>
#include "Texture.h"

class Sprite
{
public:
	Sprite(std::shared_ptr<Texture> tex);
	~Sprite();
	std::shared_ptr<Texture> texture;
};
