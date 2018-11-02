#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(std::shared_ptr<Texture> tex) : texture(tex)
{

}

Sprite::~Sprite() = default;
