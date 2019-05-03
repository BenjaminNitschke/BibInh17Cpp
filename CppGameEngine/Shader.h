#pragma once
#include "../glew-2.1.0/include/GL/glew.h"
#include <GL/gl.h>

class Shader
{
public:
	Shader(const char* vertexShader, const char* fragmentShader);
	void CreateShader(GLuint type, const char * &vertexShaderCode);
	void Use();
private:
	GLuint program;
	//TODO?
};
