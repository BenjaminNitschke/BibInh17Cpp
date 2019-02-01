#include "stdafx.h"
#include "Sprite.h"

#define SCREEN_WIDTH 1280.0f
#define SCREEN_HEIGHT 720.0f

float GetOpenGLX(int px){
	int centerX = px - (int)SCREEN_WIDTH/2;
	return (centerX/SCREEN_WIDTH)*2.0f;
}
float GetOpenGLY(int py){
	int centerY = py - (int)SCREEN_HEIGHT/2;
	return (centerY/SCREEN_HEIGHT)*(-2.0f);
}

void Sprite::Draw(int offsetX)
{
	glBindTexture(GL_TEXTURE_2D, texture->handle);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);

	int halfWidth = texture->width / scale;
	int halfHeight = texture->height / scale;
	int currentX = x + offsetX;
	
	glTexCoord2f(1, 1);
	glVertex2f(GetOpenGLX(currentX+halfWidth), GetOpenGLY(y-halfHeight));

	glTexCoord2f(0, 1);
	glVertex2f(GetOpenGLX(currentX-halfWidth), GetOpenGLY(y-halfHeight));

	glTexCoord2f(0, 0);
	glVertex2f(GetOpenGLX(currentX-halfWidth), GetOpenGLY(y+halfHeight));

	glTexCoord2f(1, 0);
	glVertex2f(GetOpenGLX(currentX+halfWidth), GetOpenGLY(y+halfHeight));

	glEnd();
}
