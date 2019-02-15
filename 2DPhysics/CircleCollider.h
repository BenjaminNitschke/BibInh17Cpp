#pragma once
#include "stdafx.h"
#include"Vector3.h"
#include <memory>
#include "LineCollider.h"


#include "Collider.h"


class CircleCollider : public Collider
{
public:
	CircleCollider(std::shared_ptr<Vector3>  mycenter,float radius,int ID)
	{
		center = mycenter;
		id = ID;
		r = radius;
		mass = r * 3;
		
	}
	CircleCollider()
	{

	}
	bool stat = false;
	float r;
	int id;
	bool Collides(std::shared_ptr<CircleCollider>collider);
	bool CheckCollisioncc(std::shared_ptr<CircleCollider>collider);
	bool CheckCollisionl(std::shared_ptr<LineCollider>collider);
	bool CheckCollisionlp(std::shared_ptr<LineCollider>collider, std::shared_ptr<Vector3> point);
	std::shared_ptr<Vector3> center;
	bool Collidesv(std::shared_ptr<Vector3>collider);
	float Distance(float x, float y, float x2, float y2);
	~CircleCollider()
	{}
};
