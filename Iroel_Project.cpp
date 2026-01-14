// Iroel_Project.cpp : définit le point d'entrée de l'application.
//

#include "Iroel_Project.h"

using namespace std;

SDL_Window* window = NULL;
RendererGL renderer;
SDL_Event event;

Uint64 NOW = SDL_GetPerformanceCounter();
Uint64 LAST = 0;
double deltaTime = 0;
float cameraX = SCREEN_WIDTH / 2;
float cameraY = SCREEN_HEIGHT / 2;
float FOV = 150;
bool running = true;
float SCALE = 100;
float SCALEX = SCALE;
float SCALEY = SCALE;
float SCALEZ = SCALE;
float offsetX = 0;
float offsetY = 0;
float offsetZ = 0;

float ROTATEX = 0;
float ROTATEY = 0;
float ROTATEZ = 0;


int face1 = 0; //FRONT FACE
int face2 = 4; //BACK FACE

vector<Coordinate> vertices = {};

Coordinate tempAB; 
Coordinate tempAC;

vector<float> tempA;
vector<float> tempB;
vector<float> tempC;
vector<float> tempD;
vector<float> N;

vector<Edge> edges = {};

vector<Triangle> triangles = {};

Camera camera(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 1/tan(FOV/2));


int redIndex = 1, greenIndex = 1, blueIndex = 1;
int redOffset = 1, greenOffset = 2, blueOffset = 3;

vector<float> normalizeVector(vector<float> vec) {
	float maxi = vec.at(0);

	for (int i = 0; i < vec.size(); i++) {
		if (maxi < vec.at(i)) {
			maxi = vec.at(i);
		}
	}
	//cout << maxi<<endl;;
	for (int i = 0; i < vec.size(); i++) {
		vec.at(i) /= maxi;
	}
	return vec;
}

vector<float> multiplyVectorFloat(vector<float> vec, float mult) {
	for (int i = 0; i < vec.size(); i++) {
		vec.at(i) *= mult;
	}
	return vec;
}

vector<float> addVector(vector<float> vec1, vector<float> vec2) {
	vector<float> vec = {};
	for (int i = 0; i < vec1.size(); i++) {
		vec.push_back(vec1.at(i)+vec2.at(i));
	}
	return vec;
}
void update() {

	ROTATEX++;
	if (ROTATEX / 360 >= 1) {
		ROTATEX = 0;
	}

	if (ROTATEX < 90) {
		camera.position.x++;
		offsetX = 1;
	}
	if (ROTATEX >= 90 && ROTATEX < 180) {
		camera.position.y++;
	}
	if (ROTATEX >= 180 && ROTATEX < 270) {
		camera.position.x--;
		offsetX = -1;
	}
	if (ROTATEX >= 270 && ROTATEX < 360) {
		camera.position.y--;
	}

	for (Coordinate &vertice : vertices) {
		//vertice.UpdateCoordinatePosition(vertice.x + offsetX, vertice.y + offsetY, vertice.z + offsetZ);
		//vertice.addToPosition({ offsetX, 0,0 });
	}

	//cout << vertices[0].x << ";" << vertices[0].y << ";"<< vertices[0].z << endl;
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

	renderer.BeginFrame(redIndex/255.,greenIndex/255., blueIndex/255.);
	renderer.EndFrame(window);

	//SDL_SetRenderDrawColor(renderer, redIndex, greenIndex, blueIndex, 255);
	//SDL_RenderClear(renderer);
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	for (Triangle triangle : triangles) {
		//triangle.RenderTriangle(renderer, &camera);
	}


	//SDL_RenderPresent(renderer);
	SDL_Delay(1000 / FRAMERATE);
}

int main()
{

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
						SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Erreur d'initialisation de SDL : %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("My program", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL |SDL_WINDOW_RESIZABLE);

	if (window == NULL) {
		fprintf(stderr, "Erreur de création de fenêtre : %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	if (!glContext) {
		SDL_Log("OpenGL context creation error ; %s", SDL_GetError());
	}

	SDL_GL_MakeCurrent(window, glContext);
	SDL_GL_SetSwapInterval(1);


	//renderer = SDL_CreateRenderer(window, NULL);
	//if (renderer == NULL) {
	//	fprintf(stderr, "Erreur de création du rendu : %s\n", SDL_GetError());
	//	SDL_Quit();
	//	return 1;
	//}



	//FRONT FACE
	vertices.push_back(Coordinate(0, 0, 1));
	vertices.push_back(Coordinate(100, 0, 1));
	vertices.push_back(Coordinate(0, 100, 1));
	vertices.push_back(Coordinate(100, 100, 1));

	//vertices.push_back(Coordinate((0 * SCALEX) + (cameraX - SCALEX / 2), (0 * SCALEY) + (cameraY - SCALEY / 2), (0 * SCALEZ) + offsetZ));
	//vertices.push_back(Coordinate((1 * SCALEX) + (cameraX - SCALEX / 2), (0 * SCALEY) + (cameraY - SCALEY / 2), (0 * SCALEZ) + offsetZ));
	//vertices.push_back(Coordinate((0 * SCALEX) + (cameraX - SCALEX / 2), (1 * SCALEY) + (cameraY - SCALEY / 2), (0 * SCALEZ) + offsetZ));
	//vertices.push_back(Coordinate((1 * SCALEX) + (cameraX - SCALEX / 2), (1 * SCALEY) + (cameraY - SCALEY / 2), (0 * SCALEZ) + offsetZ));

	//vertices.push_back(Coordinate((0 * SCALEX) + (cameraX - SCALEX / 2), (0 * SCALEY) + (cameraY - SCALEY / 2), (0 * SCALEZ) + offsetZ));
	//vertices.push_back(Coordinate((2 * SCALEX) + (cameraX - SCALEX / 2), (0 * SCALEY) + (cameraY - SCALEY / 2), (0 * SCALEZ) + offsetZ));
	//vertices.push_back(Coordinate((0 * SCALEX) + (cameraX - SCALEX / 2), (2 * SCALEY) + (cameraY - SCALEY / 2), (0 * SCALEZ) + offsetZ));
	//vertices.push_back(Coordinate((2 * SCALEX) + (cameraX - SCALEX / 2), (2 * SCALEY) + (cameraY - SCALEY / 2), (0 * SCALEZ) + offsetZ));

	tempAB = Coordinate(vertices[1].x - vertices[0].x,
						vertices[1].y - vertices[0].y,
						vertices[1].z - vertices[0].z);

	tempAC = Coordinate(vertices[2].x - vertices[0].x,
						vertices[2].y - vertices[0].y,
						vertices[2].z - vertices[0].z);

	N = { tempAB.y * tempAC.z - tempAB.z * tempAC.y,
		  tempAB.z * tempAC.x - tempAB.x * tempAC.z,
		  tempAB.x * tempAC.y - tempAB.y * tempAC.x };

	N = normalizeVector(N);




	tempA = addVector(vertices[0].getVector(), multiplyVectorFloat(N, 1));
	tempB = addVector(vertices[1].getVector(), multiplyVectorFloat(N, 1));
	tempC = addVector(vertices[2].getVector(), multiplyVectorFloat(N, 1));
	tempD = addVector(vertices[3].getVector(), multiplyVectorFloat(N, 1));


	std::cout << N.at(0) << "," << N.at(1) << "," << N.at(2) << endl;

	//BACK FACE
	vertices.push_back(Coordinate(tempA.at(0), tempA.at(1), tempA.at(2)));
	vertices.push_back(Coordinate(tempB.at(0), tempB.at(1), tempB.at(2)));
	vertices.push_back(Coordinate(tempC.at(0), tempC.at(1), tempC.at(2)));
	vertices.push_back(Coordinate(tempD.at(0), tempD.at(1), tempD.at(2)));



	//vertices.push_back(Coordinate(tempA.at(0) + (cameraX - SCALEX / 2), tempA.at(1) + (cameraY - SCALEY / 2), tempA.at(2)));
	//vertices.push_back(Coordinate(tempB.at(0) + (cameraX - SCALEX / 2), tempB.at(1) + (cameraY - SCALEY / 2), tempB.at(2)));
	//vertices.push_back(Coordinate(tempC.at(0) + (cameraX - SCALEX / 2), tempC.at(1) + (cameraY - SCALEY / 2), tempC.at(2)));
	//vertices.push_back(Coordinate(tempD.at(0) + (cameraX - SCALEX / 2), tempD.at(1) + (cameraY - SCALEY / 2), tempD.at(2)));



	//vertices.push_back(Coordinate((0 * SCALEX) + offsetX, (0 * SCALEY) + offsetY, (0 * SCALEZ) + offsetZ));
	//vertices.push_back(Coordinate((1 * SCALEX) + offsetX, (0 * SCALEY) + offsetY, (0 * SCALEZ) + offsetZ));
	//vertices.push_back(Coordinate((0 * SCALEX) + offsetX, (1 * SCALEY) + offsetY, (0 * SCALEZ) + offsetZ));
	//vertices.push_back(Coordinate((1 * SCALEX) + offsetX, (1 * SCALEY) + offsetY, (0 * SCALEZ) + offsetZ));

	//vertices.push_back(Coordinate((0 * SCALEX) + offsetX, (0 * SCALEY) + offsetY, (1 * SCALEZ) + offsetZ));
	//vertices.push_back(Coordinate((1 * SCALEX) + offsetX, (0 * SCALEY) + offsetY, (1 * SCALEZ) + offsetZ));
	//vertices.push_back(Coordinate((0 * SCALEX) + offsetX, (1 * SCALEY) + offsetY, (1 * SCALEZ) + offsetZ));
	//vertices.push_back(Coordinate((1 * SCALEX) + offsetX, (1 * SCALEY) + offsetY, (1 * SCALEZ) + offsetZ));



	//cout << N.at(0) << "," << N.at(1) << "," << N.at(2) << endl;
	
	//cout << N.at(0) << "," << N.at(1) << "," << N.at(2) << endl;


	edges.push_back(Edge(&vertices[0 + face1], &vertices[1 + face1]));
	edges.push_back(Edge(&vertices[0 + face1], &vertices[2 + face1]));
	edges.push_back(Edge(&vertices[0 + face1], &vertices[3 + face1]));
	edges.push_back(Edge(&vertices[2 + face1], &vertices[3 + face1]));
	edges.push_back(Edge(&vertices[1 + face1], &vertices[3 + face1]));

	edges.push_back(Edge(&vertices[0 + face2], &vertices[1 + face2]));
	edges.push_back(Edge(&vertices[0 + face2], &vertices[2 + face2]));
	edges.push_back(Edge(&vertices[0 + face2], &vertices[3 + face2]));
	edges.push_back(Edge(&vertices[2 + face2], &vertices[3 + face2]));
	edges.push_back(Edge(&vertices[1 + face2], &vertices[3 + face2]));

		
	triangles.push_back(Triangle(&edges[2], &edges[1], &edges[3]));
	triangles.push_back(Triangle(&edges[0], &edges[4], &edges[2]));
	triangles.push_back(Triangle(&edges[2 + 5], &edges[1 + 5], &edges[3 + 5]));
	triangles.push_back(Triangle(&edges[0 + 5], &edges[4 + 5], &edges[2 + 5]));
	offsetX = 0;
	offsetY = 0;
	offsetZ = 0;


	while (running) {

		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();

		deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());


		update();
	}
	//SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
	return 0;
}


