#include "GameObject.h"


GameObject::GameObject()
{
    _transform = Transform();
    _transform.position = Vector2D(0, 0);
}

GameObject::GameObject(Vector2D position)
{
    _transform = Transform();
    _transform.position = position;
}

void GameObject::Update()
{

}

void GameObject::Render()
{
}