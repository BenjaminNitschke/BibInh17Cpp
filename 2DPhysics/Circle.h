#pragma once
#include "Game.h"
#include "stdafx.h"
#include <GLFW/glfw3.h>
#include <functional>
#include <memory>
#include <vector>
#include <algorithm>
#include "Vector3.h"
#include <cstdio>
class Circle 
{
public:
	Circle(std::shared_ptr<Vector3>  mycenter, float radius)
	{
		centerptr = mycenter;
		r = radius;
	}
	Circle(float x, float y, float radius)
	{
		cx = x;
		cy = y;
		r = radius;
		r = radius;
	}
	void DrawCircle();
	float theta = 2 * 3.1415926 / float(50);
	float c = cosf(theta);
	float s = sinf(theta);
	float t;
	float r;
	float cx;
	float cy;
	float x = r;
	float y = 0;
	std::shared_ptr<Vector3> centerptr;
	~Circle()
	{}
private:
	
	
};

