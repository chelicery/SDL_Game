#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject* player; GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char *title, int width, int height, bool fullscreen)
{
	int flags = 0;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised .." << std::endl;
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (window)
		{
			std::cout << "window created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			std::cout << "Renderer created" << std::endl;
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			
		}
		isRunning = true;


		player = new GameObject("assets/player1.png",0,0);
		enemy = new GameObject("assets/enemy.png", 100, 100);
		map = new Map();
		

	} else
		{
			isRunning = false;
		}


	
}

void Game::handleEvents()
{
	
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}


} 

void Game::render()
{
		SDL_RenderClear(renderer);
		map->DrawMap();
		player->Render();
		enemy->Render();
		
		SDL_RenderPresent(renderer);
}


void Game::update()
{
	player->UpdatePlayer1();
	enemy->UpdatePlayer2();

}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
		std::cout << "game cleaned " << std::endl;

}




