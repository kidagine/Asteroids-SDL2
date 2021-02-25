#include "Game.h"
#include "SpriteRenderer.h"

#ifdef __EMUSCRIPTEN__
#include <emscripten.h>
#endif

const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;
const char* TITLE = "Asteroids";


int main(int argc, char* args[])
{
	Uint32 frameStart;
	int frameTime;

	Game game;
	game.Initialize(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);

	while (game.Running())
	{
		frameStart = SDL_GetTicks();
		if (0 < SDL_GetTicks())
		{
			game.Update();
			game.Render();
		}
		frameTime = SDL_GetTicks() - frameStart;
		if (FRAME_DELAY > frameTime)
		{
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}
	
	game.Terminate();
	return 0;
}
