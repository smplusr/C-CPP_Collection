#include <../include/SDL/SDL.h>

#include <iostream>

int main()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("[ERROR]: Could not initialize SDL: %s\n", SDL_GetError());

	SDL_Window* window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 0);
	
	while(true){}
	
	return 0;
}
