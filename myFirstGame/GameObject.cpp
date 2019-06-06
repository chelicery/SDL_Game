#include "GameObject.h"
#include "TextureManager.h"
#include "Physics.h"
#include "Map.h"
#include <vector>

//double* velocity;
Physics* physics;
std::vector <SDL_Rect> colls;
int elo;


GameObject::GameObject(const char* texturesheet, double x, double y)
{

	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	xpos = y;
	physics = new Physics;
	

}

void GameObject::UpdatePlayer1()
{
	double x, y;
	
	x = xpos;
	y = ypos;

	speed = physics->SpeedIncrease();
	elo = physics->CheckCollision(destRect, kol);

	auto kstate = SDL_GetKeyboardState(NULL);
	if (jump == false) {
		
		if (kstate[SDL_SCANCODE_LEFT])
			xpos -= (1.0 + speed );
		if (kstate[SDL_SCANCODE_RIGHT] && !elo)
			xpos += (1.0 + speed );
		if (kstate[SDL_SCANCODE_UP] && !elo) {

			jump = true;
			yposBeforeJump = ypos;
			ypos -= (44.0 );
		}
		if (kstate[SDL_SCANCODE_RCTRL])
			speed = physics->SpeedDecrease();
		if (kstate[SDL_SCANCODE_DOWN] && !elo ) {
			ypos += 1.0 ;
		
		} 

	} else if (jump)
	{
		ypos += 1.0;
		if (kstate[SDL_SCANCODE_LEFT] && !elo)
			xpos -= (1.0 + speed * 1.4);
		if (kstate[SDL_SCANCODE_RIGHT] && !elo)
			xpos += (1.0 + speed * 1.4);
		
		if (ypos >= yposBeforeJump) {
			jump = false;
			
		}

	}
	
	collider.x = xpos;
	collider.y = ypos;
	collider.h = 32;
	collider.w = 32;

	/*
	for (auto& i : map->colliders)
	{
	

		elo = physics->CheckCollision(destRect, i.get_box() );
		if (elo)
		{
			return;
		}
	}
	*/
	if(elo)
	{
		
		destRect.x = x;
		destRect.y = y;
	} else
	{
		destRect.x = xpos;
		destRect.y = ypos;
	}

	srcRect.h = 32;
	srcRect.w = 32; 
	srcRect.x = 0;
	srcRect.y = 0;
	

	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

	
	kol.x = 640;
	kol.y = 320;
	kol.h = 32;
	kol.w = 32;

	kol2.x = 608;
	kol2.y = 298;
	kol2.w = 32;
	kol2.h = 32;
	
	//std::cout << "x pos: " << destRect.x << "  ypos = " << destRect.y << std::endl;
	
	
		
		
	

	


	destRect = physics->keepInFrames(destRect, xpos, ypos);
}

void GameObject::UpdatePlayer2()
{



	speed = physics->SpeedIncrease();
	auto kstate = SDL_GetKeyboardState(NULL);
	if (kstate[SDL_SCANCODE_A])
		xpos -= (1.0 + speed);
	if (kstate[SDL_SCANCODE_D])
		xpos += (1.0 + speed);
	if (kstate[SDL_SCANCODE_W])
		ypos -= (1.0 + speed);
	if (kstate[SDL_SCANCODE_S])
		ypos += (1.0 + speed);
	if (kstate[SDL_SCANCODE_LCTRL]) {
		speed = physics->SpeedDecrease();

	}



	srcRect.h = 16;
	srcRect.w = 16;
	srcRect.x = 0;
	srcRect.y = 0;


	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;


}
void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);


}






