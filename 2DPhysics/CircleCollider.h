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
		mass = r * 5;
		
	}
	CircleCollider()
	{

	}
	bool stat = false;
	float r;
	int id;
	
	
	
	bool CheckCollisionlp(std::shared_ptr<LineCollider>collider, std::shared_ptr<Vector3> point);
	std::shared_ptr<Vector3> center;
	
	
	~CircleCollider()
	{}
};
