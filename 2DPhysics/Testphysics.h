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
	std::shared_ptr<GameObject> gameobject;
	std::shared_ptr<Circle> bodyy;
	void DrawAll();
};