#pragma once
#include "../../glew-2.1.0/include/GL/glew.h"

class Shader
{
public:
	Shader(const char *vertexShader, const char *fragmentShader);
	GLuint CreateShader(GLuint type, const char*& ShaderCode);

	~Shader();
	GLuint program;

	void Use();
	
};
