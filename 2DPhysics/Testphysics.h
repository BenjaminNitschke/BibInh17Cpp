#include "Game.h"
#include "Circle.h"
#include <vector>
#include "GameObject.h"
#include "ColliderPair.h"
class Testphysics : public Game
{
public:
	
	void RunTestphysics();
	std::vector<std::shared_ptr<GameObject>> GameObjects;
	
	void DrawScene();
	void CollisionDetection();
	void ApplayPhysics();
	

	std::shared_ptr<GameObject > testdraw;
};