#pragma once
#include <iostream>
using namespace std;
//setup sdl
#include <SDL.h>
#include "Texture.h"
#include "Animation.h"

struct CharacterAnimations {
	Animation* Idle;
	Animation* Attack;
};

class Game
{
	public:
	//constructor
		Game();
	//deconstructor
		~Game();
	
	private:
		//the window that we will be rendering to
		SDL_Window* SdlWindow;
		//2d renderer
		SDL_Renderer* SdlRenderer;
		// flag for the game loop
		bool bIsGameOver;
		
		//player texture
		Texture* PlayerTexture;
		CharacterAnimations* PlayerAnims;

		//how long since last update
		unsigned int LastUpdateTime;

	public:
		//crate the renderer
		//allocate any object we want
		bool Start();

		//handle any inputs from the player that happens last call
		void ProcessInput();

		//run on every frame
		void Update();

		//draw the game imagess to the screen
		void Draw();

		//this will create the window and begind the game loop
		//@ param 1- title for window
		//@ param 2- width for window
		//@ param 3- height for window
		//@ param 4- fullscreen or not for window
		void Run(const char* title, int width, int height, bool fullscreen);

		//dealocate objects from memory
		void Shutdown();

		//shutdown the sdl framework delete the renderer from memory
		void Destroy();
};

