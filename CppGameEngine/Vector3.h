#pragma once
#include <sstream>

struct Vector3
{
public:
	Vector3(float x, float y, float z);
	Vector3 Add(const Vector3& a);
	Vector3 Negate();
	Vector3 Multiply(float s);
	float DotProduct(const Vector3& a);
	Vector3 CrossProduct(const Vector3& a);
	std::string ToString();
	float x;
	float y;
	float z;
};

