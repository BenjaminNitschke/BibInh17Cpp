#pragma once
#include "Vector3.h"
#include "CircleCollider.h"
#include <memory>
#include "Circle.h"
class GameObject
{
public:
	std::shared_ptr<CircleCollider> collider;
	std::shared_ptr<Vector3> center;
	std::shared_ptr<Circle> body;
	
	GameObject(float x, float y, float z)
	{
		center = std::make_shared<Vector3>(x, y, z);
		collider = std::make_shared<CircleCollider>(center);
		body= std::make_shared<Circle>(center,0.1);

	}
	GameObject()
	{


	}

	~GameObject()
	{

	}
};
