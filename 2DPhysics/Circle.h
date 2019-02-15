#pragma once

#include "stdafx.h"
#include <memory>
#include <GLFW/glfw3.h>
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
		theta = 2 * 3.141592f / 20.0f;
		c = cosf(theta);
		s = sinf(theta);
		x = r;
		y = 0;
		
	}
	
	Circle()
	{
		
	}
	
	void DrawCircle();
	
	
	~Circle()
	{}
private:
	std::shared_ptr<Vector3> centerptr;
	float theta;
	float c;
	float s;
	float t;
	float r;
	float x;
	float y;

	
};

