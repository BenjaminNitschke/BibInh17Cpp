#include "Game.h"
#include "Circle.h"
#include <vector>
#include "GameObject.h"
class Testphysics : public Game
{
public:
	Testphysics();
	~Testphysics();
	void RunTestphysics();
	void DrawScene();
	std::shared_ptr<GameObject> gameobject;
	
};