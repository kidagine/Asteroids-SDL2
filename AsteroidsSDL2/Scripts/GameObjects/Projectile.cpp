#include "Projectile.h"
#include "../RockSpawner.h"

const char* PROJECTILE_SPRITE = "Assets/Projectile.png";

void Projectile::Initialize()
{
    _spriteRenderer = SpriteRenderer(PROJECTILE_SPRITE);
    _spriteRenderer._rect.x = _transform.position.x;
    _spriteRenderer._rect.y = _transform.position.y;    
    _spriteRenderer._angle = _transform.angle;
}

void Projectile::Launch()
{
    _transform.position.x += cos(3.14 * _transform.angle / 180.0) * 8;
    _transform.position.y += sin(3.14 * _transform.angle / 180.0) * 8;
    _spriteRenderer._rect.x = _transform.position.x;
    _spriteRenderer._rect.y = _transform.position.y;
}

void Projectile::HasCollided()
{
    if (!isDestroyed)
    {
        RockSpawner* rockSpawner = rockSpawner->getInstance();
        std::list<Rock> rocks = rockSpawner->GetRocks();
        for (std::list<Rock>::iterator it = rocks.begin(); it != rocks.end(); ++it) {
            SDL_Rect a = _spriteRenderer._rect;
            SDL_Rect b = it->_spriteRenderer._rect;
        
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
                isDestroyed = true;
                rockSpawner->DeleteRock(*it);
            }
        }
    }
}
