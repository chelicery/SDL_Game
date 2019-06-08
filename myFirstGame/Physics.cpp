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

 bool Physics::CheckCollision(SDL_Rect a, SDL_Rect b)
 {
	 int leftA, leftB;
	 int rightA, rightB;
	 int topA, topB;
	 int bottomA, bottomB;

	 leftA = a.x;
	 rightA = a.x + a.w;
	 topA = a.y;
	 bottomA = a.y + a.h;


	 leftB = b.x;
	 rightB = b.x + b.w;
	 topB = b.y;
	 bottomB = b.y + b.h;
	 //std::cout << "bottom A " << bottomA << "top b" << topB<< std::endl;
	 if ((bottomA >= topB) && (rightA >= leftB) && (leftA <= rightB) )
	 {
		 std::cout << "collision from bottom " << bottomA << "top b" << topB << std::endl;
		// std::cout << "collision 1 " << std::endl;
		 return true;
	 }

	//if(((topA >= bottomB) && (bottomA <=topB)) && ((rightA >=leftB) || (leftA <= rightB)))
	//{
	//	std::cout << "collitinio from top " << bottomA << "top b" << topB << std::endl;
		// std::cout << "collision 1 " << std::endl;
	//	return true;
	//}


	 return false;
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

SDL_Rect Physics::keepInFrames(SDL_Rect obj, double xpos, double ypos)
{
	
	if ((obj.x < 0) || (obj.x + 32 > 1240) )
	{
		obj.x = xpos = 0;
		SpeedDecrease();
		std::cout << "keep" << std::endl;
	}

	return obj;
}









