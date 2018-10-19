#pragma once
#include <GL/gl.h>

class Texture
{
public:
	GLuint handle;
	Texture(const char* file_name);
	~Texture();
	void Draw();
private:
	int width, height;
	GLuint Load(const char* file_name, int* width, int* height);
};
