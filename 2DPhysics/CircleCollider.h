#pragma once
#include "stdafx.h"
#include"Vector3.h"
#include <memory>



#include "Collider.h"


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
	CircleCollider()
	{

	}
	float r;
	float id;
	bool Collides(std::shared_ptr<CircleCollider>collider);
	bool CheckCollision(std::shared_ptr<CircleCollider>collider);
	std::shared_ptr<Vector3> center;
	
	~CircleCollider()
	{}
};
