#pragma once
#include <list>
#include "GameObjects/Rock.h"


class RockSpawner {
	static RockSpawner* instance;
public:
	static RockSpawner* getInstance() {
		if (!instance)
			instance = new RockSpawner;
		return instance;
	}
	RockSpawner();
	void SpawnRock();
	void SpawnRock(Vector2D position, Vector2D scale);
	std::list<Rock> GetRocks();
	void Update(SDL_Rect rect);
	void Render();
	void DeleteRock(Rock rock);
private:
};
