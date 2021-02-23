#include "Projectile.h"
#include "../RockSpawner.h"

const char* PROJECTILE_SPRITE = "Assets/Projectile.png";

void Projectile::Initialize()
{
    _spriteRenderer = SpriteRenderer(PROJECTILE_SPRITE);
    _spriteRenderer._rect.x = _transform.position.x;
    _spriteRenderer._rect.y = _transform.position.y;    
}

void Projectile::Launch()
{
    _transform.position.y -= 8;
    _spriteRenderer._rect.y = _transform.position.y;
}

void Projectile::HasCollided()
{
    //RockSpawner* rockSpawner = rockSpawner->getInstance();
    //std::list<Rock> rocks = rockSpawner->GetRocks();
    //Rock *tempRock;
    //for (std::list<Rock>::iterator it = rocks.begin(); it != rocks.end(); ++it) {
    //    SDL_Rect a = _spriteRenderer._rect;
    //    SDL_Rect b = it->_spriteRenderer._rect;
    //    
    //    //The sides of the rectangles
    //    int leftA, leftB;
    //    int rightA, rightB;
    //    int topA, topB;
    //    int bottomA, bottomB;

    //    //Calculate the sides of rect A
    //    leftA = a.x;
    //    rightA = a.x + a.w;
    //    topA = a.y;
    //    bottomA = a.y + a.h;

    //    //Calculate the sides of rect B
    //    leftB = b.x;
    //    rightB = b.x + b.w;
    //    topB = b.y;
    //    bottomB = b.y + b.h;
    //    if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
    //    {
    //    }
    //    else 
    //    {
    //        rockSpawner->DeleteRock(*it);
    //        //tempRock = it;
    //    }
    //}
    //if (tempRock == NULL)
    //{
    //    //rockSpawner->DeleteRock();
    //}
}
