#pragma once

#include <SDL.h>     
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cctype>
#include <string>
using std::string;

#include <sstream>


extern SDL_Renderer *renderer;
class GameObject
{
public:
	GameObject(char * filename = "block.bmp", SDL_Rect initial = {0}, int newID = 0);
	~GameObject();

	SDL_Rect getPosition();
	SDL_Surface * getPicture();
	SDL_Texture * getImage();
	
	virtual void update() = 0; // Update does nothing for block, is random for cat, and is controled by keyboard for mouse

protected:
	 // x, y, height, width
	SDL_Rect position; // protectd
	int id; // 0 = block, 1 = mouse, 2 = cat
private:
	SDL_Surface * picture; // private
	SDL_Texture * image; // private
};

GameObject::GameObject(char * filename, SDL_Rect initial, int newID)
{
	picture = SDL_LoadBMP(filename);
	image = SDL_CreateTextureFromSurface(renderer, picture);
	position = initial;
	id = newID;
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(image);
}

SDL_Rect GameObject::getPosition()
{
	return position;
}
SDL_Surface * GameObject::getPicture()
{
	return picture;
}
SDL_Texture * GameObject::getImage()
{
	return image;
}