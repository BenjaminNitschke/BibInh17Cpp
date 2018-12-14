#include "stdafx.h"
#include "FirstPersonShooterGame.h"
#include "Sprite.h"


void FirstPersonShooterGame::SetupProjection() 
{
	// camera fun
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float zNear = 0.1f;
	float zFar = 100.0f;
	GLfloat aspect = viewportWidth / (float)viewportHeight;
	float fov = 60.0f;
	float fovH = tan(float(fov * DegreeToRadians / 2.0f)) * zNear;
	float fovW = fovH * aspect;
	glFrustum(-fovW, fovW, -fovH, fovH, zNear, zFar);
}

//void FirstPersonShooterGame::glfwGetCursorPos(GLFW window, double* xPos, double* yPos)
//{
//
//}

void FirstPersonShooterGame::UpdateCamera()
{
	auto MovementSpeed = 0.023f;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-90, 1, 0, 0);
	if (aPressed)
	{
		//rotation -= 0.4f;
		movement.x += -sin((rotation - 90.0f) *DegreeToRadians) * MovementSpeed;
		movement.y += -cos((rotation - 90.0f) *DegreeToRadians) * MovementSpeed;
	}
	else if (dPressed)
	{
		//rotation += 0.4f;
		movement.x += -sin((rotation + 90.0f) *DegreeToRadians) * MovementSpeed;
		movement.y += -cos((rotation + 90.0f) *DegreeToRadians) * MovementSpeed;
	}
	glRotatef(rotation, 0, 0, 1);
	if (wPressed)
	{
		movement.x += -sin(rotation*DegreeToRadians) * MovementSpeed;
		movement.y += -cos(rotation*DegreeToRadians) * MovementSpeed;
	}
	else if (sPressed)
	{
		movement.x -= -sin(rotation*DegreeToRadians) * MovementSpeed;
		movement.y -= -cos(rotation*DegreeToRadians) * MovementSpeed;
	}
	glTranslatef(movement.x, movement.y, -2);
}

void FirstPersonShooterGame::RunGame()
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


		
		glBindTexture(GL_TEXTURE_2D, wallTexture->handle);
		glBegin(GL_QUADS);
		glRotatef(90, 1, 0, 0);

		glTexCoord2f(1, 1);
		glVertex3f(2, 0, 4);

		glTexCoord2f(0, 1);
		glVertex3f(-2, 0, 4);

		glTexCoord2f(0, 0);
		glVertex3f(-2, 0, 0);

		glTexCoord2f(1, 0);
		glVertex3f(2, 0, 0);

		glEnd();
	});
}