#include "game.h"

void fail(const char *msg) {
	std::string text = msg;
	const char *err = SDL_GetError();
	if (err) {
		text.append(": ");
		text.append(err);
	}
	SDL_ShowSimpleMessageBox(
		SDL_MESSAGEBOX_ERROR,
		"An error occurred",
		text.c_str(),
		nullptr);
	std::exit(1);
}
