#include "Character.h"
#include "SDL.h"
#include <iostream>
#include "Vector2.h"
using namespace std;

Character::Character(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames)
{
	Position = Pos;
	ObjectTexture = CharacterTexture;
	this->NumberOfFrames = NumberOfFrames;
	Velocity = Vector2().Zero();
	MovementAxis = Vector2().Zero();
	MaxSpeed = 100.0f;
}

Character::~Character()
{

}

void Character::Draw(SDL_Renderer* Renderer)
{
	SDL_Rect Clip;
	Clip.x = 0;
	Clip.y = 0;
	Clip.h = ObjectTexture->GetImageHeight();
	Clip.w = ObjectTexture->GetImageWidth() / SDL_max(1, NumberOfFrames);

	ObjectTexture->Draw(Renderer, Position, &Clip);
}

void Character::Update(float DeltaTime)
{
	//set the veloctiy to be our movement axis normalised * our speed
	Velocity = MovementAxis.Normalised() * MaxSpeed;
	//Move the character based on velocity
	Position += Velocity * DeltaTime;
}

void Character::ProcessInput(Input* UserInput)
{
}

void Character::SetMovementAxis(Vector2 Axis)
{
	MovementAxis = Axis;
}

Vector2 Character::GetMovementAxis()
{
	return MovementAxis;
}