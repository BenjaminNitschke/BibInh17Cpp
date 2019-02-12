#pragma once
#include "stdafx.h"
#include <memory>
#include <GLFW/glfw3.h>
#include <vector>
#include <algorithm>
#include "Vector3.h"
#include <cstdio>
class Line
{
public:
	Line(std::shared_ptr<Vector3>  p1, std::shared_ptr<Vector3> p2)
	{
		point1 = p1;
		point2 = p2;
	}
	void DrawLine();
	std::shared_ptr<Vector3> point1;
	std::shared_ptr<Vector3> point2;
	~Line()
	{}
};

