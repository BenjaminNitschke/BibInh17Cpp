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
	
	glGetFloatv(GL_PROJECTION, projection.m);
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
	
	glGetFloatv(GL_MODELVIEW, view.m);
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
	/* the hacky way
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(projection.m);
		glMultMatrixf(view.m);
		float worldViewProjectioneMatrix[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, worldViewProjectionMatrix);
		*/

	groundShader->Use();
	/*
	Matrix worldViewProjectionMatrix = projection * view;
	// Specify vertex attributes to be used (position and uv)
		glGetAttribLocation(groundShader->GetHandle(), "position");
		glGetAttribLocation(groundShader->GetHandle(), "uv");
		// Set perspective and view matrix for vertex shader to calculate pixel pos
		auto worldViewProjectionLocation = glGetUniformLocation(groundShader->GetHandle(), "worldViewProjection");
		glUniformMatrix4fv(worldViewProjectionLocation,	1, true, worldViewProjectionMatrix.m);


	glBindTexture(GL_TEXTURE_2D, texture->handle);
	/*
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof(VertexPositionUV), vertices.data());
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, sizeof(VertexPositionUV), ((BYTE*)(vertices.data()))+12);
	*/

	
glEnableVertexAttribArray(0);
glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
glVertexAttribPointer(
   0,// attribute 0. No particular reason for 0, but must match the layout in the shader.
   3,// size
   GL_FLOAT,           // type
   GL_FALSE,           // normalized?
   0,                  // stride
   (void*)0            // array buffer offset
);

	glDrawArrays(GL_QUADS, 0, 3);//vertices.size());//non indexed, just vertices, easy
	
glDisableVertexAttribArray(0);
	/*glDisableClientState(GL_VERTEX_ARRAY);
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
		//DrawVertices(wallTexture, wallVertices);
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
	/*
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3f(-0.02f, 0, 0);
	glVertex3f(0.018f, 0, 0);
	glVertex3f(0, -0.033f, 0);
	glVertex3f(0, 0.031f, 0);
	glEnd();
	*/

	//testing shader
	groundShader->Use();
	
	Matrix worldViewProjection = Matrix();
	auto worldViewProjectionLocation = glGetUniformLocation(groundShader->GetHandle(), "worldViewProjection");
	glUniformMatrix4fv(worldViewProjectionLocation,	1, true, worldViewProjection.m);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableVertexAttribArray(0);

	glEnable(GL_TEXTURE_2D);
}
