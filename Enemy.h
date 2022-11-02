#pragma once

#include "Character.h"

class Enemy :
    public Character
{
public:
    Enemy(Texture* EnemyTexture, Vector2 Pos, int NumberOfFrames);
    ~Enemy();

    void Update(float DeltaTime) override;
};