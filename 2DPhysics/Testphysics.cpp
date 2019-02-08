#include "stdafx.h"
#include "Testphysics.h"

#include <memory>
#include <vector>
#include <algorithm>

Testphysics::Testphysics()
{
	go = GameObject(0, 0, 0);

}
GameObject go;
Testphysics::~Testphysics()
{
}

void Testphysics::RunTestphysics()
{
	Run([=]()
	{
		DrawAll();
	});
}




void Testphysics::DrawAll()
{
	


}