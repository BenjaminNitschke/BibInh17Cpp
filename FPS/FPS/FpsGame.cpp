#include "stdafx.h"
#include "FpsGame.h"

FpsGame::FpsGame(int width, int height, const char * name) : Game(width, height, name)
{
}

FpsGame::~FpsGame()
{
}

void FpsGame::RunGame()
{
	SetupProjection();

	Run([=]()
	{
		Input();
		
		UpdateCamera();

		// tell openGL it will work with a texture
		glBindTexture(GL_TEXTURE_2D, ground->texture->handle);
		// start using texture mode
		glEnable(GL_TEXTURE_2D);
		// tell openGL there will be a quad
		glBegin(GL_QUADS);

		// bind the texture to the quad
		glTexCoord2f(25, 25);
		glVertex3f(50, 50, 0);

		glTexCoord2f(0, 25);
		glVertex3f(-50, 50, 0);

		glTexCoord2f(0, 0);
		glVertex3f(-50, -50, 0);

		glTexCoord2f(25, 0);
		glVertex3f(50, -50, 0);

		// tell openGL there won't be any more commands
		glEnd();
	});
}

// Do all the math in order to have a sensible camera and movement
void FpsGame::SetupProjection() const
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float zNear = 0.1f;
	float zFar = 100.0f;
	GLfloat aspect = 1280 / (float)720;
	float fov = 60.0f;
	float fowH = tan(float(fov / 360.0f * 3.14159f)) * zNear;
	float fowW = fowH * aspect;
	glFrustum(-fowW, fowW, -fowH, fowH, zNear, zFar);
}

void FpsGame::UpdateCamera() const
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glRotatef(-90, 1, 0, 0);
	glRotatef(-90 + Yrotation, 1 + Xrotation, 0, 0);
	glTranslatef(movement.x, movement.y, -2);
}

void FpsGame::Input()
{
	if (leftPressed)
		movement.x += MovementSpeed;
	else if (rightPressed)
		movement.x -= MovementSpeed;
	else if (upPressed)
		movement.y -= MovementSpeed;
	else if (downPressed)
		movement.y += MovementSpeed;

	Xrotation += xDelta * 0.2;
	Yrotation += yDelta * 0.2;
}
