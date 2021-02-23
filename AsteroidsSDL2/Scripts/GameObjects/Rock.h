#pragma once
#include "GameObject.h"

class Rock : public GameObject {
	int id;
public:
	bool operator == (const Rock& r) const { return id == r.id; }

	Rock() : GameObject{} {}
	Rock(Vector2D position) : GameObject(position)
	{
		Initialize();
	}
	void Update()
	{
		GameObject::Update();
		Launch();
	}
	void Render()
	{
		GameObject::Render();
		_spriteRenderer.Render();
	}
	void Initialize();
	void Launch();
protected:
	SpriteRenderer _spriteRenderer;

private:
};