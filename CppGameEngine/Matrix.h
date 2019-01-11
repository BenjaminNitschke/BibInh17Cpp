#pragma once
#include "Vector3.h"

struct Matrix
{
	Matrix();
	Matrix(const Matrix &m);
	Matrix(float v00, float v01, float v02, float v03, float v10, float v11, float v12, float v13, float v20, float v21, float v22, float v23, float v30, float v31, float v32, float v33);
	~Matrix();

	Matrix Scale(Vector3 scaler);
	
private:
	float* values = new float[16]{0};

	float GetValue(int x, int y);
	void SetValue(int x, int y, float val);
};
