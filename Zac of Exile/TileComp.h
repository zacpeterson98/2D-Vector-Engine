#pragma once
#include "ECS.h"
#include "SDL.h"
using namespace std;

class TileComp : public Component
{
public:

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	Vector2D position;

	TileComp() = default;

	~TileComp()
	{
		SDL_DestroyTexture(texture);
	}

	TileComp(int srcX, int srcY, int xpos, int ypos, const char* path)
	{
		texture = TextureMan::LoadTexture(path);

		position.x = xpos;
		position.y = ypos;

		srcRect.x	= srcX;
		srcRect.y	= srcY;
		srcRect.w = srcRect.h = 32;

		destRect.x	= xpos;
		destRect.y	= ypos;
		destRect.w = destRect.h = 64;
	}

	void update() override
	{
		destRect.x = position.x - Game::camera.x;
		destRect.y = position.y - Game::camera.y;
	}
	void draw() override
	{
		TextureMan::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
	}
};