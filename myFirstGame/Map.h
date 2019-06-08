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
	std::vector<SDL_Rect> getColliders();




private:
	SDL_Rect src, dest;
	SDL_Texture *dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	std::vector<SDL_Rect> colliders;
	int map[20][40];



};
