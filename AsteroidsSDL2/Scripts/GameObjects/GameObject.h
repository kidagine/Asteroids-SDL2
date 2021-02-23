#pragma once
#include "../Transform.h"
#include "../SpriteRenderer.h"


class GameObject {
public:
	GameObject();
	GameObject(Vector2D position);
	GameObject(Vector2D position, float angle);
	void Update();
	void Render();
protected:
	Transform _transform;
};