#pragma once
#include "stdafx.h"
#include <GLFW/glfw3.h>

#include <memory>
#include <vector>
#include <algorithm>
#include "Vector3.h"
class Circle
{
public:
	Circle(std::shared_ptr<Vector3>  mycenter, float radius)
	{
		centerptr = mycenter;
		r = radius;
	}
	void DrawCircle()
	{
		center = *centerptr.get();
		cx = center.x;
		cy = center.y;
		glBegin(GL_LINE_LOOP);
		for (int ii = 0; ii < 50; ii++)
		{
			glVertex2f(x + cx, y + cx);


			t = x;
			x = c * x - s * y;
			y = s * t + c * y;
		}
		glEnd();


	}
	~Circle()
	{}
private:
	float theta = 2 * 3.1415926 / float(50);
	float c = cosf(theta);
	float s = sinf(theta);
	float t;
	float r ;
	float cx ;
	float cy ;
	float x = r;
	float y = 0;
	std::shared_ptr<Vector3> centerptr;
	Vector3 center;
};

