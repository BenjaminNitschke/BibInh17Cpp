#include "stdafx.h"
#include "Line.h"



void Line::DrawLine()
{
	glBegin(GL_LINES);
	
	
		glVertex2f(point1->x,point1->y);
		glVertex2f(point2->x, point2->y);


	glEnd();

}

