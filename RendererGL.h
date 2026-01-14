#ifndef RENDERER_GL_INCLUDE
#define RENDERER_GL_INCLUDE

#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>

struct Color {
	float r, g, b;
};

class RendererGL {
public :
	void BeginFrame(float r, float g, float b);
	void EndFrame(SDL_Window* window);

	void DrawLine(
		float x1, float y1,
		float x2, float y2,
		const Color& color);
};


#endif