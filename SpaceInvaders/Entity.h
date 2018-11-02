#pragma once
#include <memory>
#include "Sprite.h"

// states of the entities position
#define IN_BOUNDS 0x0
#define NEG_X     0x1
#define POS_X     0x2
#define NEG_Y     0x3
#define POS_Y     0x4

class Entity
{
public:
	float x, y;
	Entity(const char* source, float x, float y);
	Entity(std::shared_ptr<Sprite> tex, float x, float y);
	~Entity();
	void Draw();
	void Move(float x, float y);
	bool CheckCollision(const std::shared_ptr<Entity> &entity);
	int OutOfBounds();
private:
	std::shared_ptr<Sprite> tex;
	bool dead = false;
	void Delete();
};
