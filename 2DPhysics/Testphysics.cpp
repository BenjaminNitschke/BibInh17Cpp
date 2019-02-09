#include "stdafx.h"
#include "Testphysics.h"

#include <memory>
#include <vector>
#include <algorithm>
#include "GameObject.h"

Testphysics::Testphysics()
{
	
	GameObjects = std::vector<std::shared_ptr<GameObject>>();
	GameObjects.push_back(std::make_shared<GameObject>(0.5, 0.5, 0));
	GameObjects.push_back(std::make_shared<GameObject>(0, 0.5, 0));
	
}

Testphysics::~Testphysics()
{
}

void Testphysics::RunTestphysics()
{
	Run([=]()
	{
		ApplayPhysics();
		DrawScene();
		
	});
}

void Testphysics::CollisionDetection()
{
	auto Collide=[](float x1, float y1,float r1, float x2, float y2, float r2)
	{
		return fabs((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) <= (r1 + r2)*(r1 + r2);
	
	};
	for (auto &Object : GameObjects) {

		
		for (auto &target : GameObjects) {

			if (Object->collider->id != target->collider->id)
			{
				if (Collide(Object->collider->center->x, Object->collider->center->y, Object->collider->r, target->collider->center->x, target->collider->center->y, target->collider->r))
				{
					float Distance = sqrtf((Object->collider->center->x - target->collider->center->x)*(Object->collider->center->x - target->collider->center->x) + (Object->collider->center->y - target->collider->center->y)*(Object->collider->center->y - target->collider->center->y));
					float Overlap = 0.5f* (Distance - Object->collider->r - target->collider->r);
					Object->collider->center->x -= Overlap * (Object->collider->center->x - target->collider->center->x) / Distance;
					Object->collider->center->y -= Overlap * (Object->collider->center->y - target->collider->center->y) / Distance;

					target->collider->center->x += Overlap * (Object->collider->center->x - target->collider->center->x) / Distance;
					target->collider->center->y += Overlap * (Object->collider->center->y - target->collider->center->y) / Distance;
				}
			}

		}
	}

}
void Testphysics::ApplayPhysics()
{
	for (unsigned i = 0; i < GameObjects.size(); i++) {
		
		GameObjects[i]->center->y += -0.00001;
		
	}
	
}

void Testphysics::DrawScene()
{
	for (unsigned i = 0; i < GameObjects.size(); i++) {
		
		GameObjects[i]->body->DrawCircle();
	}
	
}


