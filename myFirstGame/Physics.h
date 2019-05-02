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
	


private:
	double multiplier = 1.2;
	int counter = 0;



};
