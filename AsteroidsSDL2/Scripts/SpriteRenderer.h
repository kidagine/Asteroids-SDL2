#pragma once
#include "Game.h"

class SpriteRenderer {
public:
	SpriteRenderer();
	SpriteRenderer(const char* pathName);
	void Render();
	void SetSprite(const char* pathName);
	SDL_Rect _rect;
	float _angle = 0;
private:
	SDL_Texture* _texture;
};