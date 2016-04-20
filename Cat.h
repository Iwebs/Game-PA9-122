#pragma once

#include "game.h"
#include "GameObject.h"
#include <time.h>

class Cat : public GameObject
{
public:
	Cat(int newSpeed = 1);
	~Cat();

	void update(); // maybe ask the user at the beginning for a difficulty level, then call different update functions, random, follow, or something else
	void generateNewDirection(); // randomly choose new direction, reset counter to 0
private:
	int counter; // keeps track of when to change direction
	string direction;
	int speed; // can make the cat go different speeds
};

Cat::Cat(int newSpeed) : GameObject("cartoon_cat.bmp", {300, 300, 85, 85}, 2)
{
	counter = 0;
	direction = "down";
	speed = newSpeed;
}

Cat::~Cat()
{
	
}

void Cat::update()
{
	// Random movement.  Also, the cat can jump onto and over walls, because it is a cat.  This means we don't need to check
	// to see if it is running into the walls.  The cat also occationally pauses because it is not allowed to go outside the 
	// bounds of the screen and tries to randomly select the same direction.  However, real cats also pause, so we decided this 
	// was acceptable, especially since it never pauses for more than a second or two.  The speed of the cat can be changed, but
	// the defuault (1, the minumum) is already fairly quick.

	srand((unsigned int)time(NULL));

	int maxCount = 5; // after this the cat must change directions
	int minX = 0;
	int maxX = 800 - position.w; // width of screen - width of cat
	int minY = 0;
	int maxY = 600 - position.h; // height of window - height of cat 
	int newDirection = 0;
	
	if (direction == "down" && (maxY > position.y + speed))
		position.y += speed; // remember that positive y is down
	else if (direction == "up" && (minY < position.y - speed))
		position.y -= speed;
	else if (direction == "right" && (maxX > position.x + speed))
		position.x += speed;
	else if (direction == "left" && (minX < position.x - speed))
		position.x -= speed;
	else if (direction == "upRight" && (minY < position.y - speed) && (maxX > position.x + speed))
	{
		position.y -= speed;
		position.x += speed;
	}
	else if (direction == "downRight" && (maxY > position.y + speed) && (maxX > position.x + speed))
	{
		position.y += speed;
		position.x += speed;
	}
	else if (direction == "upLeft" && (minY < position.y - speed) && (minX < position.x - speed))
	{
		position.y -= speed;
		position.x -= speed;
	}
	else if (direction == "downLeft" && (maxY > position.y + speed) && (minX < position.x - speed))
	{
		position.y += speed;
		position.x -= speed;
	}
	else
		generateNewDirection();

	counter++;

	if (counter > maxCount) // if the cat has been going in the same direction for too long, give it an opporunity to change
		generateNewDirection();
}

void Cat::generateNewDirection()
{
	int newDirection = rand() % 8;

	if (newDirection == 0)
		direction = "down";
	else if (newDirection == 1)
		direction = "up";
	else if (newDirection == 2)
		direction = "right";
	else if (newDirection == 3)
		direction = "left";
	else if (newDirection == 4)
		direction = "upRight";
	else if (newDirection == 5)
		direction = "downRight";
	else if (newDirection == 6)
		direction = "upLeft";
	else if (newDirection == 7)
		direction = "downLeft";

	counter = 0;
}