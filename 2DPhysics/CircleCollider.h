#pragma once
#include "Collider.h"
#include <memory>
class CircleCollider : public Collider
{
public:
	CircleCollider(std::shared_ptr<Vector3>  mycenter,float radius,float ID)
	{
		center = mycenter;
		id = ID;
		r = radius;
		mass = r * 10;
	}
	float r;
	float id;
	std::shared_ptr<Vector3> center;
	~CircleCollider()
	{}
};
