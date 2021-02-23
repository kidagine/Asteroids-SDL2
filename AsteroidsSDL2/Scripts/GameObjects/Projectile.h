#pragma once
#include "GameObject.h"

class Projectile : public GameObject {
public:
	Projectile() : GameObject{} {}
	Projectile(Vector2D position) : GameObject(position)
	{
		Initialize();
	}
	void Update()
	{
		GameObject::Update();
		Launch();
		HasCollided();
	}
	void Render()
	{
		GameObject::Render();
		_spriteRenderer.Render();
	}
	void Initialize();
	void Launch();
	void HasCollided();
protected:
	SpriteRenderer _spriteRenderer;
private:
};