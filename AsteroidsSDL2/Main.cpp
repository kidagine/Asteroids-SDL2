#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Player.h"

const int SCREEN_WIDTH = 1260;
const int SCREEN_HEIGHT = 800;
const char* TITLE = "Asteroids";
const char* PLAYER_IDLE = "Assets/PlayerShipIdle.png";
const char* PLAYER_RUN = "Assets/PlayerShipRun.png";
const char* ROCK_SMALL = "Assets/RockSmall.png";
const char* ROCK_MEDIUM = "Assets/RockMedium.png";
const char* ROCK_BIG = "Assets/RockBig.png";

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;
SDL_Rect* srcR, destR;

bool Initialize();
SDL_Texture* LoadTexture(std::string path);
bool LoadMedia();
void GameLoop();
void Close();

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};



int main(int argc, char* args[])
{
    if (Initialize())
    {
        GameLoop();
    }
    Close();

	return 0;
}

bool Initialize()
{
    bool success = true;
    Test();
    if (SDL_Init(SDL_INIT_VIDEO) >= 0)
    {
        window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window != NULL)
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer != NULL)
            {
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
            }
            else
            {
                success = false;
            }
        }
        else 
        {
            success = false;
        }
    }
    return success;
}

void GameLoop()
{
    SDL_Event e;
    bool quit = false;
    SDL_Rect renderQuad = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 32, 32 };

    if (LoadMedia())
    {
        while (!quit)
        {

            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
                else if (e.type == SDL_KEYDOWN)
                {
                    switch (e.key.keysym.sym)
                    {
                    case SDLK_UP:
                        renderQuad.y -= 10;
                        break;
                    case SDLK_DOWN:
                        renderQuad.y += 10;
                        break;
                    case SDLK_LEFT:
                        renderQuad.x -= 10;
                        break;
                    case SDLK_RIGHT:
                        renderQuad.x += 10;
                        break;
                    }
                }
            }

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
            SDL_RenderPresent(renderer);
        }
    }
}

bool LoadMedia()
{
    //Loading success flag
    bool success = true;

    //Load PNG texture
    texture = LoadTexture(PLAYER_IDLE);
    if (texture == NULL)
    {
        printf("Failed to load texture image!\n");
        success = false;
    }

    return success;
}


SDL_Texture* LoadTexture(std::string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

void Close()
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