#pragma once

#include <vector>
#include "SDL.h"
#include "Vector2.h"

using namespace std;

//When two classes both need data from each other it creates a paradox
//We can use forward declaration to solve this paradox instead of adding an #include
class GameObject;

class Collider
{
public:
	Collider(GameObject* OwnerObject, Vector2 Position = Vector2().Zero(), Vector2 HalfDimensions = Vector2(1.0f, 1.0f), bool ShouldDebug = true);
	~Collider();

	//we need to detect if we are colliding with any of the other colliders in the game
	void Update(float DeltaTime, vector<Collider*> OtherColliders);
	void Draw(SDL_Renderer* Renderer);

	//set the bounds for the collider
	SDL_FRect ColliderRect;

	//Get the other colliders that are overlapping
	vector<Collider*>GetOverlappingColliders() const;

	//debug to draw the collider to the screen
	bool bDebug;

	//this will return the owner object
	GameObject* GetOwner()const;

	//remove a single collider from overlapped
	bool RemoveColliderFromOverlapped(Collider* RCollider);

protected:
	//Store all the colldiers that are currently overlapping this collider
	vector<Collider*> OverlappedColliders;

	//Store the owner game object is there is one
	GameObject* OwnerObject;

	//store all colliders in the game
	vector<Collider*> AllColliders;
};

