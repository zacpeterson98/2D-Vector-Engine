#pragma once
#include "SDL.h"

class ColliderComp;

class Collision
{
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
	static bool AABB(const ColliderComp& colA, const ColliderComp& colB);
};