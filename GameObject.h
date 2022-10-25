#include "SDL.h"
#include "Texture.h"
#include "Vector2.h"
#include "Input.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Draw(SDL_Renderer* Renderer);
	virtual void Update(float DeltaTime);
	virtual void ProcessInput(Input* UserInput);

protected:
	//positions for the game object to display on the window
	Vector2 Position;
	//The objects texture
	Texture* ObjectTexture;
};
