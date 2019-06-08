#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	Player(const char* texturesheet, int x, int y);
	~Player();
	void UpdatePlayer1();

};

