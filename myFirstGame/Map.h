#pragma once
#include "Game.h"
#include <vector>
#include "Tile.h"
class Map
{
	

public:
	Map();
	~Map();

	void LoadMap(int arr[20][40]);
	void DrawMap();
	//std::vector<class Tile> colliders;





private:
	SDL_Rect src, dest;
	SDL_Texture *dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][40];



};
