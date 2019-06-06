#pragma once
#include "Game.h"
#include <vector>
#include "Map.h"

class GameObject
{
	
public:
	GameObject(const char* textureshee, double x, double y);
	~GameObject();
	void UpdatePlayer1();
	void UpdatePlayer2();
	void Render();
	



private:

	bool jump;
	double yposBeforeJump;
	double xpos;
	double ypos;
	double speed;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect, kol, collider, kol2;

	SDL_Renderer* renderer;
	



};
