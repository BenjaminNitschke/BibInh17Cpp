#include "stdafx.h"
#include "Testphysics.h"

#include <memory>
#include <vector>
#include <algorithm>
#include "GameObject.h"

Testphysics::Testphysics()
{
	gameobject= std::make_shared<GameObject>(0, 0, 0);
	
	//cir= *gameobject->body.get();
	
}

Testphysics::~Testphysics()
{
}

void Testphysics::RunTestphysics()
{
	Run([=]()
	{
		
		gameobject->body->DrawCircle();
	});
}




