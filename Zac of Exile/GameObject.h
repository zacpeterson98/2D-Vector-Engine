#pragma once
#include "game.h"


class GameObject
{
private:
	int xpos;
	int ypos;
	
	bool character;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;


public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void Update();
	void Render();
};