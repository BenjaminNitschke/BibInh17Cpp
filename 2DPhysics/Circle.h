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
		theta = 2 * 3.1415926 / float(50);
		c = cosf(theta);
		s = sinf(theta);
		x = r;
		y = 0;
		
	}
	
	Circle()
	{
		
	}
	std::shared_ptr<Vector3> centerptr;
	void DrawCircle();
	float theta;
	float c;
	float s;
	float t;
	float r;
	float cx;
	float cy;
	float x ;
	float y;
	
	
	~Circle()
	{}
private:
	
	
};

