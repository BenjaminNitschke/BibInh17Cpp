#pragma once
#include "stdafx.h"
#include "Vector3.h"

struct Matrix
{
public:
	float value[4][4];

	Matrix();
	Matrix(float f00, float f01, float f02, float f03,
		float f10, float f11, float f12, float f13,
		float f20, float f21, float f22, float f23,
		float f30, float f31, float f32, float f33);
	Matrix Identity();
	Matrix Scale(const Vector3& v);
	Vector3 MultiplyWithVector3(const Vector3& v);
};

