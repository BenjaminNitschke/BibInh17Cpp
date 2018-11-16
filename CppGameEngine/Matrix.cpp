#include "stdafx.h"
#include "Matrix.h"

Matrix::Matrix()
{
	values[0] = 1;
	values[5] = 1;
	values[10] = 1;
	values[15] = 1;
}

Matrix::Matrix(Matrix &m)
{
	values = m.values;
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
	return values[4 * x + y];
}

void Matrix::SetValue(int x, int y, float val)
{
	values[4 * x + y] = val;
}
