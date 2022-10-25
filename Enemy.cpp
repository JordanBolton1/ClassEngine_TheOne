#include "Enemy.h"

Enemy::Enemy(Texture* CharacterTexture, Vector2 Pos, int NumberOfFrames)
	: Character::Character(CharacterTexture, Pos, NumberOfFrames)
{

}

Enemy::~Enemy()
{
}

void Enemy::Update(float DeltaTime)
{
	Character::Update(DeltaTime);

	Position.x += 100 * DeltaTime;
}