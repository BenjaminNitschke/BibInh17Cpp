#pragma once
#include <GL/gl.h>

class Texture
{
public:
	int width, height;
	GLuint handle;
	Texture(const char* name);
	~Texture();
private:
	GLuint Load(const char* name, int* width, int* height);
};
