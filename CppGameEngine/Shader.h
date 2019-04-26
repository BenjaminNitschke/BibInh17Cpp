#pragma once
#include "../../glew-2.1.0/include/GL/glew.h"

class Shader
{
public:
	Shader(const char *vertexShader, const char *fragmentShader);

	~Shader();
	GLuint program;

	void Use();
	
};
