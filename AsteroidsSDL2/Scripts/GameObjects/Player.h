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
		CheckBounds();
	}
	void Render()
	{
		GameObject::Render();
		_spriteRenderer.Render();
	}
	void Initialize();
	void Movement();
	void CheckBounds();
	SpriteRenderer _spriteRenderer;
private:
	bool hasShot;
	int movementSpeed = 3;
	int rotationSpeed = 5;
};