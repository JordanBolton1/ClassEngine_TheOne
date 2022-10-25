#include "Collider.h"

Collider::Collider(Vector2 Position, Vector2 HalfDimension, bool ShouldDebug)
{
	bDebug = ShouldDebug;
	OverlappedCollider = {};

	//get the position and adjust for the size of the collider to centre it
	float x = Postion.x - HalfDimension
}

Collider::~Collider()
{
}

void Collider::Update(float DeltaTime, vector<Collider*> OtherCollider)
{
}

void Collider::Draw(SDL_Renderer* Renderer)
{
}

vector<Collider*> Collider::GetOverlappingCollider()
{
	return vector<Collider*>();
}
