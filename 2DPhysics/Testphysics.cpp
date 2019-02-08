#include "stdafx.h"
#include "Testphysics.h"

#include <memory>
#include <vector>
#include <algorithm>
#include "GameObject.h"

Testphysics::Testphysics()
{
	//gameobject = 
	
	

}

Testphysics::~Testphysics()
{
}

void Testphysics::RunTestphysics()
{
	Run([=]()
	{
		bodyy = std::make_shared<Circle>(0, 0, 0.1);
		bodyy->DrawCircle();
	});
}




void Testphysics::DrawAll()
{
	float theta = 2 * 3.1415926 / float(50);
	float c = cosf(theta);
	float s = sinf(theta);
	float t;
	float r=0.1;
	float cx = 0;
	float cy = 0;
	float x = r;
	float y = 0;
	
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