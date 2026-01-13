// Iroel_Project.cpp : définit le point d'entrée de l'application.
//

#include "Iroel_Project.h"


using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;


Uint64 NOW = SDL_GetPerformanceCounter();
Uint64 LAST = 0;
double deltaTime = 0;

bool running = true;
float SCALE = 100;
float SCALEX = SCALE;
float SCALEY = SCALE;
float SCALEZ = SCALE;
float offsetX = -SCALE/2 + SCREEN_WIDTH/2;
float offsetY = -SCALE/2 + SCREEN_HEIGHT/2;
float offsetZ = 0;

float ROTATEX = 0;
float ROTATEY = 0;
float ROTATEZ = 0;


vector<Coordinate> vertices = {
					Coordinate((0 * SCALEX) + offsetX,(0 * SCALEY) + offsetY,(0 * SCALEZ) + offsetZ),
					Coordinate((1 * SCALEX) + offsetX,(0 * SCALEY) + offsetY,(0 * SCALEZ) + offsetZ),
					Coordinate((0 * SCALEX) + offsetX,(1 * SCALEY) + offsetY,(0 * SCALEZ) + offsetZ),
					Coordinate((1 * SCALEX) + offsetX,(1 * SCALEY) + offsetY,(0 * SCALEZ) + offsetZ)
};


vector<Edge> edges = {
					Edge(&vertices[0], &vertices[1]),
					Edge(&vertices[0], &vertices[2]),
					Edge(&vertices[0], &vertices[3]),
					Edge(&vertices[2], &vertices[3]),
					Edge(&vertices[1], &vertices[3]),
};

vector<Triangle> triangles = {
				Triangle(&edges[2], &edges[1], &edges[3]),
				Triangle(&edges[0], &edges[4], &edges[2])
};




int redIndex = 1, greenIndex = 1, blueIndex = 1;
int redOffset = 1, greenOffset = 2, blueOffset = 3;


void update() {

	ROTATEX++;
	if (ROTATEX / 360 >= 1) {
		ROTATEX = 0;
	}

	if (ROTATEX < 180) {
		offsetY = 1;
	}
	else {
		offsetY = -1;
	}
	for (Coordinate &vertice : vertices) {
		vertice.UpdateCoordinatePosition(vertice.x + offsetX, vertice.y + offsetY, vertice.z + offsetZ);
		
	}
	cout << vertices[0].x << ";" << vertices[0].y << ";"<< vertices[0].z << endl;
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
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	triangles[0].RenderTriangle(renderer);
	triangles[1].RenderTriangle(renderer);

	SDL_RenderPresent(renderer);
	SDL_Delay(1000 / FRAMERATE);
}

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

	offsetX = 0;
	offsetY = 0;
	offsetZ = 0;

	while (running) {

		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();

		deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());


		update();
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
	return 0;
}


