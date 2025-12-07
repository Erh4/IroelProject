// Iroel_Project.cpp : définit le point d'entrée de l'application.
//

#include "Iroel_Project.h"

using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;

bool running = true;

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Erreur d'initialisation de SDL : %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("My programm", SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (window == NULL) {
		fprintf(stderr, "Erreur de création de fenêtre : %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	renderer = SDL_CreateRenderer(window, NULL);
	if (renderer == NULL) {
		fprintf(stderr, "Erreur de création du rendu : %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	ObjectClass myObject;

	std::cout << myObject.GetName() << endl;

	SDL_FRect rect(0,0,100,100);
	int redIndex = 1, greenIndex = 1, blueIndex = 1;
	int redOffset = 1, greenOffset = 2, blueOffset = 3;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}

		redIndex += redOffset;
		greenIndex += greenOffset;
		blueIndex += blueOffset;
		if (0 >= redIndex || redIndex >= 255) {
			redOffset = -redOffset;
			redIndex += redOffset;
		}
		if (0 >= greenIndex || greenIndex >= 255) {
			greenOffset = -greenOffset;
			greenIndex += greenOffset;
		}
		if (0 >= blueIndex || blueIndex >= 255) {
			blueOffset = -blueOffset;
			blueIndex += blueOffset;
		}

		SDL_SetRenderDrawColor(renderer, redIndex, greenIndex, blueIndex, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderRect(renderer, &rect);
		


		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
	return 0;
}
