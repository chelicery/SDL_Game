#pragma once
#include "Game.h"
#include <vector>
#include "Map.h"

class GameObject
{
	
public:
	GameObject(const char* textureshee, int x, int y);
	~GameObject();
	void UpdatePlayer1();
	void UpdateEnemy();
	void Render();
	void setCollidingRects(std::vector<SDL_Rect> vector);
	bool isAlive();
	int counter;
	SDL_Rect getObjRect();
	void killHim(GameObject player);


private:
	bool alive = true;
	bool jump;
	double yposBeforeJump;
	double xpos;
	double ypos;
	double speed;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect, collider;
	SDL_Renderer* renderer;	
	std::vector <SDL_Rect> collidingRects;
	SDL_Rect objRect;
};
