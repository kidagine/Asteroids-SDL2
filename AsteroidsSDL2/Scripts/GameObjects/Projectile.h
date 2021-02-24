#pragma once
#include "GameObject.h"

class Projectile : public GameObject {
public:
	Projectile() : GameObject{} {}
	Projectile(Vector2D position, float angle) : GameObject(position, angle)
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
	bool isDestroyed;
};