#include "stdafx.h"
#include "Testphysics.h"

#include <memory>
#include <vector>
#include <algorithm>
#include "GameObject.h"

Testphysics::Testphysics()
{
	
	GameObjects = std::vector<std::shared_ptr<GameObject>>();
	GameObjects.push_back(std::make_shared<GameObject>(0.5, 0, 0));
	GameObjects.push_back(std::make_shared<GameObject>(0, 0, 0));
	
}

Testphysics::~Testphysics()
{
}

void Testphysics::RunTestphysics()
{
	Run([=]()
	{
		ApplayPhysics();
		//DrawScene();
		
	});
}
void Testphysics::ApplayPhysics()
{
	for (unsigned i = 0; i < GameObjects.size(); i++) {
		
		GameObjects[i]->center->y += -0.00002;
		
	}
	for (unsigned i = 0; i < GameObjects.size(); i++) {

		GameObjects[i]->body->DrawCircle();
	}
}

void Testphysics::DrawScene()
{
	for (unsigned i = 0; i < GameObjects.size(); i++) {
		
		GameObjects[i]->body->DrawCircle();
	}
	
}


