#ifndef Game_hpp
#define Game_hpp
#pragma once
#include "SDL.h"
#include <iostream>
#include "SDL_image.h"
class Game
{
public:
	
	Game();
	~Game();
		void init(const char*, int width, int height, bool fullscreen);
		void handleEvents();		
		void render();
		void update();
		void clean();
		bool running() { return isRunning; };

		static SDL_Renderer *renderer;
		static SDL_Event event;
	private:
		int cnt = 0;
		bool isRunning;
		SDL_Window *window;
		


};
#endif
