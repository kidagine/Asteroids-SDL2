#include "Player.h"

const char* PLAYER_IDLE_SPRITE = "Assets/PlayerShipIdle.png";
const char* PLAYER_RUN_SPRITE = "Assets/PlayerShipRun.png";
bool isMoving;

void Player::Initialize()
{
    _spriteRenderer = SpriteRenderer(PLAYER_IDLE_SPRITE);
    _spriteRenderer._rect.x = _transform.position.x;
    _spriteRenderer._rect.y = _transform.position.y;
    _transform.angle = 270;
    _spriteRenderer._angle = _transform.angle;
}

void Player::Movement()
{
    SDL_Event event;
    Vector2D previousPosition = _transform.position;

    SDL_PollEvent(&event);
    const Uint8* state = SDL_GetKeyboardState(NULL);

    // Move centerpoint of rotation for one of the trees:
    if (state[SDL_SCANCODE_UP])
    {
        _transform.position.x += cos(3.14 * _transform.angle / 180.0) * movementSpeed;
        _transform.position.y += sin(3.14 * _transform.angle / 180.0) * movementSpeed;
    }
    if (state[SDL_SCANCODE_LEFT])
    {
        _transform.angle -= rotationSpeed;
    }
    if (state[SDL_SCANCODE_RIGHT])
    {
        _transform.angle += rotationSpeed;
    }
    if (state[SDL_SCANCODE_SPACE])
    {
        if (hasShot)
        {
            hasShot = false;
            Game::Instantiate(_transform.position, _transform.angle);
        }
    }
    else
    {
        if (!hasShot)
        {
            hasShot = true;
        }
    }

    _spriteRenderer._rect.x = _transform.position.x;
    _spriteRenderer._rect.y = _transform.position.y;
    _spriteRenderer._angle = _transform.angle;
    //if (previousPosition.x != _transform.position.x || previousPosition.y != _transform.position.y)
    //{
    //    if (!isMoving)
    //    {
    //        isMoving = true;
    //        _spriteRenderer.SetSprite(PLAYER_RUN_SPRITE);
    //    }
    //}
    //else 
    //{
    //    if (isMoving)
    //    {
    //        isMoving = false;
    //        _spriteRenderer.SetSprite(PLAYER_IDLE_SPRITE);
    //    }
    //}
}

void Player::CheckBounds()
{
    if (_transform.position.x <= -25)
    {
        _transform.position.x = 800;
    }
    if (_transform.position.x >= 805)
    {
        _transform.position.x = -25;
        _spriteRenderer._rect.x = _transform.position.x;
    }

    if (_transform.position.y <= -25)
    {
        _transform.position.y = 600;
        _spriteRenderer._rect.y = _transform.position.y;
    }
    if (_transform.position.y >= 605)
    {
        _transform.position.y = -25;
        _spriteRenderer._rect.y = _transform.position.y;
    }
}