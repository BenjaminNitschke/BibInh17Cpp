#pragma once
#include "stdafx.h"
#include "Game.h"
#include <vector>
#include "CircleCollider.h"
#include <memory>
#include "GameObject.h"

#include "Circle.h"




class Testphysics : public Game
{
public:
	Testphysics();
	void RunTestphysics();
	std::vector<std::shared_ptr<GameObject>> GameObjects;

	
	void DrawScene();
	void CollisionDetection();
	void ApplayPhysics();
	

	std::shared_ptr<GameObject> testdraw;
	~Testphysics();
};