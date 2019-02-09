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
	}
	float r;
	float id;
	~CircleCollider()
	{}
};
