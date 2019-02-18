#pragma once
#include "stdafx.h"
#include "Game.h"
#include <vector>
#include "CircleCollider.h"
#include "LineCollider.h"
#include <memory>
#include "GameObject.h"
#include "Line.h"
#include "Circle.h"




class Testphysics : public Game
{
public:
	Testphysics();
	void RunTestphysics();
	std::vector<std::shared_ptr<GameObject>> GameObjects;
	std::vector<std::shared_ptr<GameObject>> GameObjectsl;
	
	void DrawScene();
	void CollisionDetection();
	void ApplayPhysics();
	float CalcDistance(float x, float y, float x2, float y2);
	bool Collides(std::shared_ptr<CircleCollider>collider, std::shared_ptr<CircleCollider>collider2);
	bool CheckCollisionlp(std::shared_ptr<LineCollider>collider, std::shared_ptr<Vector3> point);
	bool Collidescv(std::shared_ptr<CircleCollider>collider,std::shared_ptr<Vector3>point);
	bool CheckCollisionl(std::shared_ptr<LineCollider>collider, std::shared_ptr<CircleCollider>collider2);
	std::shared_ptr<GameObject> testdraw;
	std::shared_ptr<GameObject> testdraw2;
	std::shared_ptr<GameObject> testdraw3;
	std::shared_ptr<GameObject> testdraw4;
	std::shared_ptr<GameObject> testdraw5;
	~Testphysics();
};