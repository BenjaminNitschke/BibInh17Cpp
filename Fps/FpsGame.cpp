#include "stdafx.h"
#include "FpsGame.h"
#include "Sprite.h"
#include "VertexPositionUV.h"

FpsGame::FpsGame() : Game(1280, 720, "Fps")
{
	groundTexture = std::make_shared<Texture>("Ground.png");
	float levelWidth = 20;
	float levelHeight = 20;
	groundVertices.push_back(VertexPositionUV(levelWidth, levelHeight, 0.0f, levelWidth/2, levelHeight/2));
	groundVertices.push_back(VertexPositionUV(-levelWidth, levelHeight, 0.0f, 0.0f, levelHeight/2));
	groundVertices.push_back(VertexPositionUV(-levelWidth, -levelHeight, 0.0f, 0.0f, 0.0f));
	groundVertices.push_back(VertexPositionUV(levelWidth, -levelHeight, 0.0f, levelWidth/2, 0.0f));

	wallTexture = std::make_shared<Texture>("Wall.png");
	AddBox(0, 0);
	AddBox(2, 1);

	//Load shaders
	groundShader = std::make_shared<Shader>(
		// Vertex Shader
		"#version 330\n"
		"layout(location = 0) in vec4 vertexPosition_modelspace;\n"
		"layout(location = 1) in vec2 texCoord;\n"
		"uniform mat4 worldViewProjection;\n"
		"uniform float time;\n"
		"out vec2 uv;\n"
		"void main(){\n"
		"  vec4 pos = vertexPosition_modelspace;\n"
		"  pos.z += sin(time + pos.x / 7.0 + pos.y / 9.0);\n"
		"  uv = texCoord;\n"
		"  gl_Position = worldViewProjection * pos;\n"
		"}",
		// Pixel Shader
		"#version 330\n"
		"uniform sampler2D diffuse;\n"
		"uniform float time;\n"
		"in vec2 uv;\n"
		"out vec4 color;\n"
		"void main() {\n"
		"  color = texture(diffuse, uv);\n"
		"}");
	wallShader = std::make_shared<Shader>(
		// Vertex Shader
		"#version 330\n"
		"layout(location = 0) in vec4 vertexPosition_modelspace;\n"
		"layout(location = 1) in vec2 texCoord;\n"
		"uniform mat4 worldViewProjection;\n"
		"uniform float time;\n"
		"out vec2 uv;\n"
		"out float height;\n"
		"void main(){\n"
		"  vec4 pos = vertexPosition_modelspace;\n"
		"  pos.z += sin(time + pos.x / 7.0 + pos.y / 5.0 + pos.z);\n"
		"  height = pos.z;\n"
		"  uv = texCoord;\n"
		"  gl_Position = worldViewProjection * pos;\n"
		"}",
		// Pixel Shader
		"#version 330\n"
		"uniform sampler2D diffuse;\n"
		"uniform float time;\n"
		"uniform vec2 direction;\n"
		"uniform float iterations;\n"
		"in vec2 uv;\n"
		"in float height;\n"
		"out vec4 color;\n"
		"void main() {\n"
		"  //vec4 simpleColor = vec4(0.1 + height / 4.0, 0.8, 0.6, 1);\n"
		"  //color = texture(diffuse, uv) * simpleColor;\n"
		"  int count;\n"
		"  vec4 blurColor = vec4(0.0, 0.0, 0.0, 0.0);\n"
		"  for (float x = -iterations * direction.x; x < iterations * direction.x; x += direction.x){"
		"    for (float y = -iterations * direction.y; y < iterations * direction.y; y += direction.y){"
		"       blurColor += texture(diffuse, vec2(uv.x + x, uv.y + y));\n"
		"       count++;\n"
		"    }"
		"  }"
		"blurColor = blurColor / count;"
		"color = blurColor;\n"
		"}");
/*
Vector3 data[] = {
  Vector3(-1.0f, -1.0f, 0.0f),
  Vector3(1.0f, -1.0f, 0.0f),
  Vector3(1.0f,  1.0f, 0.0f),
  Vector3(-1.0f,  1.0f, 0.0f),
};
glGenBuffers(1, &vertexbuffer);
glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
glBufferData(GL_ARRAY_BUFFER, sizeof(Vector3)*std::size(data), data, GL_STATIC_DRAW);

//sizeof(VertexPositionUV)*groundVertices.size(), groundVertices.data(), GL_STATIC_DRAW);
*/
		glGenBuffers(1, &groundVertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, groundVertexBuffer);
		auto sizeInBytes = sizeof(VertexPositionUV)*std::size(groundVertices);
		glBufferData(GL_ARRAY_BUFFER, sizeInBytes, groundVertices.data(), GL_STATIC_DRAW);

		glGenBuffers(1, &wallVertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, wallVertexBuffer);
		sizeInBytes = sizeof(VertexPositionUV)*std::size(wallVertices);
		glBufferData(GL_ARRAY_BUFFER, sizeInBytes, wallVertices.data(), GL_STATIC_DRAW);

	SetupProjection();
	glEnable(GL_TEXTURE_2D);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
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
	
	glGetFloatv(GL_PROJECTION_MATRIX, projection.m);
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
	
	glGetFloatv(GL_MODELVIEW_MATRIX, view.m);
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

void FpsGame::DrawVertices(std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, int vertexBuffer, int numberOfVertices)
{
	// Step 1: Assign shader and texture
	shader->Use();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture->handle);
	// Specify vertex attributes to be used (position and uv)
	glGetAttribLocation(shader->GetHandle(), "vertexPosition_modelspace");
	glGetAttribLocation(shader->GetHandle(), "uv");
	
	// Step 2: Setup uniforms
	Matrix worldViewProjection = projection * view;
	auto worldViewProjectionLocation = glGetUniformLocation(shader->GetHandle(), "worldViewProjection");
	glUniformMatrix4fv(worldViewProjectionLocation,	1, false, worldViewProjection.m);
	auto timeLocation = glGetUniformLocation(shader->GetHandle(), "time");
	glUniform1f(timeLocation, (float)time);

	glActiveTexture(GL_TEXTURE0);
	auto diffuseLocation = glGetUniformLocation(shader->GetHandle(), "diffuse");
	glUniform1i(diffuseLocation, 0);
	auto distanceLocation = glGetUniformLocation(shader->GetHandle(), "direction");
	glUniform2f(distanceLocation, 1.0 / texture->width, 1.0 / texture->height);
	auto iterationLocation = glGetUniformLocation(shader->GetHandle(), "iterations");
	glUniform1f(iterationLocation, 10);

	// Step 4: Assign vertexbuffer and location offsets
	//glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	
		// Set Vertex Format
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexPositionUV), 0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexPositionUV), (void*)(sizeof(Vector3)));

	// Step 5: Finally render with shader and vertexbuffer
	glDrawArrays(GL_QUADS, 0, numberOfVertices);
	// Restore crap
	glDisableVertexAttribArray(0);
	glEnable(GL_TEXTURE_2D);
	glUseProgram(0);
}

void FpsGame::RunGame()
{
	Run([=]()
	{
		Input();
		SetupProjection();
		UpdateCamera();
		DrawVertices(groundShader, groundTexture, groundVertexBuffer, groundVertices.size());
		DrawVertices(wallShader, wallTexture, wallVertexBuffer, wallVertices.size());
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
}
