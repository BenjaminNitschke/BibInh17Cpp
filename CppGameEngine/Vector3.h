#pragma once
class Vector3
{
public:
	Vector3(float x, float y, float z);
	~Vector3();
	Vector3 Add(Vector3 a);
	Vector3 Negate();
	Vector3 Multiply(float s);
	float DotProduct(Vector3 a);
	Vector3 CrossProduct(Vector3 a);
	float x;
	float y;
	float z;
};

