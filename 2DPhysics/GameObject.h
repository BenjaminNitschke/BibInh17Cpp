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
	GameObject(float x, float y, float z, int ID, float radius)
	{
		
		center = std::make_shared<Vector3>(x, y, z);
		collider = std::make_shared<CircleCollider>(center, radius, ID);
		body = std::make_shared<Circle>(center, radius);

	}
	/*GameObject(float x, float y, float z, float x2, float y2, float z2, float ID, bool stati)
	{
		
		center = std::make_shared<Vector3>(x+x2/2, y+y2/2, z);
		p1 = std::make_shared<Vector3>(x, y, z);
		p1 = std::make_shared<Vector3>(x2, y2, z2);
		lcollider = std::make_shared<LineCollider>(p1,p2,  ID);
		lbody = std::make_shared<Line>(p1,p2);
		collider->stat = stati;
	}
	std::shared_ptr<LineCollider> lcollider;*/
	std::shared_ptr<CircleCollider> collider;
	std::shared_ptr<Vector3> center;
	//std::shared_ptr<Vector3> p1;
	//std::shared_ptr<Vector3> p2;
	std::shared_ptr<Circle> body;
	//std::shared_ptr<Line> lbody;
	
	
	

	~GameObject()
	{

	}
};
