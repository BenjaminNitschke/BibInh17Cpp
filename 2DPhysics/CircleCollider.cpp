#include "stdafx.h"
#include "CircleCollider.h"

bool CircleCollider::CheckCollision(std::shared_ptr<CircleCollider>collider)
{
	if (Collides(collider))
	{
		float Distance = sqrtf((center->x - center->x)*(center->x - collider->center->x) + (center->y - collider->center->y)*(center->y - collider->center->y));
		//normal
		float nx = (collider->center->x - center->x) / Distance;
		float ny = (collider->center->y - center->y) / Distance;
		//tangent
		float tx = -ny;
		float ty = nx;
		//dotProductTangent
		float dpTan1 = velocity->x *tx + velocity->y *ty;
		float dpTan2 = collider->velocity->x *tx + velocity->y *ty;
		//dotProductNormal
		float dpNorm1 = velocity->x *nx + velocity->y *ny;
		float dpNorm2 = collider->velocity->x *nx + collider->velocity->y *ny;
		//Conservation of momentum in 1D
		float m1 = (dpNorm1 * (mass - collider->mass) + 2 * collider->mass * dpNorm2);
		float m2 = (dpNorm2 * (collider->mass - mass) + 2 * mass * dpNorm1);

		velocity->x = (tx * dpTan1 + nx * m1);
		velocity->y = (ty * dpTan1 + ny * m1);
		collider->velocity->x = (tx * dpTan2 + nx * m2);
		collider->velocity->y = (ty * dpTan2 + ny * m2);
		return true;
	}
	return false;
}
bool CircleCollider::Collides(std::shared_ptr<CircleCollider>collider)
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