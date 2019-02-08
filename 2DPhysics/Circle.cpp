#include "stdafx.h"
#include "Circle.h"
#include <memory>

void Circle::DrawCircle()
{

	//cx = centerptr->x;
	//cy = centerptr->y;
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