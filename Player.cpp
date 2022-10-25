#include "Player.h"
#include "SDL.h"

Player::Player(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames)
	: Character::Character(CharacterTexture, Pos, NumberOfFrames)
{

}

Player::~Player()
{
}

void Player::Update(float DeltaTime)
{
	Character::Update(DeltaTime);
}

void Player::ProcessInput(Input* UserInput)
{
	float MovementX = 0.0f;
	float MovementY = 0.0f;

	//check if W key is down
	if (UserInput->bIsKeyDown(SDL_SCANCODE_W)) {
		MovementY = -1.0f;
	}

	//check if S key is down
	if (UserInput->bIsKeyDown(SDL_SCANCODE_S)) {
		MovementY = 1.0f;
	}

	//check if A key is down
	if (UserInput->bIsKeyDown(SDL_SCANCODE_A)) {
		MovementX = -1.0f;
	}

	//check if D key is down
	if (UserInput->bIsKeyDown(SDL_SCANCODE_D)) {
		MovementX = 1.0f;
	}

	SetMovementAxis(Vector2(MovementX, MovementY));
}