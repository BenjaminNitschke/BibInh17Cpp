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
	GameObjects = std::vector<std::shared_ptr<GameObject>>();
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
	collider = std::vector<std::shared_ptr<CircleCollider>>();
	cPair = std::vector<std::shared_ptr<ColliderPair>>();
	for (auto &col : GameObjects) {

		collider.push_back(col->collider);

	}
	
	
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
}

void Testphysics::CollisionDetection()
{
	auto Collide=[](float x1, float y1,float r1, float x2, float y2, float r2)
	{
		return fabs((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) <= (r1+r2)*(r1+r2);
	
	};
	for (auto &Object : collider) {

		
		for (auto &target : collider) {

			if (Object->id != target->id)
			{
				if (Collide(Object->center->x, Object->center->y, Object->r, target->center->x, target->center->y, target->r))
				{
					cPair.push_back(std::make_shared<ColliderPair>(Object,target));
					float Distance = sqrtf((Object->center->x - target->center->x)*(Object->center->x - target->center->x) + (Object->center->y - target->center->y)*(Object->center->y - target->center->y));
					float Overlap = 0.501f* (Distance - Object->r - target->r);
					Object->center->x -= Overlap * (Object->center->x - target->center->x) / Distance;
					Object->center->y -= Overlap * (Object->center->y - target->center->y) / Distance;

					target->center->x += Overlap * (Object->center->x - target->center->x) / Distance;
					target->center->y += Overlap * (Object->center->y - target->center->y) / Distance;
				}
			}

		}
	}
	for (auto c : cPair)
	{
		float Distance = sqrtf((c->collider1->center->x - c->collider2->center->x)*(c->collider1->center->x - c->collider2->center->x) + (c->collider1->center->y - c->collider2->center->y)*(c->collider1->center->y - c->collider2->center->y));
		//normal
		float nx=( c->collider2->center->x - c->collider1->center->x )/ Distance;
		float ny= (c->collider2->center->y - c->collider1->center->y) / Distance;
		//tangent
		float tx = -ny;
		float ty = nx;
		//dotProductTangent
		float dpTan1 = c->collider1->velocity->x *tx + c->collider1->velocity->y *ty;
		float dpTan2 = c->collider2->velocity->x *tx + c->collider2->velocity->y *ty;
		//dotProductNormal
		float dpNorm1 = c->collider1->velocity->x *nx + c->collider1->velocity->y *ny;
		float dpNorm2 = c->collider2->velocity->x *nx + c->collider2->velocity->y *ny;
		//Conservation of momentum in 1D
		float m1 = (dpNorm1 * (c->collider1->mass - c->collider2->mass) +  2* c->collider2->mass * dpNorm2);
		float m2 = (dpNorm2 * (c->collider2->mass - c->collider1->mass) +  2* c->collider1->mass * dpNorm1);

		c->collider1->velocity->x = (tx * dpTan1 + nx*m1);
		c->collider1->velocity->y = (ty * dpTan1 + ny*m1);
		c->collider2->velocity->x = (tx * dpTan2 + nx*m2);
		c->collider2->velocity->y = (ty * dpTan2 + ny*m2);
	}
	cPair.clear();
}
void Testphysics::ApplayPhysics()
{

	if (downPressed )
	{
		collider[0]->velocity->y += -0.02;
	}
	if (upPressed)
	{
		testdraw->center->y += 0.01;
		collider[0]->velocity->y += 0.02;
	}
	if (leftPressed)
	{
		collider[0]->velocity->x += -0.02;
	}
	if (rightPressed)
	{
		collider[0]->velocity->x += 0.02;
	}
	
	for (auto &Object : collider) {

		if (Object->velocity->x == 0)
		{
			Object->acceleration->x = 0;
		}
		else if(Object->velocity->x > 0)
		{
			Object->acceleration->x = -0.6;
		}
		else
		{
			Object->acceleration->x = 0.6;
		}
		if (Object->velocity->y == 0)
		{
			Object->acceleration->y =0;
		}
		else if (Object->velocity->y > 0)
		{
			Object->acceleration->y = -0.6;
		}
		else
		{
			Object->acceleration->y = 0.6;
		}
		Object->velocity->x += Object->acceleration->x *timeThisTick;
		Object->velocity->y += Object->acceleration->y*timeThisTick;
		Object->center->x += Object->velocity->x * timeThisTick ;
		Object->center->y += Object->velocity->y * timeThisTick ;
		if (Object->center->x < -(Object->r+1))
			Object->center->x = (Object->r + 1);
		if (Object->center->x > (Object->r + 1))
			Object->center->x = -(Object->r + 1);
		if (Object->center->y < -(Object->r + 1))
			Object->center->y = (Object->r + 1);
		if (Object->center->y > (Object->r + 1))
			Object->center->y = -(Object->r + 1);

		if (fabs(Object->velocity->x * Object->velocity->x + Object->velocity->y * Object->velocity->y)<0.000003f)
		{
			Object->velocity->x =0;
			Object->velocity->y =0;
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


