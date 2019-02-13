#include "stdafx.h"
#include "Testphysics.h"

#include <memory>
#include <vector>
#include <algorithm>
#include "GameObject.h"
#include "ColliderPair.h"
Testphysics::Testphysics()
{
	testdraw = std::make_shared<GameObject>(0, 0, 0, 0.5);
	GameObjects =  std::vector<std::shared_ptr<GameObject>>();
	GameObjects.push_back(std::make_shared<GameObject>(0, -0.9, 0,0,0.05));
	GameObjects.push_back(std::make_shared<GameObject>(0, 0.4, 0,1,0.05));
	GameObjects.push_back(std::make_shared<GameObject>(0.025, 0.45, 0, 2, 0.05));
	GameObjects.push_back(std::make_shared<GameObject>(-0.025, 0.45, 0.4, 3, 0.05));
	GameObjects.push_back(std::make_shared<GameObject>(0.05, 0.5, 0, 4, 0.05));
	GameObjects.push_back(std::make_shared<GameObject>(0.1, 0.5, 0, 5, 0.05));
	GameObjects.push_back(std::make_shared<GameObject>(-0.05, 0.5, 0, 6, 0.05));
	GameObjects.push_back(std::make_shared<GameObject>(-0.1, 0.5, 0, 7, 0.05));
	GameObjects.push_back(std::make_shared<GameObject>(-0.05, 0.55, 0, 8, 0.05));
	GameObjects.push_back(std::make_shared<GameObject>(-0.1, 0.55, 0, 9, 0.05));
	GameObjects.push_back(std::make_shared<GameObject>(-1.5, 0.55, 0, 10, 0.05));
	
	
	
	
	
}

Testphysics::~Testphysics()
{
}

void Testphysics::RunTestphysics()
{
	Run([=]()
	{
		CollisionDetection();
		ApplayPhysics();
		DrawScene();
		
	});


void Testphysics::CollisionDetection()
{
	
	for (auto &Object : GameObjects) {

		
		Object->collider->CheckCollision(GameObjects);
	}
	
}
void Testphysics::ApplayPhysics()
{

	if (downPressed )
	{
		GameObjects[0]->collider->velocity->y += -0.02;
	}
	if (upPressed)
	{
		testdraw->center->y += 0.01;
		GameObjects[0]->collider->velocity->y += 0.02;
	}
	if (leftPressed)
	{
		GameObjects[0]->collider->velocity->x += -0.02;
	}
	if (rightPressed)
	{
		GameObjects[0]->collider->velocity->x += 0.02;
	}
	
	for (auto &Object : GameObjects) {

		if (Object->collider->velocity->x == 0)
		{
			Object->collider->acceleration->x = 0;
		}
		else if(Object->collider->velocity->x > 0)
		{
			Object->collider->acceleration->x = -0.6;
		}
		else
		{
			Object->collider->acceleration->x = 0.6;
		}
		if (Object->collider->velocity->y == 0)
		{
			Object->collider->acceleration->y =0;
		}
		else if (Object->collider->velocity->y > 0)
		{
			Object->collider->acceleration->y = -0.6;
		}
		else
		{
			Object->collider->acceleration->y = 0.6;
		}
		Object->collider->velocity->x += Object->collider->acceleration->x *timeThisTick;
		Object->collider->velocity->y += Object->collider->acceleration->y*timeThisTick;
		Object->center->x += Object->collider->velocity->x * timeThisTick ;
		Object->center->y += Object->collider->velocity->y * timeThisTick ;
		if (Object->center->x < -(Object->collider->r+1))
			Object->center->x = (Object->collider->r + 1);
		if (Object->center->x > (Object->collider->r + 1))
			Object->center->x = -(Object->collider->r + 1);
		if (Object->center->y < -(Object->collider->r + 1))
			Object->center->y = (Object->collider->r + 1);
		if (Object->center->y > (Object->collider->r + 1))
			Object->center->y = -(Object->collider->r + 1);

		if (fabs(Object->collider->velocity->x * Object->collider->velocity->x + Object->collider->velocity->y * Object->collider->velocity->y)<0.000003f)
		{
			Object->collider->velocity->x =0;
			Object->collider->velocity->y =0;
		}
	}
	
	
	
}

void Testphysics::DrawScene()
{
	for (auto &Object : GameObjects) {
		
		Object->body->DrawCircle();
	}
	testdraw->lbody->DrawLine();
}


