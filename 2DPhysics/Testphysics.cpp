#include "stdafx.h"
#include "Testphysics.h"

#include <memory>
#include <vector>
#include <algorithm>
#include "GameObject.h"

Testphysics::Testphysics()
{
	
	GameObjects = std::vector<std::shared_ptr<GameObject>>();
	GameObjects.push_back(std::make_shared<GameObject>(0, 0.3, 0,0));
	GameObjects.push_back(std::make_shared<GameObject>(0, 0, 0,1));
	collider = std::vector<std::shared_ptr<CircleCollider>>();
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
					float Distance = sqrtf((Object->center->x - target->center->x)*(Object->center->x - target->center->x) + (Object->center->y - target->center->y)*(Object->center->y - target->center->y));
					float Overlap = 0.5f* (Distance - Object->r - target->r);
					Object->center->x -= Overlap * (Object->center->x - target->center->x) / Distance;
					Object->center->y -= Overlap * (Object->center->y - target->center->y) / Distance;

					target->center->x += Overlap * (Object->center->x - target->center->x) / Distance;
					target->center->y += Overlap * (Object->center->y - target->center->y) / Distance;
				}
			}

		}
	}

}
void Testphysics::ApplayPhysics()
{
	
		
		GameObjects[0]->center->y += -0.00003;
		
	
	
}

void Testphysics::DrawScene()
{
	for (unsigned i = 0; i < GameObjects.size(); i++) {
		
		GameObjects[i]->body->DrawCircle();
	}
	
}


