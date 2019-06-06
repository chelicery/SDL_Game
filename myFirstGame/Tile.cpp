#include "Tile.h"

Tile::Tile(int x, int y)
{
	box.x = x;
	box.y = y;
	box.w = TILE_WIDTH;
	box.h = TILE_HEIGHT;
}

SDL_Rect Tile::get_box()
{
	return box;
}


