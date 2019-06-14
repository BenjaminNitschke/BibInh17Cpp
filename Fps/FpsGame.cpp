#include "stdafx.h"
#include "FpsGame.h"
#include "Sprite.h"
#include "VertexPositionUV.h"

FpsGame::FpsGame() : Game("Fps")
{
	groundTexture = std::make_shared<Texture>("Water.png");
	//groundVertices.push_back(VertexPositionUV(levelWidth, levelHeight, 0.0f, levelWidth / 2, levelHeight / 2));
	//groundVertices.push_back(VertexPositionUV(-levelWidth, levelHeight, 0.0f, 0.0f, levelHeight / 2));
	//groundVertices.push_back(VertexPositionUV(-levelWidth, -levelHeight, 0.0f, 0.0f, 0.0f));
	//groundVertices.push_back(VertexPositionUV(levelWidth, -levelHeight, 0.0f, levelWidth / 2, 0.0f));
	CreatePlane(16);


	wallTexture = std::make_shared<Texture>("Wall.png");
	normalTexture = std::make_shared<Texture>("NormalMap.png");
	AddBox(0, 0);
	AddBox(2, 1);

	//Load shaders
	groundShader = std::make_shared<Shader>(
		// Vertex Shader
		"#version 330\n"
		"layout(location = 0) in vec4 vertexPosition_modelspace;\n"
		"layout(location = 1) in vec3 vertexNormal;\n"
		"layout(location = 2) in vec2 texCoord;\n"
		"uniform mat4 worldViewProjection;\n"
		"uniform float time;\n"
		"uniform vec3 lightDirection;\n"
		"uniform vec2 split;\n"
		"out float height;\n"
		"out float brightness;\n"
		"out vec2 uv;\n"
		"out vec3 normal;\n"
		"void main(){\n"
		"  vec4 pos = vertexPosition_modelspace;\n"
		//	"  now done in fragment: brightness = 0.2f + 0.8f * clamp(dot(lightDirection, normal), 0, 1);\n"
		"  pos.z += sin(time+pos.x/7.0+pos.y/5.0) * 0.8;\n"
		"  uv = texCoord;\n"
		"  normal = vertexNormal;\n"
		"  gl_Position = worldViewProjection * pos;\n"
		"  height = pos.z;\n"
		"}",
		// Pixel Shader
		"#version 330\n"
		"uniform sampler2D diffuse;\n"
		"uniform float time;\n"
		"uniform vec3 lightDirection;\n"
		"in vec2 uv;\n"
		"in float brightness;\n"
		"in float height;\n"
		"in vec3 normal;\n"
		"out vec4 color;\n"
		"void main() {\n"
		"  color = texture(diffuse, uv) * (height * .5 + 1);\n"
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
		//"  pos.z += sin(time+pos.x/7.0+pos.y/5.0);\n"
		"  height = pos.z;\n"
		"  uv = texCoord;\n"
		"  gl_Position = worldViewProjection * pos;\n"
		"}",
		// Pixel Shader
		"#version 330\n"
		"uniform sampler2D diffuse;\n"
		"uniform float time;\n"
		"uniform int tile;\n"
		"uniform vec2 res;\n"
		"uniform float radius;\n"
		"in vec2 uv;\n"
		"in float height;\n"
		"out vec4 color;\n"
		"void main() {\n"
		"  float rightBound = res.x * radius;\n"
		"  float upperBound = res.y * radius;\n"
		"  float x = 0;\n"
		"  float y = 0;\n"
		"  float count = 0;\n"
		"  for (float x=-rightBound; x<rightBound; x+=res.x) {\n"
		"	 for (float y=-upperBound; y<upperBound; y+=res.y) {\n"
		"	   color += texture(diffuse, vec2(uv.x+x, uv.y+y) * tile);\n"
		"	   count++;\n"
		"	 }\n"
		"  }\n"
		"  color/=count;\n"
		//"  vec4 simpleColor = vec4(0.1+height/4.0, 0.8, 0.6, 1);\n"
		//"  color = texture(diffuse, uv * tile)*simpleColor;\n"
		"}");
	/*tst
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
	auto sizeInBytes = sizeof(VertexPositionUV) * std::size(groundVertices);
	glBufferData(GL_ARRAY_BUFFER, sizeInBytes, groundVertices.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &wallVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, wallVertexBuffer);
	sizeInBytes = sizeof(VertexPositionUV) * std::size(wallVertices);
	glBufferData(GL_ARRAY_BUFFER, sizeInBytes, wallVertices.data(), GL_STATIC_DRAW);

	SetupProjection();
	glEnable(GL_TEXTURE_2D);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void FpsGame::CreatePlane(int subdivisions)
{
	auto step = subdivisions * 2;
	auto stepWidth = levelWidth / step;
	auto stepHeight = levelHeight / step;

	for (int x = 0; x < step; x++)
	{
		for (int y = 0; y < step; y++)
		{
			groundVertices.push_back(VertexPositionUV(stepWidth * x, stepHeight * y, 0.0f, 0, 0, 1, 0, 1, 0, levelWidth / step, levelHeight / step));
			groundVertices.push_back(VertexPositionUV(stepWidth * x + stepWidth, stepHeight * y, 0.0f, 0, 0, 1, 0, 1, 0, 0.0f, levelHeight / step));
			groundVertices.push_back(VertexPositionUV(stepWidth * x + stepWidth, stepHeight * y + stepHeight, 0.0f, 0, 0, 1, 0, 1, 0, 0.0f, 0.0f));
			groundVertices.push_back(VertexPositionUV(stepWidth * x, stepHeight * y + stepHeight, 0.0f, 0, 0, 1, 0, 1, 0, levelWidth / step, 0.0f));
		}
	}

}void FpsGame::SetupProjection()
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
	movement.x -= sin(angle * DegreeToRadians) * MovementSpeed * timeThisTick;
	movement.y -= cos(angle * DegreeToRadians) * MovementSpeed * timeThisTick;
}

void FpsGame::DrawVertices(std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, int vertexBuffer, int numberOfVertices)
{
	// Step 1: Assign shader and texture
	shader->Use();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture->handle);
	// Specify vertex attributes to be used (position and uv)
	glGetAttribLocation(shader->GetHandle(), "vertexPosition_modelspace");
	glGetAttribLocation(shader->GetHandle(), "normal");
	glGetAttribLocation(shader->GetHandle(), "tangent");
	glGetAttribLocation(shader->GetHandle(), "uv");

	// Step 2: Setup uniforms
	Matrix worldViewProjection = projection * view;
	auto worldViewProjectionLocation = glGetUniformLocation(shader->GetHandle(), "worldViewProjection");
	glUniformMatrix4fv(worldViewProjectionLocation, 1, false, worldViewProjection.m);
	auto timeLocation = glGetUniformLocation(shader->GetHandle(), "time");
	glUniform1f(timeLocation, (float)time);
	auto lightDirectionLocation = glGetUniformLocation(shader->GetHandle(), "lightDirection");
	glUniform3f(lightDirectionLocation, lightDirection.x, lightDirection.y, lightDirection.z);
	auto tileLocation = glGetUniformLocation(shader->GetHandle(), "tile");
	glUniform1i(tileLocation, 1);

	glActiveTexture(GL_TEXTURE0);
	auto diffuseLocation = glGetUniformLocation(shader->GetHandle(), "diffuse");
	glUniform1i(diffuseLocation, 0);

	glActiveTexture(GL_TEXTURE0);
	auto textureLocation = glGetUniformLocation(shader->GetHandle(), "res");
	glUniform2f(textureLocation, 1.0f / wallTexture->width, 1.0f / wallTexture->height);

	glActiveTexture(GL_TEXTURE0);
	auto radiusLocation = glGetUniformLocation(shader->GetHandle(), "radius");
	glUniform1f(radiusLocation, 10);

	glActiveTexture(GL_TEXTURE0);
	auto resXLocation = glGetUniformLocation(shader->GetHandle(), "resX");
	glUniform1f(resXLocation, 1.0f / groundTexture->width);

	// Step 4: Assign vertexbuffer and location offsets
	//glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	// Set Vertex Format
	glEnableVertexAttribArray(0);
	// Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexPositionUV), 0);
	glEnableVertexAttribArray(1);
	// Normal
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, sizeof(VertexPositionUV), (void*)(3 * 4));
	glEnableVertexAttribArray(2);
	// Tangent
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE, sizeof(VertexPositionUV), (void*)(6 * 4));
	glEnableVertexAttribArray(3);
	// UV
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(VertexPositionUV), (void*)(9 * 4));

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