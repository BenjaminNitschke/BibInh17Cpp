#include "stdafx.h"
#include "Entity.h"

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
	return centerY / SCREEN_HEIGHT * 2;
}

// create a visual representation for this entity based on a png file
Entity::Entity(const char* source, float x, float y) : x(x), y(y)
{

	tex = std::make_shared<Sprite>(std::make_shared<Texture>(source));
}

// create a visual representation for this entity based on an existing sprite
Entity::Entity(std::shared_ptr<Sprite> tex, float x, float y) : x(x), y(y), tex(tex)
{

}

Entity::~Entity()
{

}

// Draw the entity
void Entity::Draw()
{
	// tell openGL it will work with a texture
	glBindTexture(GL_TEXTURE_2D, tex->texture->handle);
	// start using texture mode
	glEnable(GL_TEXTURE_2D);
	// use transparency
	glEnable(GL_BLEND);
	// transparency mode
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// tell openGL there will be a quad
	glBegin(GL_QUADS);

	// dimensions of the texture
	int halfWidth = tex->texture->width / 2;
	int halfHeight = tex->texture->height / 2;

	// bind the texture to the quad
	glTexCoord2f(0, 0);
	glVertex2f(GetX(x - halfWidth), GetY(y - halfHeight));

	glTexCoord2f(1, 0);
	glVertex2f(GetX(x + halfWidth), GetY(y - halfHeight));

	glTexCoord2f(1, 1);
	glVertex2f(GetX(x + halfWidth), GetY(y + halfHeight));

	glTexCoord2f(0, 1);
	glVertex2f(GetX(x - halfWidth), GetY(y + halfHeight));

	// tell openGL there wont be any more commands
	glEnd();
}

// move the entity by x and y
void Entity::Move(const float x, const float y)
{
	this->x += x;
	this->y += y;
}

// standard AABB collision detections
bool Entity::CheckCollision(const std::shared_ptr<Entity> &entity)
{

	return x >= entity->x - entity->tex->texture->width / 2 && x <= entity->x + entity->tex->texture->width / 2 &&
		y >= entity->y - entity->tex->texture->height / 2 && y <= entity->y + entity->tex->texture->height / 2;
}

int Entity::OutOfBounds()
{
	if (x - tex->texture->width / 2 <= 0) return NEG_X;
	if (x + tex->texture->width / 2 >= SCREEN_WIDTH) return POS_X;
	if (y - tex->texture->height / 2 <= 0) return NEG_Y;
	if (y + tex->texture->height / 2 >= SCREEN_HEIGHT) return POS_Y;
	return IN_BOUNDS;
}
