#include "Game.h"
#include "GameObjects/Player.h"
#include "GameObjects/Rock.h"
#include "GameObjects/Projectile.h"
#include "RockSpawner.h"

static bool paused;
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
Player* _player = NULL;
RockSpawner* _rockSpawner = NULL;
SpriteRenderer* _logoSplash = NULL;
const char* SPLASH_SCREEN_SPRITE = "Assets/SplashScreen.png";

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
    _logoSplash = new SpriteRenderer(SPLASH_SCREEN_SPRITE);

    RockSpawner* rockSpawner = rockSpawner->getInstance();
    _rockSpawner = rockSpawner;

    for (int i = 0; i < 4; i++)
    {
        _rockSpawner->SpawnRock();
    }
    Vector2D playerPosition = Vector2D(width / 2, height / 2);
    _player = new Player(playerPosition);
}

void Game::Update()
{
    if (!paused)
    {
        if (_logoSplash != nullptr)
        {
            if (3000 < SDL_GetTicks())
            {
                _logoSplash = nullptr;
            }
        }
        else
        {
            _player->Update();
            _rockSpawner->Update(_player->_spriteRenderer._rect);
            for (std::list<Projectile>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
                it->Update();
            }
        }
    }
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
    if (!paused)
    {
        SDL_RenderClear(renderer);
        if (_logoSplash != nullptr)
        {
            _logoSplash->Render();
        }
        else
        {
            _player->Render();
            _rockSpawner->Render();

            for (std::list<Projectile>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
                it->Render();
            }
        }

        SDL_RenderPresent(renderer);
    }
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

void Game::Instantiate(Vector2D position, float angle)
{
    Projectile gameObject(position, angle);
    gameObjects.push_front(gameObject);
}

void Game::PauseGame()
{
    paused = true;
}

bool Game::Running()
{
    return isRunning;
}