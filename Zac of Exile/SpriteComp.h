#pragma once

#include "Components.h"
#include "SDL.h"
#include "Vector2D.h"
#include "TextureMan.h"
#include "animation.h"
#include <map>

class SpriteComp : public Component
{
private:
	TransformComp* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	bool animated	= false;
	int frames		= 0;
	int speed		= 200;

public:

	int animIndex = 0;
	std::map<const char*, Animation> animations;

	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	SpriteComp() = default;
	SpriteComp(const char* path)
	{
		setTex(path);
	}

	SpriteComp(const char* path, bool isAnimated)
	{
		animated = isAnimated;

		Animation idle = Animation(0, 3, 100);
		Animation walk = Animation(1, 8, 100);

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);

		Play("Idle");

		setTex(path);
	}

	~SpriteComp()
	{
		SDL_DestroyTexture(texture);
	}

	void setTex(const char* path)
	{
		texture = TextureMan::LoadTexture(path);
	}

	void init() override
	{
		transform = &entity->getComponent<TransformComp>();
		
		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}

	void update() override
	{
		if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		srcRect.y = animIndex * transform->height;
		
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}

	void draw() override
	{
		TextureMan::Draw(texture, srcRect, destRect, spriteFlip);
	}

	void Play(const char* animName)
	{
		frames = animations[animName].frames;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
	}

};