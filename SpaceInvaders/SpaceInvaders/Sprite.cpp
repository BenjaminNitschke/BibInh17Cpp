#include "stdafx.h"
#include "Sprite.h"

float GetOpenGLX(int px){
	int centerX = px-640;
	return (centerX/1280.0f)*2.0f;
}
float GetOpenGLY(int py){
	int centerY = py-360;
	return (centerY/720.0f)*(-2.0f);
}

void Sprite::Draw()
{
	glBindTexture(GL_TEXTURE_2D, texture->handle);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);

	int halfWidth = texture->width / 2;
	int halfHeight = texture->height / 2;
	
	glTexCoord2f(1, 1);
	glVertex2f(GetOpenGLX(x+halfWidth), GetOpenGLY(y-halfHeight));

	glTexCoord2f(0, 1);
	glVertex2f(GetOpenGLX(x-halfWidth), GetOpenGLY(y-halfHeight));

	glTexCoord2f(0, 0);
	glVertex2f(GetOpenGLX(x-halfWidth), GetOpenGLY(y+halfHeight));

	glTexCoord2f(1, 0);
	glVertex2f(GetOpenGLX(x+halfWidth), GetOpenGLY(y+halfHeight));

	glEnd();
}
