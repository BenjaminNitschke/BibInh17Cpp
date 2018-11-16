#pragma once
#include <sstream>

struct Vector3
{
	float x;
	float y;
	float z;
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
	
	Vector3 operator+(const Vector3& other)
	{
		return Vector3(x+other.x, y+other.y, z+other.z);
	}
	Vector3 operator-()
	{
		return Vector3(-x, -y, -z);
	}
	Vector3 operator-(const Vector3& other)
	{
		return Vector3(x-other.x, y-other.y, z-other.z);
	}
	Vector3 operator*(const float scalar)
	{
		return Vector3(x*scalar, y*scalar, z*scalar);
	}
	Vector3 DotProduct(const Vector3& other)
	{
		return Vector3(x*other.x, y*other.y, z*other.z);
	}
	Vector3 CrossProduct(const Vector3 other)
	{
		return Vector3(
			y * other.z - z * other.y,
			x * other.z - z * other.x,
			x * other.y - y * other.x);
	}
	float Length()
	{
		return sqrt(x*x+y*y+z*z);
	}

	std::string ToString()
	{
		std::ostringstream result;
		// Special c++ madness to avoid -0 in the output!
		// https://stackoverflow.com/a/12536877
		result << "(" << (x==0?0:x) << ", " << (y==0?0:y) << ", " << (z==0?0:z) << ")";
		return result.str();
	}
};