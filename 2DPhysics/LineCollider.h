#pragma once
#include "Collider.h"
class LineCollider :	public Collider
{
public:
	LineCollider(std::shared_ptr<Vector3> point1, std::shared_ptr<Vector3> point2)
	{
		std::shared_ptr<Vector3> p1=point1;
		std::shared_ptr<Vector3> p2=point2;
	}
	std::shared_ptr<Vector3> p1;
	std::shared_ptr<Vector3> p2;
	~LineCollider();
};

