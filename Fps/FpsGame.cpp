#include "stdafx.h"
#include "FpsGame.h"
#include "Sprite.h"
#include "VertexPositionUV.h"

void FpsGame::SetupProjection()
{
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

void FpsGame::UpdateCamera()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-90, 1, 0, 0);
	if (leftPressed)
		rotation -= 0.4f;
	else if (rightPressed)
		rotation += 0.4f;
	glRotatef(rotation, 0, 0, 1);
	if (spacePressed){
		auto MovementSpeed = 0.023f;
		movement.x += -sin(rotation*DegreeToRadians) * MovementSpeed;
		movement.y += -cos(rotation*DegreeToRadians) * MovementSpeed;
	}
	glTranslatef(movement.x, movement.y, -2);
}

void FpsGame::DrawVertices(std::shared_ptr<Texture> texture, std::vector<VertexPositionUV> vertices)
{
	glBindTexture(GL_TEXTURE_2D, texture->handle);
	glBegin(GL_QUADS);
	for (auto vertex : vertices)
		vertex.Draw();
	glEnd();
}

void FpsGame::RunGame()
{
	Run([=]()
	{
		UpdateCamera();
		DrawVertices(groundTexture, groundVertices);
		DrawVertices(wallTexture, wallVertices);
	});
}