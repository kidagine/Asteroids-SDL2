#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <list>
#include "Vector2D.h"

class Game {
public:
	Game();
	void Initialize(const char* title, int width, int height);

	bool Running();
	void Update();
	void Render();
	void Terminate();

	void static Instantiate();
	void static Instantiate(Vector2D position);
	static SDL_Renderer* renderer;
private:
	bool isRunning;
};