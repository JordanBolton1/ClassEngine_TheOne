#include "GameObject.h"
#include "Vector2.h"
#include "SDL.h"

GameObject::GameObject()
{
	Position = Vector2().Zero();
	ObjectTexture = nullptr;
	ObjectCenter = Position;
	Collision = nullptr;
	NumberOfFrames = 1;
	bShouldDelete = false;
}

GameObject::~GameObject()
{
	// remove the collision from memory  if there is one
	if (Collision != nullptr) {
		delete Collision;
		Collision = nullptr;
	}

	//remove the texture from memory if there is one
	if (ObjectTexture != nullptr) {
		delete ObjectTexture;
		ObjectTexture = nullptr;
	}
}

void GameObject::Draw(SDL_Renderer* Renderer)
{
}

void GameObject::Update(float DeltaTime)
{
	//This will find the boject center based on the texture if there is one
	FindObjectCenter();
	//this will update the collision position to match the object center
	UpdateCollisionPosition();
}

void GameObject::ProcessInput(Input* UserInput)
{

}

void GameObject::SetCollision(Vector2 Position, Vector2 HalfDimensions, bool ShouldDebug)
{
	//if there is a collision currently
	if (Collision != nullptr) {
		//clear it
		delete Collision;
		Collision = nullptr;
	}

	//define the game objects collision
	Collision = new Collider(this, Position, HalfDimensions, ShouldDebug);
}

void GameObject::SetCollisionDimensions(Collider* Collision, Vector2 HalfDimensions)
{
	if (Collision != nullptr) {
		//set the width of the collider
		Collision->ColliderRect.w = HalfDimensions.x * 2;
		//set the height of the collider
		Collision->ColliderRect.h = HalfDimensions.y * 2;
	}
}

void GameObject::UpdateCollisionPosition()
{
	//check if there is even a collision
	if (Collision != nullptr) {
		float w = Collision->ColliderRect.w / 2;
		float h = Collision->ColliderRect.h / 2;

		//Change the position of the collider to equal the object center
		//center the collider based on its half dimensions
		Collision->ColliderRect.x = ObjectCenter.x - w;
		Collision->ColliderRect.y = ObjectCenter.y - h;
	}
}

void GameObject::FindObjectCenter()
{
	ObjectCenter = Position;
	if (ObjectTexture != nullptr) {
		float w = ObjectTexture->GetImageWidth() / SDL_max(1, NumberOfFrames);
		float h = ObjectTexture->GetImageHeight();

		//w = w / 2;
		w /= 2;
		//h = h / 2;
		h /= 2;

		//ObjectCenter = ObjectCenter + w;
		ObjectCenter.x += w;
		//ObjectCenter = ObjectCenter + h;
		ObjectCenter.y += h;

	}
}

Collider* GameObject::GetCollision()
{
	return Collision;
}

bool GameObject::ShouldDelete() const
{
	//thi will be the key that tells the game this need to be deleted
	return bShouldDelete;
}

void GameObject::DestroyGameObject()
{
	//set should delete
	bShouldDelete = true;
}
