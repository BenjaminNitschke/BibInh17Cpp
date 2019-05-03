#include "stdafx.h"
#include "Shader.h"


Shader::Shader(const char * vertexShaderCode, const char * fragmentShaderCode)
{
	program = glCreateProgram();
	CreateShader(GL_VERTEX_SHADER, vertexShaderCode);
	CreateShader(GL_FRAGMENT_SHADER, fragmentShaderCode);
	glLinkProgram(program);
	auto error = glGetError();
	if (error != GL_NO_ERROR)
		throw error;
	//TODO: error handling
}

void Shader::Use()
{
	glUseProgram(program);
}

void Shader::CreateShader(GLuint type, const char* &vertexShaderCode)
{
	GLuint vertexShader = glCreateShader(type);
	glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
	glCompileShader(vertexShader);
	GLint status;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if (status == false)
	{
		const int bLength = 1024;
		char buffer[bLength];
		int length;
		glGetShaderInfoLog(vertexShader, bLength, &length, buffer);
		//printf(buffer);
		throw buffer;
	}
}