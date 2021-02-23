#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer()
{}

SpriteRenderer::SpriteRenderer(const char* pathName)
{
    SDL_Surface* surface = IMG_Load(pathName);
    if (surface != NULL)
    {
        _texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
        if (_texture != NULL)
        {
            SDL_FreeSurface(surface);
        }
    }

    _rect.h = 32;
    _rect.w = 32;
}

void SpriteRenderer::Render()
{
    SDL_RenderCopy(Game::renderer, _texture, NULL, &_rect);
}

void SpriteRenderer::SetSprite(const char* pathName)
{
    SDL_Surface* surface = IMG_Load(pathName);
    if (surface != NULL)
    {
        _texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
        if (_texture != NULL)
        {
            SDL_FreeSurface(surface);
        }
    }
}
