#include "RockSpawner.h";

std::list<Rock> rocks;
int seed = 255;
RockSpawner::RockSpawner()
{}

void RockSpawner::SpawnRock()
{
    srand(seed);
    seed++;
    int y = rand() % 640;
    y = rand() % 640;
    int x = rand() % 640;
    int angle = rand() % 180;
    Rock rock(Vector2D(x, y), angle);
    rocks.push_front(rock);
}

std::list<Rock> RockSpawner::GetRocks()
{
    return rocks;
}

void RockSpawner::Update(SDL_Rect rect)
{
    for (std::list<Rock>::iterator it = rocks.begin(); it != rocks.end(); ++it) {
        it->Update();
        it->HasCollided(rect);
    }
}

void RockSpawner::Render()
{
    for (std::list<Rock>::iterator it = rocks.begin(); it != rocks.end(); ++it) {
        it->Render();
    }
}

void RockSpawner::DeleteRock(Rock rock)
{
   rocks.remove(rock);
   if (rocks.size() == 0)
   {
       Game::PauseGame();
   }
}


