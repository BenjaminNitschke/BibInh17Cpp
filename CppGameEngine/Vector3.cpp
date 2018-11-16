#include "stdafx.h"
#include "Vector3.h"


Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
}

Vector3 Vector3::Add(Vector3 a)
{
	return Vector3(this->x + a.x, this->y + a.y, this->z + a.z);
}

Vector3 Vector3::Negate()
{
	return Vector3(-this->x, -this->y, -this->z);
}

Vector3 Vector3::Multiply(float s)
{
	return Vector3(s * this->x, s * this->y, s * this->z);
}

float Vector3::DotProduct(Vector3 a)
{
	return (this->x * a.x) + (this->y * a.y) + (this->z * a.z);
}

Vector3 Vector3::CrossProduct(Vector3 a)
{
	float newX = (this->y * a.z) + (this->z * a.y);
	float newY = (this->z * a.x) + (this->x * a.z);
	float newZ = (this->x * a.y) + (this->y * a.x);
	return Vector3(newX, newY, newZ);
}
