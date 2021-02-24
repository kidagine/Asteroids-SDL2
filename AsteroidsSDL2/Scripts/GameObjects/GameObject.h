#pragma once
#include "../Transform.h"
#include "../SpriteRenderer.h"


class GameObject {
public:
	GameObject();
	GameObject(Vector2D position);
	GameObject(Vector2D position, float angle);
	GameObject(Vector2D position, Vector2D scale, float angle);
	void Update();
	void Render();
	Transform _transform;
protected:
};