#pragma once
#include <sstream>

class Vector3
{
public:
	float x;
	float y;
	float z;
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
	
	Vector3 operator+(const Vector3 & other) 
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}
	Vector3 operator-(const Vector3 & other)
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}
	Vector3 operator-(Vector3 a)
	{
		return Vector3(a);
	}
	Vector3 operator*(const float scalar)
	{
		return Vector3(x * scalar, y * scalar, z * scalar);
	}
	Vector3 DotProduct(const Vector3 & other)
	{
		return Vector3(x * other.x, y * other.y, z * other.z);
	}
	Vector3 CrossProduct(const Vector3 & other)
	{
		return Vector3(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x);
	}

	std::string ToString()
	{
		std::ostringstream result;
		result << "(" << (x == 0 ? 0: x) << ", " << "(" << (y == 0 ? 0: y) << ", " << "(" << (z == 0 ? 0: z) << ")";
		return result.str();
	}
	
	~Vector3();
};