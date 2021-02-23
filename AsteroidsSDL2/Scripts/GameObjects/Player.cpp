#include "Player.h"

const char* PLAYER_IDLE_SPRITE = "Assets/PlayerShipIdle.png";
const char* PLAYER_RUN_SPRITE = "Assets/PlayerShipRun.png";
bool isMoving;
int speed = 10;

void Player::Initialize()
{
    _spriteRenderer = SpriteRenderer(PLAYER_IDLE_SPRITE);
    _spriteRenderer._rect.x = _transform.position.x;
    _spriteRenderer._rect.y = _transform.position.y;
}

void Player::Movement()
{
    SDL_Event event;
    Vector2D previousPosition = _transform.position;
    if (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                _transform.position.y -= speed;
                break;
            case SDLK_DOWN:
                _transform.position.y += speed;
                break;
            case SDLK_LEFT:
                _transform.position.x -= speed;
                break;
            case SDLK_RIGHT:
                _transform.position.x += speed;
                break;
            }
        }
        if (event.type == SDL_KEYUP)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_SPACE:
                Vector2D projectilePosition = Vector2D(_transform.position.x, _transform.position.y - 20);
                Game::Instantiate(projectilePosition);
                break;
            }
        }
    }
    _spriteRenderer._rect.x = _transform.position.x;
    _spriteRenderer._rect.y = _transform.position.y;
    if (previousPosition.x != _transform.position.x || previousPosition.y != _transform.position.y)
    {
        if (!isMoving)
        {
            isMoving = true;
            _spriteRenderer.SetSprite(PLAYER_RUN_SPRITE);
        }
    }
    else 
    {
        if (isMoving)
        {
            isMoving = false;
            _spriteRenderer.SetSprite(PLAYER_IDLE_SPRITE);
        }
    }
}
