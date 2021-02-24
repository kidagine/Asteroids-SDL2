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

GameObject::GameObject(Vector2D position, float angle)
{
    _transform = Transform();
    _transform.position = position;
    _transform.angle = angle;
}

GameObject::GameObject(Vector2D position, Vector2D scale, float angle)
{
    _transform = Transform();
    _transform.position = position;
    _transform.scale = scale;
    _transform.angle = angle;
}

void GameObject::Update()
{

}

void GameObject::Render()
{
}