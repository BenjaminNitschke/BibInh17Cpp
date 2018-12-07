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
		SetupProjection();
		UpdateCamera();

		// tell openGL it will work with a texture
		glBindTexture(GL_TEXTURE_2D, ground->texture->handle);
		// start using texture mode
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);

		// bind the texture to the quad
		glTexCoord2f(1, 1);
		glVertex3f(5, 5, 1);

		glTexCoord2f(0, 1);
		glVertex3f(-5, 5, 1);

		glTexCoord2f(0, 0);
		glVertex3f(-5, -5, 1);

		glTexCoord2f(1, 0);
		glVertex3f(5, -5, 1);
		glEnd();


		// tell openGL there will be a quad
		glBegin(GL_QUADS);

		// bind the texture to the quad
		glTexCoord2f(25, 25);
		glVertex3f(10, 10, 0);

		glTexCoord2f(0, 25);
		glVertex3f(-10, 10, 0);

		glTexCoord2f(0, 0);
		glVertex3f(-10, -10, 0);

		glTexCoord2f(25, 0);
		glVertex3f(10, -10, 0);

		// tell openGL there won't be any more commands
		glEnd();

		// put camera back into 2d
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
		glDisable(GL_TEXTURE_2D);
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex3f(-0.02f, 0, 0);
		glVertex3f(0.018f, 0, 0);
		glVertex3f(0, -0.033f, 0);
		glVertex3f(0, 0.031f, 0);
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
	float fowH = tan(float(fov * DegreeToRadians / 2.0f)) * zNear;
	float fowW = fowH * aspect;
	glFrustum(-fowW, fowW, -fowH, fowH, zNear, zFar);
}

void FpsGame::UpdateCamera() const
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Set up, down rotation
	glRotatef(Yrotation, 1, 0, 0);
	// Set lef, right rotation
	glRotatef(Xrotation, 0, 1, 0);
	// Set default viewport
	glRotatef(-90, 1, 0, 0);
	xDelta = 0;
	yDelta = 0;
	glTranslatef(movement.x, movement.y, -2);
}

void FpsGame::Input()
{
	if (leftPressed)
		CalculateMovement(Xrotation-90);
	else if (rightPressed)
		CalculateMovement(Xrotation+90);
	else if (upPressed)
		CalculateMovement(Xrotation);
	else if (downPressed)
		CalculateMovement(Xrotation+180);
	Xrotation -= xDelta * RotationSpeed;
	Yrotation -= yDelta * RotationSpeed;
	if (Yrotation < -90)
		Yrotation = -90;
	if (Yrotation > 70)
		Yrotation = 70;
}

void FpsGame::CalculateMovement(float angle)
{
	movement.x-=sin(angle * DegreeToRadians) * MovementSpeed * timeThisTick;
	movement.y-=cos(angle * DegreeToRadians) * MovementSpeed * timeThisTick;
}
