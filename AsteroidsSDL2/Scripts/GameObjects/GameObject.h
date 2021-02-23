#pragma once
#include "../Transform.h"
#include "../SpriteRenderer.h"


class GameObject {
public:
	GameObject();
	GameObject(Vector2D position);
	void Update();
	void Render();
protected:
	Transform _transform;
};