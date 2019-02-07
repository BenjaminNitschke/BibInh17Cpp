#pragma once
#include <memory>
#include "Texture.h"

class Sprite
{
public:
	Sprite(std::shared_ptr<Texture> texture, int x, int y)
		: texture(texture), x(x), y(y) {}
	void Draw();
	void Move(int addX, int addY);
	int getPos(int index);
	void setPos(int x, int y);
	double DistanceTo(Sprite * missile, Sprite * enemie);
private:
	std::shared_ptr<Texture> texture;
	int x;
	int y;
	float GetOpenGLX(int px);
	float GetOpenGLY(int py);
};

