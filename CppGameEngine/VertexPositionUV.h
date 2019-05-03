#pragma once
#include <GL/gl.h>

struct VertexPositionUV
{
	float x, y, z;
	float u, v;

	VertexPositionUV() { x = y = z = u = v = 0; }

	VertexPositionUV(const float& x, const float& y, const float& z, const float& u, const float& v): x(x), y(y), z(z), u(u), v(v) {}

	void Draw()
	{
		glTexCoord2f(u, v);
		glVertex3f(x, y, z);
	}
};