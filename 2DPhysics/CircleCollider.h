#pragma once
#include "stdafx.h"
#include <vector>

#include <memory>
#include "GameObject.h"
#include "Collider.h"
#include "LineCollider.h"

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
	void CheckCollision(std::vector<std::shared_ptr<GameObject>> GameObjects);
	bool Collide(std::shared_ptr<CircleCollider>collider );
	/*bool Collide(std::shared_ptr<LineCollider> );*/
	CircleCollider()
	{
		
	}
	~CircleCollider()
	{}
};
