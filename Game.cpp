#include <iostream>
#include "Game.h"
#include "Texture.h"
#include "Input.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

// constructor
Game::Game()
{
	// set the SDL Window and Renderer to null in case it has memory
	SdlWindow = nullptr;
	SdlRenderer = nullptr;
	EnemyTexture = nullptr;
	LastUptadeTime = 0.0f;
	PlayerTexture = nullptr;
	UserInput = nullptr;


	// Initialise the subsytem in the SDL2 Framework
	if (SDL_InitSubSystem(SDL_INIT_EVERYTHING) != 0) {

		bIsGameOver = true;
		// if failed to initialise subsystem, tell us on the console
		cout << "Initialise SDL - failed" << endl;
	}
	else {
		// enable the game loop
		bIsGameOver = false;
		// if the subsytem succesfully initialises
		cout << "Initialise SDL - success" << endl;
	}
}

// deconstructor
Game::~Game()
{

}

bool Game::Start()
{
	// create the sdl renderer and define it
	SdlRenderer = SDL_CreateRenderer(SdlWindow, 0, -1);

	// get the start time of the clock in milliseconds
	LastUpdateTime = SDL_GetTicks();

	// make sure the renderer worked
	if (SdlRenderer != nullptr) {
		cout << "Create Renderer - success" << endl;

		//Start detecting input
		UserInput = new Input();

		//Initalise the player Texture
		PlayerTexture = new Texture();
		//load the player texture
		PlayerTexture->LoadImageFromFile("Assets/Adventurer-50x37-109.png", SdlRenderer);

		//Construct the player
		Player* PlayerCharacter = new Player(PlayerTexture, Vector2(0, 0), 109);
		GameObjects.push_back(PlayerCharacter);

		//Initalise the enemy Texture
		EnemyTexture = new Texture();
		//load the enemy texture
		EnemyTexture->LoadImageFromFile("assets/goblin-spritesheet-65x35-28.png", SdlRenderer);

		//Construct the enemy as an enemy using the enemy texture
		Enemy* Enemy1 = new Enemy(EnemyTexture, Vector2(0, 37), 28);
		GameObjects.push_back(Enemy1);

		//Construct the second enemy as an enemy using the same enemy texture
		Enemy* Enemy2 = new Enemy(EnemyTexture, Vector2(0, 72), 28);
		GameObjects.push_back(Enemy2);
	}

	return true;
}

void Game::ProcessInput()
{
	// @ TODO: Process player inputs
	UserInput->UpdateInput(bIsGameOver);

	//cycle through all game objects and run their inputs
	for (unsigned int i = 0; i < GameObjects.size(); ++i) {
		GameObjects[i]->ProcessInput(UserInput);
	}
}

void Game::Update()
{
	// @ TODO: Add and changes to the game each frame
	// howe long since the last frame was updated in milliseconds
	unsigned int tick = SDL_GetTicks() - LastUpdateTime;

	//change the tick to seconds
	float DeltaTime = tick / 1000.0f;

	//refresh the last update time
	LastUpdateTime = SDL_GetTicks();



	// @TODO: Add anything that needs DeltaTime below here


	//cycle through all game objects and run their update
	for (unsigned int i = 0; i < GameObjects.size(); ++i) {
		GameObjects[i]->Update(DeltaTime);
	}
}

void Game::Draw()
{
	// set the draw colour
	SDL_SetRenderDrawColor(SdlRenderer, 15, 15, 15, 255);

	// clear the renderers
	SDL_RenderClear(SdlRenderer);

	// @ TODO: Draw stuff here

	//Cycle through all game objects and run their draw
	for (unsigned int i = 0; i < GameObjects.size(); ++i) {
		GameObjects[i]->Draw(SdlRenderer);
	}

	SDL_RenderPresent(SdlRenderer);
}

void Game::HandleGarbage()
{
}

void Game::Run(const char* title, int width, int height, bool fullscreen)
{
	// define the creation flag
	int CreationFlag = 0;

	// if fullscreen is set to false then set windowed mode
	if (!fullscreen) {
		CreationFlag = SDL_WINDOW_SHOWN;
	}
	else {
		CreationFlag = SDL_WINDOW_FULLSCREEN;
	}

	// create the SDL Window
	SdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, CreationFlag);

	// check if the SDL window worked
	// create the renderer and start the game loop
	if (SdlWindow != nullptr && Start()) {
		cout << "Create Window - success" << endl;

		// run the game loop
		while (!bIsGameOver) {
			// check for player input
			ProcessInput();

			// process any changes that were made either by input or game code
			Update();

			// draw everything to the screen
			Draw();
		}
	}

	// debug if we failed or exited
	cout << "Create Window - failed or was exited" << endl;

	Shutdown();
	Destroy();
}

void Game::Shutdown()
{
	// @ TODO: deallocate all of the stuff we add in start
}

void Game::Destroy()
{
	// deallocate the window
	SDL_DestroyWindow(SdlWindow);

	// deallocate the renderer
	SDL_DestroyRenderer(SdlRenderer);

	// shut down the SDL framework
	SDL_Quit();

}