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
	GameObject()
	{


	}
	GameObject(float x, float y, float z, float ID, float radius)
	{

		center = std::make_shared<Vector3>(x, y, z);
		collider = std::make_shared<CircleCollider>(center, radius, ID);
		body = std::make_shared<Circle>(center, radius);

	}
	
	std::shared_ptr<CircleCollider> collider;
	std::shared_ptr<Vector3> center;
	std::shared_ptr<Vector3> p1;
	std::shared_ptr<Vector3> p2;
	std::shared_ptr<Circle> body;
	std::shared_ptr<Line> lbody;
	
	
	

	~GameObject()
	{

	}
};
