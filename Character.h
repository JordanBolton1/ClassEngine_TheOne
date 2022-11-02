#pragma once
#include "GameObject.h"
#include "SDL.h"
#include "Vector2.h"

using namespace std;

class Character : public GameObject
{
public:
	Character(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames);
	~Character();

	void Draw(SDL_Renderer* Renderer) override;
	virtual void Update(float DeltaTime) override;
	virtual void ProcessInput(Input* UserInput) override;

protected:
	float MaxSpeed;

	void SetMovementAxis(Vector2 Axis);
	Vector2 GetMovementAxis();

private:
	//Velocity is the true representation of speed, this will have an x and y value
	Vector2 Velocity;
	//This is going to detect input and move our character based on its direction
	//make sure the number is normally between 0 and 1 to keep regular speeds
	Vector2 MovementAxis;
};