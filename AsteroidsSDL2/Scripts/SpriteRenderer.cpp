#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer()
{}

SpriteRenderer::SpriteRenderer(const char* pathName)
{
    SDL_Surface* surface = IMG_Load(pathName);
    if (surface != NULL)
    {
        _texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
        _rect.h = surface->h;
        _rect.w = surface->w;

        if (_texture != NULL)
        {
            SDL_FreeSurface(surface);
        }
    }
}

void SpriteRenderer::Render()
{
    SDL_RenderCopyEx(Game::renderer, _texture, NULL, &_rect, _angle, NULL, SDL_FLIP_NONE);
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
