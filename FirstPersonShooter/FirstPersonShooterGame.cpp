#include "stdafx.h"
#include "FirstPersonShooterGame.h"
#include "Sprite.h"
#include "VertexPositionUV.h"


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

void FirstPersonShooterGame::DrawVertices(std::shared_ptr<Texture> texture, std::vector<VertexPositionUV> vertices)
{
	glBindTexture(GL_TEXTURE_2D, texture->handle);
	glBegin(GL_QUADS);
	for (auto vertex : vertices)
		vertex.Draw();
	glEnd();
}

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
		DrawVertices(groundTexture, groundVertices);
		DrawVertices(wallTexture, wallVertices);
	});
}