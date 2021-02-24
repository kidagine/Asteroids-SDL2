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
    Rock rock(Vector2D(x, y),Vector2D(3, 3),angle);
    rocks.push_front(rock);
}

void RockSpawner::SpawnRock(Vector2D position, Vector2D scale)
{
    srand(seed);
    seed++;
    int angle = rand() % 180;
    angle = rand() % 180;
    Rock rock(position, scale, angle);
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
    for (int i = 0; i < rock.rocksToSpawn; i++)
    {
        SpawnRock(rock._transform.position, Vector2D(rock._transform.scale.x - 1, rock._transform.scale.y - 1));
    }
   rocks.remove(rock);
   if (rocks.size() == 0)
   {
       Game::Won();
   }
}


