
#include "stdafx.h"
#include "Testphysics.h"
#include "Vector3.h"

#include <memory>
#include <vector>
#include <algorithm>


Testphysics::Testphysics()
{
	testdraw = std::make_shared<GameObject>(0.0f, -0.9f, 0.0f, 0, 0.05f);
	//testdraw2 = std::make_shared<GameObject>(std::make_shared<GameObject>(-0.9, 0.9, 0, 0.9, 0.9, 0, 2, true));
	GameObjects.push_back(testdraw);
	GameObjects.push_back(std::make_shared<GameObject>(0.1f, 0.1f, 0.0f,1,0.05f));
	GameObjects.push_back(std::make_shared<GameObject>(0.2f, -0.2f, 0.0f, 2, 0.05f));
	GameObjects.push_back(std::make_shared<GameObject>(0.3f, 0.3f, 0.0f, 3, 0.05f));
	GameObjects.push_back(std::make_shared<GameObject>(-0.4f, 0.4f, 0.0f, 4, 0.05f));
	GameObjects.push_back(std::make_shared<GameObject>(0.5f, 0.5f, 0.0f, 5, 0.05f));
	GameObjects.push_back(std::make_shared<GameObject>(0.6f, -0.6f, 0.0f, 6, 0.05f));
	GameObjects.push_back(std::make_shared<GameObject>(0.7f, 0.7f, 0.0f, 7, 0.05f));
	GameObjects.push_back(std::make_shared<GameObject>(-0.8f, 0.8f, 0.0f, 8, 0.05f));
}

Testphysics::~Testphysics()
{
}

void Testphysics::RunTestphysics()
{
	Run([=]()
	{
		for (auto &Object : GameObjects) {

			if (Object->collider->velocity->x == 0)
			{
				Object->collider->acceleration->x = 0;
			}
			else if (Object->collider->velocity->x > 0)
			{
				Object->collider->acceleration->x = -0.53;
			}
			else
			{
				Object->collider->acceleration->x = 0.53;
			}
			if (Object->collider->velocity->y == 0)
			{
				Object->collider->acceleration->y = 0;
			}
			else if (Object->collider->velocity->y > 0)
			{
				Object->collider->acceleration->y = -0.53;
			}
			else
			{
				Object->collider->acceleration->y = 0.53;
			}
			Object->collider->velocity->x += Object->collider->acceleration->x *timeThisTick;
			Object->collider->velocity->y += Object->collider->acceleration->y*timeThisTick;
			Object->center->x += Object->collider->velocity->x * timeThisTick;
			Object->center->y += Object->collider->velocity->y * timeThisTick;
			if (Object->center->x < -(Object->collider->r + 1))
				Object->center->x = (Object->collider->r + 1);
			if (Object->center->x > (Object->collider->r + 1))
				Object->center->x = -(Object->collider->r + 1);
			if (Object->center->y < -(Object->collider->r + 1))
				Object->center->y = (Object->collider->r + 1);
			if (Object->center->y > (Object->collider->r + 1))
				Object->center->y = -(Object->collider->r + 1);

			if (fabs(Object->collider->velocity->x * Object->collider->velocity->x + Object->collider->velocity->y * Object->collider->velocity->y) < 0.000003f)
			{
				Object->collider->velocity->x = 0;
				Object->collider->velocity->y = 0;
			}
		}
		CollisionDetection();
		ApplayPhysics();
		DrawScene();

	});
}

void Testphysics::CollisionDetection()
{
	
	for (auto &Object : GameObjects) {
		
		
			for (auto &target : GameObjects) {
				if (Object->collider->id != target->collider->id)
				{
					if (Object->collider->CheckCollisioncc(target->collider)) {}
				}
				

			}
		
		//if (Object->collider->CheckCollisionl(testdraw2->lcollider)) {}
	}


	
}
void Testphysics::ApplayPhysics()
{

	if (downPressed )
	{
		testdraw->collider->velocity->y += -0.02;
	}
	if (upPressed)
	{
		
		testdraw->collider->velocity->y += 0.02;
	}
	if (leftPressed)
	{
		testdraw->collider->velocity->x += -0.02;
	}
	if (rightPressed)
	{
		testdraw->collider->velocity->x += 0.02;
	}
	
	
	
	
	
}



void Testphysics::DrawScene()
{
	for (auto &Object : GameObjects) {
		
		Object->body->DrawCircle();
	}
//	testdraw->lbody->DrawLine();
}


