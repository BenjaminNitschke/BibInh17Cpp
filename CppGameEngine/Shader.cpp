#include "stdafx.h"
#include "Shader.h"

Shader::Shader(const char* vertexShaderCode, const char* fragmentShaderCode)
{
	program = glCreateProgram();
	CreateShader(GL_VERTEX_SHADER, vertexShaderCode);
	CreateShader(GL_FRAGMENT_SHADER, fragmentShaderCode);
	glBindAttribLocation(program, 0, "in_Position");
	glLinkProgram(program);
	
		char buffer[1000];
		int length;
		glGetProgramInfoLog(program, 1000, &length, buffer);
		printf(buffer);

	auto error = glGetError();
	if (error != GL_NO_ERROR)
		throw error;
}

void Shader::CreateShader(GLuint type, const char * &vertexOrFragmentShaderCode)
{
	GLuint vertexOrFragmentShader = glCreateShader(type);
	glShaderSource(vertexOrFragmentShader, 1, &vertexOrFragmentShaderCode, NULL);
	glCompileShader(vertexOrFragmentShader);
	GLint status;
	glGetShaderiv(vertexOrFragmentShader, GL_COMPILE_STATUS, &status);
	if (status == false)
	{
		char buffer[1000];
		int length;
		glGetShaderInfoLog(vertexOrFragmentShader, 1000, &length, buffer);
		printf(buffer);
		throw buffer;
	}
}

void Shader::Use()
{
	glUseProgram(program);
}