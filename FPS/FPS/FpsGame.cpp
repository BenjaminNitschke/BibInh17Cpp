#include "stdafx.h"
#include "FpsGame.h"
#include "VertexPositionUV.h"
#include <vector>
#include "Shader.h"

FpsGame::FpsGame(int width, int height, const char* name) : Game(width, height, name)
{
	int levelWidth = 10;
	int levelHeight = 10;

	AddQuad(&groundVertices, -levelWidth / 2, -levelHeight / 2, 0, levelWidth, levelHeight);

	AddBox(0, 0);

	// Load Shader
	groundShader = std::make_shared<Shader>(
		// Vertex Shader
		"#version 330\n"
		"layout(location = 0) in vec3 vertexposition_modelspace;\n"
		"void main()"
		"{"
		"  gl_Position.xyz = vertexposition_modelspace.xyz;"
		"  gl_Position.w = 1.0;"
		"}"
		,
		// Fragment Shader
		"#version 330\n"
		"out vec3 color;"
		"void main()"
		"{"
		"  color = vec3(1.0, 0.0, 0.0);"
		"}");

	glEnable(GL_TEXTURE_2D);
}

void FpsGame::AddQuad(std::vector<VertexPositionUV>* cache, float x, float y, float z, float width, float depth)
{
	cache->push_back(VertexPositionUV(x + width, y + depth, z, width / 2, depth / 2));
	cache->push_back(VertexPositionUV(x, y + depth, 0, 0, depth / 2));
	cache->push_back(VertexPositionUV(x, y, 0, 0, 0));
	cache->push_back(VertexPositionUV(x + width, y, 0, width / 2, 0));
}

void FpsGame::AddBox(int x, int y)
{
	int size = 4;
	int x0 = x * size;
	int x1 = (x + 1) * size;
	int y0 = y * size;
	int y1 = (y + 1) * size;
	int z0 = 0;
	int z1 = size;
	wallVertices.push_back(VertexPositionUV(x1, y0, z1, 1, 1));
	wallVertices.push_back(VertexPositionUV(x0, y0, z1, 0, 1));
	wallVertices.push_back(VertexPositionUV(x0, y0, z0, 0, 0));
	wallVertices.push_back(VertexPositionUV(x1, y0, z0, 1, 0));

	wallVertices.push_back(VertexPositionUV(x0, y0, z1, 1, 1));
	wallVertices.push_back(VertexPositionUV(x0, y1, z1, 0, 1));
	wallVertices.push_back(VertexPositionUV(x0, y1, z0, 0, 0));
	wallVertices.push_back(VertexPositionUV(x0, y0, z0, 1, 0));

	wallVertices.push_back(VertexPositionUV(x1, y1, z1, 1, 1));
	wallVertices.push_back(VertexPositionUV(x0, y1, z1, 0, 1));
	wallVertices.push_back(VertexPositionUV(x0, y1, z0, 0, 0));
	wallVertices.push_back(VertexPositionUV(x1, y1, z0, 1, 0));

	wallVertices.push_back(VertexPositionUV(x1, y0, z1, 1, 1));
	wallVertices.push_back(VertexPositionUV(x1, y1, z1, 0, 1));
	wallVertices.push_back(VertexPositionUV(x1, y1, z0, 0, 0));
	wallVertices.push_back(VertexPositionUV(x1, y0, z0, 1, 0));
}

FpsGame::~FpsGame()
{
}

void FpsGame::DrawVertices(const std::shared_ptr<Texture> texture, std::vector<VertexPositionUV> vertices)
{
	glBindTexture(GL_TEXTURE_2D, texture->handle);
	/*glBegin(GL_QUADS);
	//for (auto vertex : vertices)
		vertex.Draw();
*/

	groundShader->Use();

	Matrix viewPerspectiveMatrix = view * projection;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(VertexPositionUV), vertices.data());
	glTexCoordPointer(2, GL_FLOAT, sizeof(VertexPositionUV), reinterpret_cast<BYTE*>(vertices.data()) + 12);

	glDrawArrays(GL_QUADS, 0, vertices.size());

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
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
			DrawVertices(ground->texture, groundVertices);
			DrawVertices(wall->texture, wallVertices);

			// put camera back into 2d
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glDisable(GL_TEXTURE_2D);
			/*glBegin(GL_LINES);
			glColor3f(1, 1, 1);
			glVertex3f(-0.02f, 0, 0);
			glVertex3f(0.018f, 0, 0);
			glVertex3f(0, -0.033f, 0);
			glVertex3f(0, 0.031f, 0);
			glEnd();*/

			groundShader->Use();

			unsigned int vertexBuffer;

			Vector3 data[] = { Vector3(-1,-1,0), Vector3(1,-1,0), Vector3(0,1,0) };
			glGenBuffers(1, &vertexBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof data, data, GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glDisableVertexAttribArray(0);

			glEnable(GL_TEXTURE_2D);
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

	glGetFloatv(GL_PROJECTION, (GLfloat*)projection.m);
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

	glGetFloatv(GL_MODELVIEW, (GLfloat*)view.m);
}

void FpsGame::Input()
{
	if (leftPressed)
		CalculateMovement(Xrotation - 90);
	else if (rightPressed)
		CalculateMovement(Xrotation + 90);
	else if (upPressed)
		CalculateMovement(Xrotation);
	else if (downPressed)
		CalculateMovement(Xrotation + 180);
	Xrotation -= xDelta * RotationSpeed;
	Yrotation -= yDelta * RotationSpeed;
	if (Yrotation < -90)
		Yrotation = -90;
	if (Yrotation > 70)
		Yrotation = 70;
}

void FpsGame::CalculateMovement(float angle)
{
	movement.x -= static_cast<double>(sin(angle * DegreeToRadians)) * MovementSpeed * timeThisTick;
	movement.y -= static_cast<double>(cos(angle * DegreeToRadians)) * MovementSpeed * timeThisTick;
}
