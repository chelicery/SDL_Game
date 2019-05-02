#include "Physics.h"
#include "time.h"
Physics::Physics()
{
	
}
Physics::~Physics()
{
	
}


 double Physics::SpeedDecrease()
{
	 if(multiplier > 2)
	 multiplier -= 0.2;
	 counter--;
	return abs(multiplier);
}

 double Physics::SpeedIncrease()
{

	if (counter > 80 && multiplier <8)
		multiplier += 0.0055;
	
	counter++;
	return multiplier;
	
}
double Gravity()
{
	float flPreviousTime = 0;
	float flCurrentTime = SDL_GetTicks();

	float dt = flCurrentTime - flPreviousTime;

	if (dt > 0.15f)
		dt = 0.15f;
	return dt;

}





