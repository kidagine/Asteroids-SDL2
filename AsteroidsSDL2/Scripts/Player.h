#pragma once
#include "GameObject.h"

class Player : public GameObject {
public:
	Player() : GameObject{} {}
	void Update()
	{
		GameObject::Update();
	}
	void Render()
	{
		GameObject::Render();
	}
private:
};