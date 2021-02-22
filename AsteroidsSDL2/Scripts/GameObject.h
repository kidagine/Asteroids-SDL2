#pragma once
#include "Game.h"
#include "SpriteRenderer.h"
#include "Transform.h"

class GameObject {
public:
	GameObject();
	void Update();
	void Render();
private:
	SpriteRenderer _spriteRenderer;
	Transform _transform;
};