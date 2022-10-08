#include "Animation.h"
#include <iostream>
using namespace std;


Animation::Animation()
{
}

Animation::Animation(Texture* InSpriteSheet, int InNumberOfFrames, float InFrameDuration, int InStartFrame, int InEndFrame)
{
	//set default variables
	SpriteSheet = InSpriteSheet;
	StartFrame = InStartFrame;
	EndFrame = InEndFrame;
	FrameDuration = InFrameDuration;
	FrameTimer = 0.0f;
	CurrentFrame = StartFrame;


	// set the width and height of each sprite in the spritesheet
	if (SpriteSheet != nullptr) {
		//splice the sritesheet into its frames
		FrameWidth = SpriteSheet->GetImageWidth() / max(1, InNumberOfFrames);
		FrameHeight = SpriteSheet->GetImageHeight();
	}
	else {
		cout << "no texture found" << endl;
	}

}

Animation::~Animation()
{
	if (SpriteSheet != nullptr) {
		//deallocate thhe sprite sheet
		delete SpriteSheet;
		SpriteSheet = nullptr;
	}
}

void Animation::Update(float DeltaTime)
{
	//update the timer each frame
	FrameTimer += DeltaTime;

	if (FrameTimer >= FrameDuration) {
		CurrentFrame++;

		FrameTimer = 0.0f;

		if (CurrentFrame >= EndFrame) {
			CurrentFrame = StartFrame;
		}
	}
}

void Animation::Draw(SDL_Renderer* Renderer, int PosX, int PosY, int Scale)
{

	//get current rendering frame clipping region
	SDL_Rect clip;
	clip.x = CurrentFrame * FrameWidth;
	clip.y = 0;
	clip.w = FrameWidth;
	clip.h = FrameHeight;
	//draw to the screen
	SpriteSheet->Draw(Renderer, PosX, PosY, &clip);
}
