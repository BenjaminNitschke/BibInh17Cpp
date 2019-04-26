#include "stdafx.h"
#include "Shader.h"

Shader::Shader(const char* vertexShader, const char* fragmentShader)
{
	program = glCreateProgram();

	GLuint shaderHandle = 0;
	glShaderSource(shaderHandle, 1, &vertexShader, nullptr);
	glCompileShader(shaderHandle);
	glLinkProgram(program);
}

Shader::~Shader()
{
}

void Shader::Use()
{
	glUseProgram(program);

}
