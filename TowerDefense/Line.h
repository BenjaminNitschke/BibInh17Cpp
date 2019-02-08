#pragma once
#include "Point.h"
#include "Sprite.h"
class Line
{
public:
	Line();
	Line(Point start, Point end);
	~Line();
	Point start;
	Point end;
	void Draw(float r, float g, float b, float a);
	void SetPoint(int point, int x, int y);
	void MovePoint(int point, int x, int y);
private:
	float GetOpenGLX(int px);
	float GetOpenGLY(int py);
};