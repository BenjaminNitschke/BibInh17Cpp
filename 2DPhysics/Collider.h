#pragma once
#include "Vector3.h"
#include "stdafx.h"
#include <memory>
class Collider
{
public:
	std::shared_ptr<Vector3> center;

	Collider()
	{}


	~Collider()
	{}
};
