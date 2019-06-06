#pragma once
#include <SDL.h>


class Tile
{
	Tile(int posX, int posY);
	~Tile();
	
	

public:
	const int TILE_WIDTH = 32;
	const int TILE_HEIGHT = 32;


	SDL_Rect get_box();
	SDL_Rect box;
};