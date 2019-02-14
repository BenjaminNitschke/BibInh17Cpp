#pragma once
#include "stdafx.h"
#include"Vector3.h"
#include <memory>
#include "LineCollider.h"


#include "Collider.h"


class CircleCollider : public Collider
{
public:
	CircleCollider(std::shared_ptr<Vector3>  mycenter,float radius,float ID)
	{
		center = mycenter;
		id = ID;
		r = radius;
		mass = r * 2;
	}
	CircleCollider()
	{

	}
	float r;
	float id;
	bool Collides(std::shared_ptr<CircleCollider>collider);
	bool CheckCollision(std::shared_ptr<CircleCollider>collider);
	bool CheckCollision(std::shared_ptr<LineCollider>collider);
	std::shared_ptr<Vector3> center;
	bool Collides(std::shared_ptr<Vector3>collider);
	float Distance(float x, float y, float x2, float y2);
	~CircleCollider()
	{}
};
