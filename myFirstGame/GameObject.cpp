#include "GameObject.h"
#include "TextureManager.h"
#include "Physics.h"
#include "Map.h"
#include <vector>

//double* velocity;
Physics* physics;
double xOld, yOld;
int elo;


GameObject::GameObject(const char* texturesheet, int x, int y)
{

	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	physics = new Physics;
	

}

void GameObject::UpdatePlayer1()
{
	if (alive) {

		xOld = xpos;
		yOld = ypos;

		speed = physics->SpeedIncrease();
		//elo = physics->CheckCollision(destRect, kol);

		auto kstate = SDL_GetKeyboardState(NULL);
		if (jump == false) {

			if (kstate[SDL_SCANCODE_LEFT])
				xpos -= (1.0 + speed);
			if (kstate[SDL_SCANCODE_RIGHT] /*&& !elo*/)
				xpos += (1.0 + speed);
			if (kstate[SDL_SCANCODE_UP] /*&& !elo*/) {

				jump = true;
				yposBeforeJump = ypos;
				ypos -= (44.0) + speed;
			}
			if (kstate[SDL_SCANCODE_RCTRL])
				speed = physics->SpeedDecrease();
			if (kstate[SDL_SCANCODE_DOWN] && !elo) {
				ypos += 1.0;

			}

		}
		else if (jump)
		{

			if (kstate[SDL_SCANCODE_LEFT] && !elo)
				xpos -= (1.0 + speed * 1.4);
			if (kstate[SDL_SCANCODE_RIGHT] && !elo)
				xpos += (1.0 + speed * 1.4);

			if (ypos >= yposBeforeJump) {
				jump = false;

			}
			else
				ypos += 1.0;

		}

		collider.x = xOld;
		collider.y = yOld;
		collider.h = 32;
		collider.w = 32;

		for (auto& i : collidingRects)
		{


			elo = physics->CheckCollision(collider, i);
			if (elo)
			{
				break;
			}
		}

		if (elo)
		{
			///speed = 0;
			destRect.x = xOld;
			destRect.y = yOld;
		}
		else
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













		destRect = physics->keepInFrames(destRect, xpos, ypos);
	}
}

void GameObject::UpdateEnemy()
{
	 

	if (counter <= 40)
	{
		xpos++;
		counter++;
	}
	if (counter >= 40)
	{
		xpos--;
		counter++;
	}

	if(counter == 80)
	{
		counter = 0;
	}

		

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	
	destRect.x =  objRect.x = xpos;
	destRect.y  = objRect.y = ypos;
	destRect.w  = objRect.w = 32;
	destRect.h =  objRect.h = 32;
	//std::cout << "objrect.x: " << objRect.x << " rect y = " << objRect.y << std::endl;
	
	collidingRects.push_back(getObjRect());

}
void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);


}

void GameObject::setCollidingRects(std::vector<SDL_Rect> vector)
{
	this->collidingRects = vector;
}



bool GameObject::isAlive()
{
	return alive;
};

SDL_Rect GameObject::getObjRect()
{
	return this->objRect;
}


