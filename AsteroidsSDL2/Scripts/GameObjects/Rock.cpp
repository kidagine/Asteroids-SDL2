#include "Rock.h"

const char* ROCK_BIG_SPRITE = "Assets/RockBig.png";
const char* ROCK_NORMAL_SPRITE = "Assets/RockMedium.png";
const char* ROCK_SMALL_SPRITE = "Assets/RockSmall.png";

void Rock::Initialize()
{
    _spriteRenderer = SpriteRenderer(ROCK_SMALL_SPRITE);
    _spriteRenderer._rect.x = _transform.position.x;
    _spriteRenderer._rect.y = _transform.position.y;


    //id = rand() % 1000 + 1;
}

void Rock::Launch()
{
    std::cout << _spriteRenderer._rect.y << std::endl;
    _spriteRenderer._rect.y = +50;
    std::cout << _spriteRenderer._rect.y << std::endl;
}