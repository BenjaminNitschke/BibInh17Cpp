#pragma once
#include "Vector3.h"

struct Matrix
{
	Matrix();
	Matrix(Matrix &m);
	~Matrix();

	Matrix Scale(Vector3 scaler);

private:
	float* values = new float[16]{0};

	float GetValue(int x, int y);
	void SetValue(int x, int y, float val);
};
