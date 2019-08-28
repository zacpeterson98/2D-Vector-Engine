#pragma once
#include "Components.h"
#include "ecs.h"

class TransformComp : public Component
{
private:
	int xpos;
	int ypos;

public:

	TransformComp()
	{
		ypos = 0;
		xpos = 0;
	}

	TransformComp(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	int x() { return xpos; }
	int y() { return ypos; }
	void x(int x) { xpos = x; }
	void y(int y) { ypos = y; }

	/*
	void init() override
	{
		xpos = 0;
		ypos = 0;
	}
	*/

	void update() override
	{
		xpos++;
		ypos++;
	}

	void setPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
};