#pragma once

#include "GameObject.h"

class Physics
{

public:
	Physics();
	~Physics();
	 double SpeedIncrease();
	 double SpeedDecrease();
	 double Gravity();
	 bool CheckCollision(SDL_Rect a , SDL_Rect b);
	 SDL_Rect keepInFrames(SDL_Rect obj, double xpos, double ypos);

private:
	double multiplier = 1.2;
	int counter = 0;



};
