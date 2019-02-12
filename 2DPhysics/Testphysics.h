#include "Game.h"
#include "Circle.h"
#include <vector>
#include "GameObject.h"
#include "ColliderPair.h"
class Testphysics : public Game
{
public:
	Testphysics();
	~Testphysics();
	void RunTestphysics();
	void DrawScene();
	void ApplayPhysics();
	void CollisionDetection();
	std::vector<std::shared_ptr<GameObject>> GameObjects;
	std::vector<std::shared_ptr<CircleCollider>> collider;
	std::vector<std::shared_ptr<ColliderPair>> cPair;
};