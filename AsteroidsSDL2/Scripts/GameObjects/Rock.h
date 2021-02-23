#pragma once
#include "GameObject.h"

class Rock : public GameObject {
	int id;
public:
	bool operator == (const Rock& r) const { return id == r.id; }
	Rock() : GameObject{} {}
	Rock(Vector2D position, float angle) : GameObject(position, angle)
	{
		Initialize();
	}
	void Update()
	{
		GameObject::Update();
		Launch();
		CheckBounds();
	}
	void Render()
	{
		GameObject::Render();
		_spriteRenderer.Render();
	}
	void Initialize();
	void Launch();
	void CheckBounds();
	void HasCollided(SDL_Rect b);
	SpriteRenderer _spriteRenderer;
private:
	int speed = 1;
	int randomAngle = 0;
};