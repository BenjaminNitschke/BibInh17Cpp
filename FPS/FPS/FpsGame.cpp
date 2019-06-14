#include "stdafx.h"
#include "FpsGame.h"
#include "VertexPositionUV.h"
#include <vector>
#include "Shader.h"

FpsGame::FpsGame(int width, int height, const char* name) : Game(width, height, name)
{
	int levelWidth = 10;
	int levelHeight = 10;

	AddQuad(&groundVertices, -levelWidth / 2, -levelHeight / 2, 0, levelWidth, levelHeight, 10);

	AddBox(0, 0);

	waveAndBlur = std::make_shared<Shader>(
		// Vertex Shader
		"#version 330\n"
		"in vec4 vertexposition_modelspace;\n"
		"in vec2 tex_coord;\n"
		"out vec3 vertex;\n"
		"out vec2 uv;\n"
		"uniform mat4 worldViewPerspective;\n"
		"uniform float time;\n"
		"void main()"
		"{"
		"  vec4 pos = vertexposition_modelspace;"
		"  pos.z += sin(time + pos.x / 7.0 + pos.y / 2.0);"
		"  gl_Position = worldViewPerspective * pos;"
		"  vertex = vertexposition_modelspace.xyz;"
		"  uv = tex_coord;"
		"}"
		,
		// Fragment Shader
		"#version 330\n"
		"uniform sampler2D diffuse;\n"
		"uniform vec2 res;\n"
		"uniform float radius;\n"
		"in vec2 uv;\n"
		"in vec3 vertex;\n"
		"out vec4 color;"
		"void main()"
		"{"
		"  float right_bound = res.x * radius;"
		"  float upper_bound = res.y * radius;"
		"  float count = 0;"

		"  for(float x = -right_bound; x < right_bound; x += res.x) {"
		"    for(float y = -upper_bound; y < upper_bound; y += res.y) {"
		"      color += texture(diffuse, vec2(uv.x + x, uv.y + y));"
		"      count++;"
		"    }"
		"  }"

		"  color /= count;"
		"  color = texture(diffuse, vec2(uv.x, uv.y));"
		"  color.z = 1;"
		"}");

	normal = std::make_shared<Shader>(
		// Vertex Shader
		"#version 330\n"
		"layout(location = 0) in vec4 vertexposition_modelspace;\n"
		"layout(location = 1) in vec2 tex_coord;\n"
		"layout(location = 2) in vec3 normal;\n"
		"uniform mat4 worldViewPerspective;\n"
		"uniform vec3 lightDirection;\n"
		"out vec2 uv;\n"
		"out float brightness;\n"
		"void main()"
		"{"
		"  brightness = dot(lightDirection, normal);"
		"  uv = tex_coord;"
		"  gl_Position = worldViewPerspective * vertexposition_modelspace;"
		"}"
		,
		// Fragment Shader
		"#version 330\n"
		"in vec2 uv;\n"
		"in vec3 vertex;\n"
		"in float brightness;\n"
		"uniform sampler2D diffuse;\n"
		"out vec4 color;"
		"void main()"
		"{"
		"  color = texture(diffuse, vec2(uv.x, uv.y)) * brightness;"
		"}");

	texture = std::make_shared<Shader>(
		// Vertex Shader
		"#version 330\n"
		"uniform mat4 worldViewPerspective;\n"
		"in vec4 vertexposition_modelspace;\n"
		"in vec2 tex_coord;\n"
		"out vec2 uv;\n"
		"void main()"
		"{"
		"  gl_Position = worldViewPerspective * vertexposition_modelspace;"
		"  uv = tex_coord;"
		"}"
		,
		// Fragment Shader
		"#version 330\n"
		"uniform sampler2D diffuse;\n"
		"in vec2 uv;\n"
		"in vec3 vertex;\n"
		"out vec4 color;"
		"void main()"
		"{"
		"  color = texture(diffuse, vec2(uv.x, uv.y));"
		"}");



	glEnable(GL_TEXTURE_2D);
}

void FpsGame::AddQuad(std::vector<VertexPositionUV>* cache, float x, float y, float z, float width, float depth, int resolution)
{
	auto spacingX = width / resolution;
	auto spacingY = depth / resolution;
	auto spacingUV = 1.0f / resolution;

	for (int i = 0; i < resolution; i++)
	{
		for (int j = 0; j < resolution; j++)
		{
			cache->push_back(VertexPositionUV((i + 1) * spacingX - width / 2, (j + 1) * spacingY - depth / 2, z, (i + 1) * spacingUV, (j + 1) * spacingUV));
			cache->push_back(VertexPositionUV(i * spacingX - width / 2, (j + 1) * spacingY - depth / 2, z, i * spacingUV, (j + 1) * spacingUV));
			cache->push_back(VertexPositionUV(i * spacingX - width / 2, j * spacingY - depth / 2, z, i * spacingUV, j * spacingUV));
			cache->push_back(VertexPositionUV((i + 1) * spacingX - depth / 2, j * spacingY - depth / 2, z, (i + 1) * spacingUV, j * spacingUV));
		}
	}
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


void FpsGame::RunGame()
{
	SetupProjection();

	Run([=]()
		{
			Input();
			SetupProjection();
			UpdateCamera();

			// tell openGL it will work with a texture
			/*DrawVertices(ground->texture, groundVertices);
			DrawVertices(wall->texture, wallVertices);*/

			// put camera back into 2d
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glDisable(GL_TEXTURE_2D);

			DrawVertices(wallVertices, texture, wall->texture,nullptr);
			DrawVertices(groundVertices, normal, ground->texture, nullptr);

			glEnable(GL_TEXTURE_2D);
		});
}

void FpsGame::DrawVertices(std::vector<VertexPositionUV> vertices, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> diffuse, std::shared_ptr<Texture> normal)
{
	shader->Use();
	glEnable(GL_TEXTURE_2D);

	auto matrixLocation = glGetUniformLocation(shader->program, "worldViewPerspective");
	glUniformMatrix4fv(matrixLocation, 1, false, (projection * view).m);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, diffuse->handle);
	auto textureLocation = glGetUniformLocation(shader->program, "diffuse");
	glUniform1i(textureLocation, 0);

	//blur and wave
	//auto resolutionLocation = glGetUniformLocation(shader->program, "res");
	//glUniform2f(resolutionLocation, 1.0f / diffuse->width, 1.0f / diffuse->height);

	//auto radiusLocation = glGetUniformLocation(shader->program, "radius");
	//glUniform1f(radiusLocation, 0);

	//auto timeLocation = glGetUniformLocation(shader->program, "time");
	//glUniform1f(timeLocation, time);

	//normal map
	auto lightDirectionLocation = glGetUniformLocation(shader->program, "lightDirection");
	glUniform3f(lightDirectionLocation, lightDirection.x, lightDirection.y, lightDirection.z);

	unsigned int vertexBuffer;

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof VertexPositionUV * vertices.size(), vertices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glGetAttribLocation(shader->program, "vertexposition_modelspace");
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof VertexPositionUV, (void*)0);

	glEnableVertexAttribArray(1);
	glGetAttribLocation(shader->program, "tex_coord");
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof VertexPositionUV, (void*)sizeof Vector3);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
	glDrawArrays(GL_QUADS, 0, vertices.size());
	glDisableVertexAttribArray(0);
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

	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)projection.m);
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

	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)view.m);
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
