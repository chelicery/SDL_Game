#pragma once

#include "Game.h"

class TextureManager
{
	
public:
	static SDL_Texture* LoadTexture(const char* fileName );
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
	void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL) {};
	SDL_Rect clip[4];
};
