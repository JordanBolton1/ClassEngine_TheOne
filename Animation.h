#include "SDL.h"
#include "Texture.h"
#include "Vector2.h"

class Animation
{
public:
	//Constructor
	Animation();

	//Override Constructor
	Animation(Texture* InSpriteSheet, int InNumberOfFrames = 1, float InFrameDuration = 0.1f,
		int InStartFrame = 0, int InEndFrame = 1);

	//Deconstructor
	~Animation();

	//update the animation on each frame
	void Update(float DeltaTime);

	//Draw the texture to screen at the positions and scale
	void Draw(SDL_Renderer* Renderer, Vector2 Pos, int Scale = 1, bool Flip = false);

	int GetFrameWidth() { return FrameWidth; }

	int GetFrameHeight() { return FrameHeight; }

private:
	//start and end frame
	unsigned int StartFrame;
	unsigned int EndFrame;

	//frame width and height
	unsigned int FrameWidth;
	unsigned int FrameHeight;

	//Texture image for the spritesheet
	Texture* SpriteSheet;

	//timer since the last sprite update
	float FrameTimer;

	//How long each frame should hold for
	float FrameDuration;

	//What frame are we currently on
	unsigned int CurrentFrame;
};
