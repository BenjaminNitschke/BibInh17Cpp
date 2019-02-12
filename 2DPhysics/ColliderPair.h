#pragma once
#include "CircleCollider.h"

class ColliderPair
{
public:
	std::shared_ptr<CircleCollider> collider1;
	std::shared_ptr<CircleCollider> collider2;
	ColliderPair(std::shared_ptr<CircleCollider> colliderOne, std::shared_ptr<CircleCollider> colliderTwo)
	{
		collider1 = colliderOne;
		collider2 = colliderTwo;
	}
	ColliderPair()
	{
		
	}
	~ColliderPair()
	{}
};

