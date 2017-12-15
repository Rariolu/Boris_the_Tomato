#ifndef _LEVEL_H
#define _LEVEL_H

#include "Scene.h"
#include "Descender.h"
#include"PointsCounter.h"
#include"Leaf.h"
#include"HealthBar.h"

//A sub-class of "Scene" which represents the main level of the game.
class Level : public Scene
{
	public:
		//Constructor method.
		Level();
		//Destructor method.
		~Level();
		//A method which initialises this scene using a pointer to the sdl renderer.
		void Initialise(SDL_Renderer* renderer);
	private:
		//A method which takes appropriate actions depending on the user's input and returns
		//a boolean representing whether or not to continue running the scene.
		bool GetInput();
		//A method which is called once per frame and is used to check for collisions between
		//descenders and leaves and deletes either if necessary.
		void Update(float deltaTime);
		//An array of x positions from which descenders can be spawned.
		vector<int> descenderXPositions;
		//An array of all descenders that are currently on screen.
		vector<Descender*> descenders;
		//Create a descender and place it on screen at a random x position and of a random type.
		Descender* AddDescender();
		//The amount of time remaining until the possibility of another descender spawning.
		float spawnWait = 0;
		//A method which returns a boolean representing whether or not the given sprite collides
		//with any of the active descenders.
		bool CollidesWithADescender(Sprite* sprite);
		//A pointer to an instance of "PointsCounter" which is used to show the player's
		//accumulated points.
		PointsCounter* pointscounter;
		//A method which removes the given descender from the "descenders" array
		//and removes it as a sprite.
		vector<Descender*>::iterator DeleteDescender(vector<Descender*>::iterator descender);
		//A method which returns a boolean representing whether or not the given
		//descender and leaf collide.
		bool LeafCollision(Descender* descender, Leaf* leaf);
		//An array containing all the onscreen leaves.
		vector<Leaf*> leaves;
		//A method which initialises the "leaves" array and its contents.
		void init_leaves();
		//A sprite which is used to represent the bottom of the screen
		//and causes descenders to be destroyed upon touching it.
		Sprite* bottom;
		//A method which launches the "Game Over" scene.
		void GameOver();
		//A pointer to an instance of "HealthBar" that represents the player's current health.
		HealthBar* healthbar;
};
#endif