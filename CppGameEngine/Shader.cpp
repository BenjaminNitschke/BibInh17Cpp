#include "stdafx.h"
#include "Shader.h"

Shader::Shader(const char* vertexShaderCode, const char* fragmentShaderCode)
{
	//TODO: crashes, needs correct lib and dll
	program = glCreateProgram();
	CreateShader(GL_VERTEX_SHADER, vertexShaderCode);
	CreateShader(GL_FRAGMENT_SHADER, fragmentShaderCode);
	glLinkProgram(program);
	//TODO: error handling
}

void Shader::CreateShader(GLuint type, const char * &vertexShaderCode)
{
	GLuint vertexShader = glCreateShader(type);
	glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
	glCompileShader(vertexShader);
}

void Shader::Use()
{
	glUseProgram(program);
}