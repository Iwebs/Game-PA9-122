#include "gameobject.h"
extern SDL_Event event;

class Score : public GameObject
{
public:

	Score(char * filename = "zero.bmp", SDL_Rect newP = { 213, 294, 40, 40 });
	~Score();

	void update();

private:

};

Score::~Score()
{
}

Score::Score(char * filename, SDL_Rect newP) : GameObject(filename, newP, 4)
{

}

void Score::update()
{
	return;
}
