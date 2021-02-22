#pragma once
#include "Game.h"

class SpriteRenderer {
public:
	SpriteRenderer();
	SpriteRenderer(const char* pathName);
	void Render();
	SDL_Rect _rect;
private:
	SDL_Texture* _texture;
};