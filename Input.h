#pragma once

#include "SDL.h"
class Input
{
public:
	Input();
	~Input();

	void UpdateInput(bool& bIsGameOver);

	//these are to detect if a particular key is up or down
	bool bIsKeyDown(SDL_Scancode Key);
	bool bIsKeyUp(SDL_Scancode Key);

private:
	const Uint8* KeyboardState;
};
