#include "stdafx.h"
#include "Sprite.h"
#include "GLFW/glfw3.h"
#include <iostream>

// width of the screen
#define SCREEN_WIDTH (float)1280.0f
// height of the screen
#define SCREEN_HEIGHT (float)720.0f

// convert custom screen-space to openGL screen-space
float GetX(int x)
{
	float centerX = x - SCREEN_WIDTH / 2;
	return centerX / SCREEN_WIDTH * 2;
}

float GetY(int y)
{
	float centerY = y - SCREEN_HEIGHT / 2;
	return centerY / SCREEN_HEIGHT * -2;
}

Sprite::Sprite(std::string source, float x, float y, float scaling) : x(x), y(y), scaling(scaling)
{
	texture = std::make_shared<Texture>(source.c_str());
}

// Draw the entity
void Sprite::Draw()
{
	// tell openGL it will work with a texture
	glBindTexture(GL_TEXTURE_2D, texture->handle);
	// start using texture mode
	glEnable(GL_TEXTURE_2D);
	// use transparency
	glEnable(GL_BLEND);
	// transparency mode
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// tell openGL there will be a quad
	glBegin(GL_QUADS);

	// dimensions of the texture
	int halfWidth = texture->width / 2 * scaling;
	int halfHeight = texture->height / 2 * scaling;

	// bind the texture to the quad
	glTexCoord2f(1, 1);
	glVertex2f(GetX(x + halfWidth), GetY(y - halfHeight));

	glTexCoord2f(0, 1);
	glVertex2f(GetX(x - halfWidth), GetY(y - halfHeight));

	glTexCoord2f(0, 0);
	glVertex2f(GetX(x - halfWidth), GetY(y + halfHeight));

	glTexCoord2f(1, 0);
	glVertex2f(GetX(x + halfWidth), GetY(y + halfHeight));

	// tell openGL there won't be any more commands
	glEnd();

	//std::cout << "sprite drawn @ " << std::to_string(x) << " / " << std::to_string(y) << std::endl;
}

// move the entity by x and y
void Sprite::Move(const float x, const float y)
{
	this->x += x;
	this->y += y;
}

void Sprite::MoveTo(float x, float y)
{
	this->x = x;
	this->y = y;
}

Sprite::~Sprite() = default;
