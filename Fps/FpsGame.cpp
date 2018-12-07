#include "stdafx.h"
#include "FpsGame.h"
#include "Sprite.h"

void Fps::FpsGame::SetupProjection()
{
	//Camera fun
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float zNear = 0.1f;
	float zFar = 100.0f;
	GLfloat aspect = viewportWidth / (float)viewportHeight;
	float fov = 60.0f;
	
	float fovH = tan(float(fov / 360.0f * 3.14159f)) * zNear;
	float fovW = fovH * aspect;
	glFrustum(-fovW, fovW, -fovH, fovH, zNear, zFar);
}

void Fps::FpsGame::UpdateCamera()
{
	//GL_MODELVIEW
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(rotationY += (mouseY * 0.05f), 1, 0, 0);
	mouseY = 0;

	glRotatef(rotationX += (mouseX * 0.1f), 0, 0, 1);
	mouseX = 0;

	//glRotatef(-90, 1, 0, 0);
	
	if (shiftPressed)
	{
		movementSpeed = 0.3f;
	}
	else
	{
		movementSpeed = 0.1f;
	}

	if (wPressed)
	{
		//movement.x += movementSpeed;
		movement.x += -sin(rotationX*degreeToRadian) * movementSpeed;
		movement.y += -cos(rotationX*degreeToRadian) * movementSpeed;
	}
	if (aPressed)
	{
		//movement.y += movementSpeed;
		movement.x += -sin((rotationX - 90)*degreeToRadian) * movementSpeed;
		movement.y += -cos((rotationX - 90)*degreeToRadian) * movementSpeed;
	}
	if (sPressed)
	{
		//movement.x -= movementSpeed;
		movement.x += -sin((rotationX - 180)*degreeToRadian) * movementSpeed;
		movement.y += -cos((rotationX - 180)*degreeToRadian) * movementSpeed;
	}
	if (dPressed)
	{
		//movement.y -= movementSpeed;
		movement.x += -sin((rotationX + 90)*degreeToRadian) * movementSpeed;
		movement.y += -cos((rotationX + 90)*degreeToRadian) * movementSpeed;
	}
	glTranslatef(movement.x, movement.y, -2);
}

void Fps::FpsGame::RunGame()
{
	Run([=]()
	{
		UpdateCamera();

		glBindTexture(GL_TEXTURE_2D, groundTexture->handle);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBegin(GL_QUADS);

		glTexCoord2f(25, 25);
		glVertex3f(50, 50, 0);

		glTexCoord2f(0, 25);
		glVertex3f(-50, 50, 0);

		glTexCoord2f(0, 0);
		glVertex3f(-50, -50, 0);

		glTexCoord2f(25, 0);
		glVertex3f(50, -50, 0);

		glEnd();
	});
}