#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Game {
public:
	Game();
	void Initialize(const char* title, int width, int height);

	bool Running();
	void Update();
	void Render();
	void Terminate();

	static SDL_Renderer* renderer;
private:
	bool isRunning;
};