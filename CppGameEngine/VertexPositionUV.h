#pragma once
#include <GL/gl.h>

struct VertexPositionUV
{
	float x, y, z;
	float nx, ny, nz;
	float tx, ty, tz;
	float u, v;

	VertexPositionUV() { x = y = z = nx = ny = nz = tx = ty = tz = u = v = 0; }

	VertexPositionUV(const float& x, const float& y, const float& z, const float& nx, const float& ny, const float& nz, const float& tx, const float& ty, const float& tz, const float& u, const float& v) : x(x), y(y), z(z), nx(nx), ny(ny), nz(nz), tx(tx), ty(ty), tz(tz), u(u), v(v) {}
};