#include "GameObject.h"
#include "TextureMan.h"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
	objTexture = TextureMan::LoadTexture(textureSheet);

	xpos = x;
	ypos = y;
}

void GameObject::Update()
{
	xpos++;
	ypos++;

	if (character)
	{
		srcRect.h = 192;
		srcRect.w = 78;
	}
	else
	{
		srcRect.h = 32;
		srcRect.w = 32;
	}

	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}