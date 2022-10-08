#include "Game.h"
#include "Texture.h"


//constructor
Game::Game()
{
	//set the sdl window to null in case it has memory
	SdlWindow = nullptr;
	SdlRenderer = nullptr;

	//initiallise subsystem in SDL2 framework
	if (SDL_InitSubSystem(SDL_INIT_EVERYTHING) != 0)
	{
		bIsGameOver = true;
		//if failed to initialise subsystem, tell us on the console
		cout << "initialised SDL - failed" << endl;
		//exit app
	}
	else
	{
		bIsGameOver = false;
		//if subsystem successully initialises
		cout << "initialised success" << endl;
	}
}

// deconsructor
Game::~Game()
{

}

bool Game::Start()
{
	//create the sdl renderer and define it
	SdlRenderer = SDL_CreateRenderer(SdlWindow, 0, -1);

	//get the start time of the clock in millisec
	LastUpdateTime = SDL_GetTicks();

	//make sure the renderer worked
	if (SdlRenderer != nullptr) {
		cout << "create renderer - success" << endl;

		//initialised texture
		PlayerTexture = new Texture();
		//load the texture
		if (PlayerTexture->LoadImageFromFile("Assets/Adventurer-50x37-109.png", SdlRenderer)) {

			cout << "player texture - success" << endl;

			PlayerAnims->Idle = new Animation(PlayerTexture, 109,1.0f,0,9);
		}
		else {
			cout << "player texture - failed" << endl;
		}

		return true;
	}

	cout << "create renderer - failed" << endl;
	return false;
}


void Game::ProcessInput()
{
	// @ todo: process player inputs
}


void Game::Update()
{
	// @ todo: add and changes to the game each frame

	unsigned int tick = SDL_GetTicks() - LastUpdateTime;

	//Change the tick to seconds
	float DeltaTime = tick / 1000.0f;

	//refresh the last update time
	LastUpdateTime = SDL_GetTicks();

	//todo add anything that needs deltatime here

	PlayerAnims->Attack->Update(DeltaTime);

	//get how many seconds it has been
	int Seconds = SDL_GetTicks() / 1000;
	cout << Seconds << endl;

	//after 10 seconds kill the program
	if (Seconds > 9) {
		bIsGameOver = true;
	}
}


void Game::Draw()
{
	//set draw the colour
	SDL_SetRenderDrawColor(SdlRenderer, 15, 15, 15, 255);

	//clear the renderer
	SDL_RenderClear(SdlRenderer);

	// @ todo: Draw stuff here
	PlayerAnims->Attack->Draw(SdlRenderer, 0, 0);

	SDL_RenderPresent(SdlRenderer);

}


void Game::Run(const char* title, int width, int height, bool fullscreen)
{
	//define the creation flag
	int CreationFlag = 0;

	//if bool screen is set to false then set windowed mode
	if (!fullscreen) 
	{
		CreationFlag = SDL_WINDOW_SHOWN;

	}
	else 
	{
		CreationFlag = SDL_WINDOW_FULLSCREEN;
	}

	//create the sdl window 
	SdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, CreationFlag);

	//check if the sdl window worked
	//create renderer and start game loop
	if (SdlWindow != nullptr && Start()) 
	{
		cout << "create window - success" << endl;


		//run the game loop
		while (!bIsGameOver) 
		{
			//check for player input
			ProcessInput();

			//any changes that were made either by input or game code
			Update();

			//draw everything to the screen
			Draw();
		}
	}

	// debug if we failed or exited
	cout << "create window - failed or was exited" << endl;

	Shutdown();
	Destroy();
}


void Game::Shutdown()
{
}


void Game::Destroy()
{
	//dealocate the window
	SDL_DestroyWindow(SdlWindow);

	//dealocate the renderer
	SDL_DestroyRenderer(SdlRenderer);

	//shutdown sdl framework
	SDL_Quit();
}
