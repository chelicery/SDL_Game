#pragma once
#include <SDL.h>

class Tile
{
	Tile();
	~Tile();

private:
	SDL_Rect box;

	int type;

public:
	Tile(int x, int y, int tileType);

	void show();

	int get_type();
	SDL_Rect get_box();

};