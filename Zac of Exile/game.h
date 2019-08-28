#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
using namespace std;

class ColliderComp;

class Game 
{
private:
	SDL_Window* window;
	int count = 0;

public:
	Game();
	~Game();

	static bool isRunning;

	void init(const char* title, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	static void AddTile(int srcX, int srcY, int x, int y);
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static vector<ColliderComp*> colliders;
	static SDL_Rect camera;

	bool running() 
	{ 
		return isRunning;
	}
};