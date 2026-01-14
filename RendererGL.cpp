#include "RendererGL.h"

void RendererGL::BeginFrame(float r, float g, float b) {
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RendererGL::EndFrame(SDL_Window* window) {
	SDL_GL_SwapWindow(window);
}

static float ToGLX(float x, int width) {
	return (x / width) * 2. - 1.;
}

static float ToGLY(float y, int height) {
	return 1. - (y / height) * 2.;
}


//ETAPE 4