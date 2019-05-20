#pragma once
#include <SDL.h>
const int TILE_WIDTH = 64; 
const int TILE_HEIGHT = 64; 
const int TOTAL_TILES = 192; 
const int TILE_SPRITES = 3; //The different tile sprites 
const int TILE_GRASS = 0; 
const int TILE_DIRT = 1; 
const int TILE_SKY = 2; 

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