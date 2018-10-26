#pragma once

#include "Sprite.h"
#include <vector>
#include "Entity.h"


void Shoot(const std::shared_ptr<Entity>* player, std::shared_ptr<Sprite> tex);
std::vector<std::shared_ptr<Entity>> projectiles = std::vector<std::shared_ptr<Entity>>();
std::vector<std::shared_ptr<Entity>> enemies = std::vector<std::shared_ptr<Entity>>();