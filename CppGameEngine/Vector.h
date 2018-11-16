#pragma once

class Vector
{
public:
	float x, y, z;

	Vector(float x, float y, float z);
	~Vector();
	
	Vector Add(Vector v2);
	Vector Subtract(Vector v2);
	Vector Negate();
	Vector Scale(float scaler);
	float DotProduct(Vector v2);
	Vector CrossProduct(Vector v2);
};
