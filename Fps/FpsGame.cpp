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
	glRotatef(Yrotation, 1, 0, 0);
	glRotatef(Xrotation, 0, 1, 0);
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

void FpsGame::DrawVertices(std::shared_ptr<Texture> texture, std::vector<VertexPositionUV> vertices)
{
	glBindTexture(GL_TEXTURE_2D, texture->handle);
	groundShader->Use();
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof(VertexPositionUV), vertices.data());
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, sizeof(VertexPositionUV), ((BYTE*)(vertices.data()))+12);
	glDrawArrays(GL_QUADS, 0, vertices.size());//non indexed, just vertices, easy
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	/*old
	glBegin(GL_QUADS);
	for (auto vertex : vertices)
		vertex.Draw();
	glEnd();
	*/
}

void FpsGame::RunGame()
{
	Run([=]()
	{
		Input();
		SetupProjection();
		UpdateCamera();
		DrawVertices(groundTexture, groundVertices);
		DrawVertices(wallTexture, wallVertices);
		DrawCrosshair();
	});
}

void FpsGame::DrawCrosshair()
{
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
	glEnable(GL_TEXTURE_2D);
}
