#include "GameObject.h"
#include "TextureManager.h"
#include "Physics.h"


//double* velocity;
Physics* physics;


GameObject::GameObject(const char* texturesheet, double x, double y)
{

	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	xpos = y;
	physics = new Physics;

}

void GameObject::UpdatePlayer1()
{
	


	speed = physics->SpeedIncrease();

	auto kstate = SDL_GetKeyboardState(NULL);
	if (jump == false) {
		if (kstate[SDL_SCANCODE_LEFT])
			xpos -= (1.0 + speed );
		if (kstate[SDL_SCANCODE_RIGHT])
			xpos += (1.0 + speed );
		if (kstate[SDL_SCANCODE_UP]) {
			jump = true;
			yposBeforeJump = ypos;
			ypos -= (45.0 + speed);				
		}
		if (kstate[SDL_SCANCODE_RCTRL])
			speed = physics->SpeedDecrease();
		if (kstate[SDL_SCANCODE_DOWN])
			ypos += (1.0 + speed);

	} else if (jump)
	{
		ypos += 2.0;
		if (kstate[SDL_SCANCODE_LEFT])
			xpos -= (1.0 + speed * 1.4);
		if (kstate[SDL_SCANCODE_RIGHT])
			xpos += (1.0 + speed * 1.4);
		
		if (ypos >= yposBeforeJump) {
			jump = false;
			
		}

	} 

	
	
	   	  
	srcRect.h = 32;
	srcRect.w = 32; 
	srcRect.x = 0;
	srcRect.y = 0;
	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

	
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

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;


}
void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);


}




