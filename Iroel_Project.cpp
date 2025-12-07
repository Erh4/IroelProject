// Iroel_Project.cpp : définit le point d'entrée de l'application.
//

#include "Iroel_Project.h"
#include <SDL3/SDL.h>

using namespace std;


static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr;
bool run = true;
int main()
{
	cout << "Hello CMake." << endl;
	if (!SDL_CreateWindowAndRenderer("Hello World", 800, 600, SDL_WINDOW_FULLSCREEN, &window, &renderer))
	{
		SDL_Log("Couldn't create window and rendrer: %s", SDL_GetError());
		return -1;
	}

	return 0;
}
