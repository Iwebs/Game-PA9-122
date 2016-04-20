#pragma once

#include "GameObject.h"

extern SDL_Event event;

class Mouse : public GameObject
{
public:
	Mouse(int newSpeed = 1);
	~Mouse();

	void update();
	
private:
	
};

Mouse::Mouse(int newSpeed) : GameObject("cartoon_mouse.bmp", { 100, 100, 50, 50 }, 2)
{
	
}

Mouse::~Mouse()
{

}

void Mouse::update()
{
	bool quit;
	int minX = 0;
	int maxX = 800 - position.w; // width of screen - width of cat
	int minY = 0;
	int maxY = 600 - position.h; // height of window - height of cat 

	switch (event.type)
	{
	case SDL_QUIT:
		quit = true;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT: 
			if (position.x - 1 > minX) // check function for block collision
				position.x--; break;
		case SDLK_RIGHT: 
			if (position.x + 1 < maxX)
				position.x++; break;
		case SDLK_UP:    
			if (position.y - 1 > minY)
				position.y--; break;
		case SDLK_DOWN:  
			if (position.y + 1 < maxY)
				position.y++; break;
		}
	}
}