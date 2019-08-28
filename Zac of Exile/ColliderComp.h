#pragma once
#include <string>
#include "SDL.h"
#include "components.h"
using namespace std;

class ColliderComp : public Component
{
public:
	SDL_Rect collider;
	string tag;

	TransformComp* transform;

	ColliderComp(string t)
	{
		tag = t;
	}

	void init() override
	{
		if (!entity->hasComponent<TransformComp>())
		{
			entity->addComponent<TransformComp>();
		}
		transform = &entity->getComponent<TransformComp>();

		Game::colliders.push_back(this);
	}

	void update() override
	{
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}

};