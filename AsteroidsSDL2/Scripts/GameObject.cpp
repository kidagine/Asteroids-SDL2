#include "GameObject.h"

const char* PLAYER_IDLE_IMAGE = "Assets/PlayerShipIdle.png";


GameObject::GameObject()
{
	_spriteRenderer = SpriteRenderer(PLAYER_IDLE_IMAGE);
    _transform = Transform();
    _transform.position = Vector2D(0, 0);
}

void GameObject::Update()
{
    _spriteRenderer._rect.y += _transform.position.x + 1;
    _spriteRenderer._rect.x += _transform.position.y + 1;
}

void GameObject::Render()
{
	_spriteRenderer.Render();
}