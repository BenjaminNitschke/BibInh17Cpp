#include "stdafx.h"
#include "Line.h"

#define SCREEN_WIDTH 1280.0f
#define SCREEN_HEIGHT 720.0f

float Line::GetOpenGLX(int px) {
	int centerX = px - (int)SCREEN_WIDTH / 2;
	return (centerX / SCREEN_WIDTH)*2.0f;
}
float Line::GetOpenGLY(int py) {
	int centerY = py - (int)SCREEN_HEIGHT / 2;
	return (centerY / SCREEN_HEIGHT)*(-2.0f);
}

Line::Line()
{
	start = Point(0, 0);
	end = Point(0, 0);
}

Line::Line(Point start, Point end)
{
	this->start = start;
	this->end = end;
}


Line::~Line()
{
}

void Line::Draw()
{
	glColor4f(0, 0, 0, 0.5f);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(GetOpenGLX(start.x), GetOpenGLY(start.y));
	glVertex2f(GetOpenGLX(end.x), GetOpenGLY(end.y));
	glEnd();
	glColor4f(1, 1, 1, 1);
}

void Line::SetPoint(int point, int x, int y)
{
	if (point == 0)
	{
		start.x = x;
		start.y = y;
	}
	if (point == 1)
	{
		end.x = x;
		end.y = y;
	}
}

void Line::MovePoint(int point, int x, int y)
{
	if (point == 0)
	{
		start.x += x;
		start.y += y;
	}
	if (point == 1)
	{
		end.x += x;
		end.y += y;
	}
}
