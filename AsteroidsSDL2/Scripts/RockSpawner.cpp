#include "RockSpawner.h";

std::list<Rock> rocks;

RockSpawner::RockSpawner()
{}

void RockSpawner::SpawnRock()
{
    int x = rand() % 800;
    int y = rand() % 640;
    Rock rock(Vector2D(x, y));
    rocks.push_front(rock);
}

void RockSpawner::SpawnRock(Vector2D position)
{
    Rock rock(position);
    rocks.push_front(rock);
}

std::list<Rock> RockSpawner::GetRocks()
{
    return rocks;
}

void RockSpawner::DeleteRock(Rock rock)
{
   // rocks.remove(rock);
}


