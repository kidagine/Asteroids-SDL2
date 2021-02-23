#pragma once
#include "GameObject.h"

class Player : public GameObject {
public:
	Player() : GameObject{} {}
	Player(Vector2D position) : GameObject(position) 
	{
		Initialize();
	}
	void Update()
	{
		GameObject::Update();
		Movement();
	}
	void Render()
	{
		GameObject::Render();
		_spriteRenderer.Render();
	}
	void Initialize();
	void Movement();
protected:
	SpriteRenderer _spriteRenderer;
private:
};