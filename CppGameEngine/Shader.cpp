#include "stdafx.h"
#include "Shader.h"
#include <cstdio>

Shader::Shader(const char* vertexShader, const char* fragmentShader)
{
	program = glCreateProgram();

	glAttachShader(program, CreateShader(GL_VERTEX_SHADER, vertexShader));
	glAttachShader(program, CreateShader(GL_FRAGMENT_SHADER, fragmentShader));
	
	glLinkProgram(program);
	auto err = glGetError();

	if (err != GL_NO_ERROR)
	{
		throw err;
	}
}

GLuint Shader::CreateShader(GLuint type, const char * &shaderCode)
{
	GLuint shader = glCreateShader(type);

	glShaderSource(shader, 1, &shaderCode, nullptr);
	glCompileShader(shader);

	GLint shaderCompiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderCompiled);

	if(shaderCompiled == GL_FALSE)
	{
		char buffer[1000];
		int length;
		glGetShaderInfoLog(shader, 1000, &length, buffer);
		printf(buffer);
		throw buffer;
	}

	return shader;
}

Shader::~Shader()
{
}

void Shader::Use()
{
	glUseProgram(program);
}
