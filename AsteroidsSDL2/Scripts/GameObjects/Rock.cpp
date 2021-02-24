#include "Rock.h"

const char* ROCK_BIG_SPRITE = "Assets/RockBig.png";
const char* ROCK_NORMAL_SPRITE = "Assets/RockMedium.png";
const char* ROCK_SMALL_SPRITE = "Assets/RockSmall.png";

void Rock::Initialize()
{
    _spriteRenderer = SpriteRenderer(ROCK_SMALL_SPRITE);
    _spriteRenderer._rect.x = _transform.position.x;
    _spriteRenderer._rect.y = _transform.position.y;
    _spriteRenderer._rect.h = _transform.scale.x * _spriteRenderer._rect.h;
    _spriteRenderer._rect.w = _transform.scale.y * _spriteRenderer._rect.w;
    _spriteRenderer._angle = _transform.angle;
    speed = _transform.scale.x - 4;
    if (_transform.scale.x == 1)
    {
        rocksToSpawn = 0;
    }
    id = rand() % 1000 + 1;
}

void Rock::Launch()
{
    _transform.position.x += cos(3.14 * _transform.angle / 180.0) * speed;
    _transform.position.y += sin(3.14 * _transform.angle / 180.0) * speed;
    _spriteRenderer._rect.x = _transform.position.x;
    _spriteRenderer._rect.y = _transform.position.y;
}

void Rock::HasCollided(SDL_Rect b)
{
    SDL_Rect a = _spriteRenderer._rect;

    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
    {
    }
    else
    {
        Game::Lost();
    }
}

void Rock::CheckBounds()
{
    if (_transform.position.x <= -96)
    {
        _transform.position.x = 800;
    }
    if (_transform.position.x >= 896)
    {
        _transform.position.x = -96;
        _spriteRenderer._rect.x = _transform.position.x;
    }

    if (_transform.position.y <= -96)
    {
        _transform.position.y = 600;
        _spriteRenderer._rect.y = _transform.position.y;
    }
    if (_transform.position.y >= 696)
    {
        _transform.position.y = -96;
        _spriteRenderer._rect.y = _transform.position.y;
    }
}