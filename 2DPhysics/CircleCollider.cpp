#include "stdafx.h"



/*
bool CircleCollider::Collidesv(std::shared_ptr<Vector3>collider)
{
	auto Collide = [](float x1, float y1, float r1, float x2, float y2)
	{
		return fabs((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) <= r1*r1 ;

	};
	if (Collide(center->x, center->y, r, collider->x, collider->y))
	{
		float Distance = sqrtf((center->x - collider->x)*(center->x - collider->x) + (center->y - collider->y)*(center->y - collider->y));
		float Overlap = 1.01f* (Distance - r );
		center->x -= Overlap * (center->x - collider->x) / Distance;
		center->y -= Overlap * (center->y - collider->y) / Distance;

		//collider->x += Overlap * (center->x - collider->x) / Distance;
		//collider->y += Overlap * (center->y - collider->y) / Distance;
		return true;
	}
	return false;
}
bool CircleCollider::CheckCollisionl(std::shared_ptr<LineCollider>collider)
{
	if (Collidesv(collider->p1) || Collidesv(collider->p2))
	{
		/*float Distance = sqrtf((center->x - center->x)*(center->x - collider->center->x) + (center->y - collider->center->y)*(center->y - collider->center->y));
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

		velocity->x = (tx * dpTan1 + nx * m1)*0.8;
		velocity->y = (ty * dpTan1 + ny * m1)*0.8;
		collider->velocity->x = (tx * dpTan2 + nx * m2)*0.8;
		collider->velocity->y = (ty * dpTan2 + ny * m2)*0.8;
		return true;
	}
	else
	{
		float leng = Distance(collider->p1->x, collider->p1->y, collider->p2->x, collider->p2->y);
		float dot = (((center->x - collider->p1->x)*(collider->p2->x - collider->p1->x)) + ((center->y - collider->p1->y)*(collider->p2->y - collider->p1->y))) / std::pow(leng,2);
		float closestX = collider->p1->x + (dot*(collider->p2->x - collider->p1->x));
		float closestY = collider->p1->y + (dot*(collider->p2->y - collider->p1->y));
		if (CheckCollisionlp(collider, std::make_shared<Vector3>(closestX, closestY, 0)))
		{
			if (Collidesv(std::make_shared<Vector3>(closestX, closestY, 0)))
			{
				float Distance = sqrtf((center->x - closestX)*(center->x - closestX) + (center->y - closestY)*(center->y - closestY));
				float Overlap = 1.01f* (Distance - r);
				center->x -= Overlap * (center->x - closestX) / Distance;
				center->y -= Overlap * (center->y - closestY) / Distance;
				return true;
			}
		}
	}
	return false;
}
*/
