#include "Game.h"
#include "GameObjects/Player.h"
#include "GameObjects/Rock.h"
#include "GameObjects/Projectile.h"
#include "RockSpawner.h"


SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
Player* _player = NULL;
Rock* _rock = NULL;

RockSpawner* _rockSpawner = NULL;

SDL_Renderer* Game::renderer = nullptr;
std::list<Projectile> gameObjects;
RockSpawner* RockSpawner::instance = 0;
float timeUntilRockSpawn = 3000;

Game::Game()
{}

void Game::Initialize(const char* title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) >= 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if (window != NULL)
        {
            std::cout << "Window initialized" << std::endl;
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer != NULL)
            {
                std::cout << "Renderer initialized" << std::endl;
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
            }
            isRunning = true;

        }
    }
    RockSpawner* rockSpawner = rockSpawner->getInstance();
    _rockSpawner = rockSpawner;
    for (int i = 0; i < 1; i++)
    {
        _rockSpawner->SpawnRock();
    }
    Vector2D playerPosition = Vector2D(width / 2, height / 2);
    _rock = new Rock(playerPosition);
    _player = new Player(playerPosition);
}

void Game::Update()
{
    _player->Update();
    _rock->Update();
    std::list<Rock> rocks = _rockSpawner->GetRocks();
    for (std::list<Rock>::iterator it = rocks.begin(); it != rocks.end(); ++it) {
        it->Update();
    }
    for (std::list<Projectile>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
         it->Update();
    }
    //if (timeUntilRockSpawn < SDL_GetTicks())
    //{
    //    timeUntilRockSpawn = SDL_GetTicks() + 3000;
    //    _rockSpawner->SpawnRock();
    //}


    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            isRunning = false;
        }
    }
}

void Game::Render()
{
    SDL_RenderClear(renderer);
    _player->Render();
    _rock->Render();
    std::list<Rock> rocks = _rockSpawner->GetRocks();
    for (std::list<Rock>::iterator it = rocks.begin(); it != rocks.end(); ++it) {
        it->Render();
    }
    for (std::list<Projectile>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
        it->Render();
    }
    SDL_RenderPresent(renderer);
}

void Game::Terminate()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    IMG_Quit();
    SDL_Quit();
}

void Game::Instantiate()
{
    Projectile gameObject;
    gameObjects.push_front(gameObject);
}

void Game::Instantiate(Vector2D position)
{
    Projectile gameObject(position);
    gameObjects.push_front(gameObject);
}

bool Game::Running()
{
    return isRunning;
}