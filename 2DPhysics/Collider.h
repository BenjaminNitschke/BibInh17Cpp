#pragma once
#include "stdafx.h"
#include <memory>
#include "Vector3.h"


class Collider
{
public:
	Collider()
	{
		velocity = std::make_shared<Vector3>(0, 0, 0);
		acceleration = std::make_shared<Vector3>(0, 0, 0);
		
	}
	std::shared_ptr<Vector3> velocity;;
	std::shared_ptr<Vector3> acceleration;
	float mass;
	

	~Collider()
	{}
};
