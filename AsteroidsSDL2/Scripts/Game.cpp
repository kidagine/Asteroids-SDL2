#include "Game.h"
#include "GameObject.h"
#include "Player.h"

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Texture* texture = NULL;
GameObject* _player = NULL;

SDL_Renderer* Game::renderer = nullptr;


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

    _player = new GameObject();
}

void Game::Update()
{
    _player->Update();
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
    SDL_RenderPresent(renderer);
}

void Game::Terminate()
{
    SDL_DestroyTexture(texture);
    texture = NULL;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    IMG_Quit();
    SDL_Quit();
}

bool Game::Running()
{
    return isRunning;
}