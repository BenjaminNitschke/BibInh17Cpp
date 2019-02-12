#include "stdafx.h"
#include "Circle.h"
void Circle::DrawCircle()
{
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < 20; ii++)
	{
		glVertex2f(x + centerptr->x, y + centerptr->y);


		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();

}