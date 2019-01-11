#include "stdafx.h"
#include "Vector3.h"
#include <sstream>

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
	
}

Vector3::Vector3() : x(0), y(0), z(0)
{
	
}

Vector3::~Vector3()
{

}

Vector3 Vector3::operator+=(const Vector3& v2) const
{
	return Vector3(x + v2.x, y + v2.y, z + v2.z);
}

Vector3 Vector3::operator+(Vector3& v2) const
{
	return Vector3(x + v2.x, y + v2.y, z + v2.z);
}

Vector3 Vector3::operator-(Vector3& v2) const
{
	return Vector3(x - v2.x, y - v2.y, z - v2.z);
}

Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator*(float scalar) const
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator/(float scalar) const
{
	return Vector3(x / scalar, y / scalar, z / scalar);
}

float Vector3::SquareMagnitude() const
{
	return x * x + y * y + z * z;
}

float Vector3::Magnitude() const
{
	return sqrt(SquareMagnitude());
}

Vector3 Vector3::UnitVector() const
{
	return Vector3(x / Magnitude(), y / Magnitude(), z / Magnitude());
}

float Vector3::DotProduct(Vector3& v2) const
{
	return x * v2.x + y * v2.y + z * v2.z;
}

Vector3 Vector3::CrossProduct(Vector3& v2) const
{
	return Vector3(
		y * v2.z - z * v2.y,
		z * v2.x - x * v2.z,
		x * v2.y - y * v2.x
	);
}

float Vector3::Distance(Vector3& v2) const
{
	return (*this - v2).Magnitude();
}

std::string Vector3::ToString() const
{
	std::ostringstream stream;
	stream << "(" << (x == 0 ? 0 : x) << ", " << (y == 0 ? 0 : y) << ", " << (z == 0 ? 0 : z) << ")" << "\n";
	return stream.str();
}

bool Vector3::Equals(Vector3& v2) const
{
	return x == v2.x && y == v2.y && z == v2.z;
}
