#include "stdafx.h"
#include "Vector.h"

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z)
{
	
}

Vector::~Vector()
{

}

Vector Vector::Add(Vector v2)
{
	return Vector(x + v2.x, y + v2.y, z + v2.z);
}

Vector Vector::Negate()
{
	return Vector(-x, -y, -z);
}

Vector Vector::Subtract(Vector v2)
{
	return Add(v2.Negate());
}


Vector Vector::Scale(float scaler)
{
	return Vector(x * scaler, y * scaler, z * scaler);
}

float Vector::DotProduct(Vector v2)
{
	return x * v2.x + y * v2.y + z * v2.z;
}

Vector Vector::CrossProduct(Vector v2)
{
	return Vector(
		y * v2.z - z * v2.y,
		z * v2.x - x * v2.z,
		x * v2.y - y * v2.x
	);
}
