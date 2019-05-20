#include "Tile.h"

Tile::Tile(int x, int y, int tileType)
{
	box.x = x;
	box.y = y;

	box.w = TILE_WIDTH;
	box.h = TILE_HEIGHT;

	type = tileType;

}

void Tile::show()
{
	//apply_surface(box.x, box.y, tileSheet, screen, &clips[type ]);

}
