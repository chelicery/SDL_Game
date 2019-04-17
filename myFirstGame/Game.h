#ifndef Game_hpp
#define Game_hpp
#pragma once
#include "SDL.h"

class Game
{
public:
	Game();
	~Game();
		void init(const char*, int xpos, int ypos, int width, int height, bool fullscreen);
		void handleEvents();
		
		void render();
		void update();
		void clean();
		bool running() { return isRunning; };
	private:
		bool isRunning;
		SDL_Window *window;
		SDL_Renderer *renderer;


};
#endif
