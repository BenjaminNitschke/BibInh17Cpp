#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix::Matrix(float f00, float f01, float f02, float f03, float f10, float f11, float f12, float f13, float f20, float f21, float f22, float f23, float f30, float f31, float f32, float f33)
{
	value[0][0] = f00;
	value[0][1] = f01;
	value[0][2] = f02;
	value[0][3] = f03;

	value[1][0] = f10;
	value[1][1] = f11;
	value[1][2] = f12;
	value[1][3] = f13;

	value[2][0] = f20;
	value[2][1] = f21;
	value[2][2] = f22;
	value[2][3] = f23;

	value[3][0] = f30;
	value[3][1] = f31;
	value[3][2] = f32;
	value[3][3] = f33;
}

Matrix Matrix::Identity()
{
	return Matrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

Matrix Matrix::Scale(const Vector3& v)
{
	return Matrix(value[0][0] * v.x, value[0][1] * v.x, value[0][2] * v.x, value[0][3], 
				  value[1][0] * v.y, value[1][1] * v.y, value[1][2] * v.y, value[1][3],
				  value[2][0] * v.z, value[2][1] * v.z, value[2][2] * v.z, value[2][3],
				  value[3][0], value[3][1], value[3][2], value[3][3]);
}

Vector3 Matrix::MultiplyWithVector3(const Vector3& v)
{
	//TODO:
	return Vector3(0,0,0);
}