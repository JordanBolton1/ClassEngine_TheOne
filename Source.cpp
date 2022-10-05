#include <iostream>
#include"Game.h"
using namespace std;

int main(int argc, char** argv) 
{
	//create the game class and alocate it to memory
	Game* NewGame = new Game();

	NewGame->Run("Engine", 1280, 720, false);

	delete NewGame;

	return 0;
}