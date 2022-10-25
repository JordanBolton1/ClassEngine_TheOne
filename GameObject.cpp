#include "GameObject.h"
#include "Vector2.h"
#include "Input.h"

GameObject::GameObject()
{
	Position = Vector2(0, 0);
	ObjectTexture = nullptr;
}

GameObject::~GameObject()
{
}

void GameObject::Draw(SDL_Renderer* Renderer)
{
}

void GameObject::Update(float DeltaTime)
{
}

void GameObject::ProcessInput(Input* UserInput)
{

}