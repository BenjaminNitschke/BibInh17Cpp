#pragma once
#include "stdafx.h"
#include "Vector3.h"
#include "CircleCollider.h"
#include <memory>
#include "Circle.h"
#include "Line.h"
class GameObject
{
public:
	std::shared_ptr<CircleCollider> collider;
	std::shared_ptr<Vector3> center;
	std::shared_ptr<Vector3> p1;
	std::shared_ptr<Vector3> p2;
	std::shared_ptr<Circle> body;
	std::shared_ptr<Line> lbody;
	
	GameObject()
	{


	}
	GameObject(float x, float y, float z, float ID,float radius)
	{
		
		center = std::make_shared<Vector3>(x, y, z);
		collider = std::make_shared<CircleCollider>(center,radius,ID);
		body= std::make_shared<Circle>(center,radius);

	}
	GameObject(float x, float y,float z, float length)
	{

		center = std::make_shared<Vector3>(x, y, z);
		p1= std::make_shared<Vector3>(center->x+(length/2), center->y, z);
		p2 = std::make_shared<Vector3>(center->x - length, center->y, z);
		
		//body = std::make_shared<Circle>(center, radius);
		lbody = std::make_shared<Line>(p1, p2);
	}
	

	~GameObject()
	{

	}
};
