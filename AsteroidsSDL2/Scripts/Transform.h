#pragma once
#pragma once
#include "Game.h"
#include "Vector2D.h"

class Transform {
public:
	Transform();
	Vector2D position;
	float angle = 0;
	Vector2D scale;
private:
};