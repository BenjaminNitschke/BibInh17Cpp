#pragma once
#include "Vector3.h"
#include "stdafx.h"
#include <memory>
class Collider
{
public:
	
	std::shared_ptr<Vector3> velosity;
	std::shared_ptr<Vector3> axeleration;
	Collider()
	{}


	~Collider()
	{}
};
