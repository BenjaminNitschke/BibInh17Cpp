#pragma once
#include "Vector3.h"
#include "stdafx.h"
#include <memory>
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
	


	~Collider()
	{}
};
