#include "pch.h"
#include <glad\glad.h>
#include "Engine/Graphics/Renderer.h"

int main(int argc, char** argv)
{
	nc::Renderer renderer;
	renderer.Startup();
	renderer.Create("OpenGL", 800, 600);

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
		}

		SDL_PumpEvents();

		renderer.BeginFrame();

		glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.5f, -0.5f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.0f, 0.5f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.5f, -0.5f);

		glEnd();

		renderer.EndFrame();
	}

	return 0;
}
