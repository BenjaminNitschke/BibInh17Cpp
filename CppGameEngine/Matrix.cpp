#include "stdafx.h"
#include "Matrix.h"

Matrix::Matrix()
{
	values[0] = 1;
	values[5] = 1;
	values[10] = 1;
	values[15] = 1;
}

Matrix::Matrix(const Matrix &m)
{
	values = m.values;
}

Matrix::Matrix(float v00, float v01, float v02, float v03, float v10, float v11, float v12, float v13, float v20, float v21, float v22, float v23, float v30, float v31, float v32, float v33)
{
	SetValue(0, 0, v00);
	SetValue(1, 0, v01);
	SetValue(2, 0, v02);
	SetValue(3, 0, v03);

	SetValue(0, 1, v10);
	SetValue(1, 1, v11);
	SetValue(2, 1, v12);
	SetValue(3, 1, v13);

	SetValue(0, 2, v20);
	SetValue(1, 2, v21);
	SetValue(2, 2, v22);
	SetValue(3, 2, v23);

	SetValue(0, 3, v30);
	SetValue(1, 3, v31);
	SetValue(2, 3, v32);
	SetValue(3, 3, v33);
}

Matrix::~Matrix()
{
	delete values;
}

Matrix Matrix::Scale(Vector3 scaler)
{
	Matrix m = Matrix();

	m.SetValue(0, 0, scaler.x);
	m.SetValue(1, 1, scaler.y);
	m.SetValue(2, 2, scaler.z);

	return m;
}

float Matrix::GetValue(int x, int y)
{
	return values[4 * y + x];
}

void Matrix::SetValue(int x, int y, float val)
{
	values[4 * y + x] = val;
}
