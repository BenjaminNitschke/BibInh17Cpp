
#include "stdafx.h"
#include "Testphysics.h"
#include "Vector3.h"

#include <memory>
#include <vector>
#include <algorithm>


Testphysics::Testphysics()
{
	testdraw = std::make_shared<GameObject>(0.0f, -0.8f, 0.0f, 0, 0.05f);
	testdraw2 = std::make_shared<GameObject>(-0.9, 0.9, 0, 0.9, 0.9, 0, 2);
	testdraw3 = std::make_shared<GameObject>(-0.9, 0.9, 0, -0.9, -0.9, 0, 2);
	testdraw4 = std::make_shared<GameObject>(0.9, -0.9, 0, 0.9, 0.9, 0, 2);
	testdraw5 = std::make_shared<GameObject>(0.9, -0.9, 0, -0.9, -0.9, 0, 2);
	GameObjectsl.push_back(testdraw2);
	GameObjectsl.push_back(testdraw3);
	GameObjectsl.push_back(testdraw4);
	GameObjectsl.push_back(testdraw5);
	GameObjects.push_back(testdraw);
	
	GameObjects.push_back(std::make_shared<GameObject>(0.0f, 0.1f, 0.0f,1,0.05f));
	GameObjects.push_back(std::make_shared<GameObject>(0.051f, 0.201f, 0.0f, 2, 0.05f));
	GameObjects.push_back(std::make_shared<GameObject>(-0.051f, 0.201f, 0.0f, 3, 0.05f));
	GameObjects.push_back(std::make_shared<GameObject>(0.121f, 0.302f, 0.0f, 4, 0.05f));
	GameObjects.push_back(std::make_shared<GameObject>(-0.121f, 0.302f, 0.0f, 5, 0.05f));
	GameObjects.push_back(std::make_shared<GameObject>(0.103f, 0.302, 0.0f, 6, 0.05f));
	
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
				Object->collider->acceleration->x = 0.0f;
			}
			else if (Object->collider->velocity->x > 0)
			{
				Object->collider->acceleration->x = -0.6f;
			}
			else
			{
				Object->collider->acceleration->x = 0.6f;
			}
			if (Object->collider->velocity->y == 0)
			{
				Object->collider->acceleration->y = 0.0f;
			}
			else if (Object->collider->velocity->y > 0)
			{
				Object->collider->acceleration->y = -0.6f;
			}
			else
			{
				Object->collider->acceleration->y = 0.6f;
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
					
						if (Collides(Object->collider,target->collider))
						{
							float Distance = CalcDistance(Object->collider->center->x, Object->collider->center->y, target->collider->center->x, target->collider->center->y);
							//normal
							float nx = (target->collider->center->x - Object->collider->center->x) / Distance;
							float ny = (target->collider->center->y - Object->collider->center->y) / Distance;
							//tangent
							float tx = -ny;
							float ty = nx;
							//dotProductTangent
							float dpTan1 = Object->collider->velocity->x *tx + Object->collider->velocity->y *ty;
							float dpTan2 = target->collider->velocity->x *tx + target->collider->velocity->y *ty;
							//dotProductNormal
							float dpNorm1 = Object->collider->velocity->x *nx + Object->collider->velocity->y *ny;
							float dpNorm2 = target->collider->velocity->x *nx + target->collider->velocity->y *ny;
							//Conservation of momentum in 1D
							float m1 = (dpNorm1 * (Object->collider->mass - target->collider->mass) + 2.0f* target->collider->mass * dpNorm2)/(Object->collider->mass + target->collider->mass);
							float m2 = (dpNorm2 * (target->collider->mass - Object->collider->mass) +  2.0f* Object->collider->mass * dpNorm1)/ (Object->collider->mass + target->collider->mass);

							Object->collider->velocity->x = (tx * dpTan1 + nx * m1);
							Object->collider->velocity->y = (ty * dpTan1 + ny * m1);
							target->collider->velocity->x = (tx * dpTan2 + nx * m2);
							target->collider->velocity->y = (ty * dpTan2 + ny * m2);
							
						}
						
					
					
				}
				

			}
			for (auto &Lines : GameObjectsl) {
				if (CheckCollisionl(Lines->lcollider, Object->collider)) {}


			}
			
		
	}


	
}
bool Testphysics::Collides(std::shared_ptr<CircleCollider>collider, std::shared_ptr<CircleCollider>collider2)
{
	auto Collide = [](float x1, float y1, float r1, float x2, float y2, float r2)
	{
		return fabs((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) <= (r1 + r2)*(r1 + r2);

	};
	if (Collide(collider->center->x, collider->center->y, collider->r, collider2->center->x, collider2->center->y, collider2->r))
	{
		float Distance = CalcDistance(collider->center->x, collider->center->y, collider2->center->x, collider2->center->y);
		float Overlap = 0.503f* (Distance - collider->r - collider2->r);
		collider->center->x -= Overlap * (collider->center->x - collider2->center->x) / Distance;
		collider->center->y -= Overlap * (collider->center->y - collider2->center->y) / Distance;

		collider2->center->x += Overlap * (collider->center->x - collider2->center->x) / Distance;
		collider2->center->y += Overlap * (collider->center->y - collider2->center->y) / Distance;
		return true;
	}
	return false;
}

	

void Testphysics::ApplayPhysics()
{

	if (downPressed )
	{
		testdraw->collider->velocity->y += -5* timeThisTick;
	}
	if (upPressed)
	{
		
		testdraw->collider->velocity->y += 5* timeThisTick;
	}
	if (leftPressed)
	{
		testdraw->collider->velocity->x += -5* timeThisTick;
	}
	if (rightPressed)
	{
		testdraw->collider->velocity->x += 5* timeThisTick;
	}
	
	
	
	
	
}



void Testphysics::DrawScene()
{
	for (auto &Object : GameObjects) {
		
		Object->body->DrawCircle();
	}
	for (auto &Lines : GameObjectsl) {
		Lines->lbody->DrawLine();


	}
	
}

float Testphysics::CalcDistance(float x, float y, float x2, float y2)
{
	float distX = x - x2;
	float distY = y - y2;
	return sqrt((distX*distX) + (distY*distY));


}
bool Testphysics::CheckCollisionl(std::shared_ptr<LineCollider>collider, std::shared_ptr<CircleCollider>collider2)
{
	if (Collidescv(collider2, collider->p1) || Collidescv(collider2, collider->p2))
	{
		
		
		return true;
	}
	else
	{
		float leng = CalcDistance(collider->p1->x, collider->p1->y, collider->p2->x, collider->p2->y);
		float dot = (((collider2->center->x - collider->p1->x)*(collider->p2->x - collider->p1->x)) + ((collider2->center->y - collider->p1->y)*(collider->p2->y - collider->p1->y))) / std::pow(leng, 2);
		float closestX = collider->p1->x + (dot*(collider->p2->x - collider->p1->x));
		float closestY = collider->p1->y + (dot*(collider->p2->y - collider->p1->y));
		if (CheckCollisionlp(collider, std::make_shared<Vector3>(closestX, closestY, 0)))
		{
			if(Collidescv(collider2, std::make_shared<Vector3>(closestX, closestY, 0)))
			{
				return true;
			}
			return true;
		}
		return false;
	}
}
bool Testphysics::Collidescv(std::shared_ptr<CircleCollider>collider,std::shared_ptr<Vector3>point)
{
	auto Colliden = [](float x1, float y1, float r1, float x2, float y2)
	{
		return fabs((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) <= r1 * r1;

	};
	if (CalcDistance(collider->center->x,collider->center->y,point->x,point->y)<=collider->r )//Colliden(collider->center->x, collider->center->y, collider->r, point->x, point->y)
	{
		float Distance = CalcDistance(collider->center->x, collider->center->y, point->x, point->y);
		float Overlap = 1.01f* (Distance - collider->r);
		collider->center->x -= Overlap * (collider->center->x - point->x) / Distance;
		collider->center->y -= Overlap * (collider->center->y - point->y) / Distance;

		//point->x += Overlap * (collider->center->x - point->x) / Distance;
		//point->y += Overlap * (collider->center->y - point->y) / Distance;
		
		//normal
		float nx = (collider->center->x - point->x) / Distance;
		float ny = (collider->center->y - point->y) / Distance;
		//tangent
		float tx = -ny;
		float ty = nx;
		//dotProductTangent
		float dpTan1 = collider->velocity->x *tx + collider->velocity->y *ty;
		float dpTan2 = 0 *tx + 0 *ty;
		//dotProductNormal
		float dpNorm1 = collider->velocity->x *nx + collider->velocity->y *ny;
		float dpNorm2 = 0 *nx + 0 *ny;
		//Conservation of momentum in 1D
		float m1 = (dpNorm1 * (collider->mass - collider->mass*0.3) + 2.0f* collider->mass*0.3 * dpNorm2) / (collider->mass + collider->mass*0.3);
		//float m2 = (dpNorm2 * (collider->mass - mass) + 2 * mass * dpNorm1);

		collider->velocity->x = (tx * dpTan1 + nx * m1);
		collider->velocity->y = (ty * dpTan1 + ny * m1);
		//collider->velocity->x = (tx * dpTan2 + nx * m2)*0.8;
		//collider->velocity->y = (ty * dpTan2 + ny * m2)*0.8;
		return true;
	}
	return false;
}
bool Testphysics::CheckCollisionlp(std::shared_ptr<LineCollider>collider, std::shared_ptr<Vector3> point)
{
	float leng = CalcDistance(collider->p1->x, collider->p1->y, collider->p2->y, collider->p2->y);
	float d1 = CalcDistance(point->x, point->y, collider->p1->x, collider->p1->y);
	float d2 = CalcDistance(point->x, point->y, collider->p2->x, collider->p2->y);
	float buffer = 0.02;
	if (d1 + d2 >= leng - buffer && d1 + d2 <= leng + buffer)
	{
		return true;
	}
	return false;
}
