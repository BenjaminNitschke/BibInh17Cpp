#pragma once
#include <string>

struct Vector3
{
	float x, y, z;

	Vector3(float x, float y, float z = 0);
	Vector3();
	~Vector3();
	
	Vector3 operator +=(const Vector3& v2) const;
	Vector3 operator +(Vector3& v2) const;
	Vector3 operator -(Vector3& v2) const;
	Vector3 operator -() const;
	Vector3 operator *(float scalar) const;
	Vector3 operator /(float scalar) const;

	float SquareMagnitude() const;
	float Magnitude() const;
	Vector3 UnitVector() const;
	float DotProduct(Vector3& v2) const;
	Vector3 CrossProduct(Vector3& v2) const;
	float Distance(Vector3& v2) const;

	std::string ToString() const;
	bool Equals(Vector3& v2) const;
};
