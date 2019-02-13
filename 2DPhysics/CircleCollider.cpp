#include "stdafx.h"
#include "CircleCollider.h"


void CircleCollider::CheckCollision(std::vector<std::shared_ptr<GameObject>> GameObjects )
{
	for (auto &target : GameObjects) {

		if (id != target->collider->id)
		{
			if (Collide(target->collider))
			{
				float Distance = sqrtf((center->x - target->collider->center->x)*(center->x - target->collider->center->x) + (center->y - target->collider->center->y)*(center->y - target->collider->center->y));
				//normal
				float nx = (target->collider->center->x - center->x) / Distance;
				float ny = (target->collider->center->y - center->y) / Distance;
				//tangent
				float tx = -ny;
				float ty = nx;
				//dotProductTangent
				float dpTan1 = velocity->x *tx + velocity->y *ty;
				float dpTan2 = target->collider->velocity->x *tx + target->collider->velocity->y *ty;
				//dotProductNormal
				float dpNorm1 = velocity->x *nx + velocity->y *ny;
				float dpNorm2 = target->collider->velocity->x *nx + target->collider->velocity->y *ny;
				//Conservation of momentum in 1D
				float m1 = (dpNorm1 * (mass - target->collider->mass) + 2 * target->collider->mass * dpNorm2);
				float m2 = (dpNorm2 * (target->collider->mass - mass) + 2 * mass * dpNorm1);

				velocity->x = (tx * dpTan1 + nx * m1);
				velocity->y = (ty * dpTan1 + ny * m1);
				target->collider->velocity->x = (tx * dpTan2 + nx * m2);
				target->collider->velocity->y = (ty * dpTan2 + ny * m2);
				
			}
		}

	}
}



bool CircleCollider::Collide(std::shared_ptr<CircleCollider> collider)
{
	auto Collide = [](float x1, float y1, float r1, float x2, float y2, float r2)
	{
		return fabs((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) <= (r1 + r2)*(r1 + r2);

	};
	if (Collide(center->x, center->y, r, collider->center->x, collider->center->y, collider->r))
	{
		float Distance = sqrtf((center->x - collider->center->x)*(center->x - collider->center->x) + (center->y - collider->center->y)*(center->y - collider->center->y));
		float Overlap = 0.501f* (Distance - r - collider->r);
		center->x -= Overlap * (center->x - collider->center->x) / Distance;
		center->y -= Overlap * (center->y - collider->center->y) / Distance;

		collider->center->x += Overlap * (center->x - collider->center->x) / Distance;
		collider->center->y += Overlap * (center->y - collider->center->y) / Distance;
		return true;
	}
	return false;
}
/*bool CircleCollider::Collide(std::shared_ptr<LineCollider> collider)
{

	return true;
}*/