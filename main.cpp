#include "game.h"
#include "GameObject.h"
#include "Cat.h"
#include "Mouse.h"
#include <SDL.h>

SDL_Renderer * renderer; // Needs to be outside so the GameObject can access it
SDL_Event event; // Needs to be global so the mouse can access it

int main(int argc, char ** argv)
{
	// variables

	bool quit = false;
	//SDL_Event event;
	int x = 288;
	int y = 208;

	// init SDL

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window * window = SDL_CreateWindow("SDL2 Keyboard/Mouse events",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

	renderer = SDL_CreateRenderer(window, -1, 0);

	Cat * cat = new Cat();
	Mouse *mouse = new Mouse();

	// update surface
	SDL_UpdateWindowSurface(window);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	// handle events

	while (!quit)
	{
		SDL_Delay(5);
		SDL_PollEvent(&event);

		// Display pointer coordinates, close window
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_MOUSEMOTION:
			int mouseX = event.motion.x;
			int mouseY = event.motion.y;

			std::stringstream ss;
			ss << "X: " << mouseX << " Y: " << mouseY;

			SDL_SetWindowTitle(window, ss.str().c_str());
			break;
		}

		SDL_RenderClear(renderer);

		// whatever you render first will be on the botto
		SDL_RenderCopy(renderer, mouse->getImage(), NULL, &(mouse->getPosition()));
		SDL_RenderCopy(renderer, cat->getImage(), NULL, &(cat->getPosition()));
		cat->update();
		mouse->update();
		SDL_RenderPresent(renderer);

		// Cat - mouse collision detection
		if ((mouse->getPosition().x + mouse->getPosition().w > cat->getPosition().x) &&
			(mouse->getPosition().y + mouse->getPosition().h > cat->getPosition().y) &&
			(mouse->getPosition().x < cat->getPosition().x + cat->getPosition().w) &&
			(mouse->getPosition().y < cat->getPosition().y + cat->getPosition().h))
		{
			// Cat and mouse collide!
			
			// system("pause");
			quit = true;

			// Show a message before closing window.
			/*while (1)
			{
				if (event.type == SDL_KEYDOWN)
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_UP:
						SDL_Window * death = SDL_CreateWindow("Game Over!",
							SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 100, 0);
						cout << "cat got you" << endl;
						quit = true;
						break;
					}
						
				}
			}*/
			
		}
	}

	// cleanup SDL

	//SDL_DestroyTexture(textureMouse); // now in Game Object destructor
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}