#ifndef _INTRO_H
#define _INTRO_H

#include "Scene.h"

//A sub-clas of "Scene" which is used to represent the initial scene used to introduce the game.
class Intro : public Scene
{
	public:
		//Constructor method.
		Intro();
		//Destructor method.
		~Intro();
		//A method which initialises this scene using a pointer to the sdl renderer.
		void Initialise(SDL_Renderer* renderer);
	private:
		//A float representing the amount of time that has accumulated
		//since the current slide was loaded.
		float accumulatedtime = 0;
		//A method which is called once per frame and changes the slide if enough time
		//has passed since the current one was loaded.
		void Update(float deltaTime);
		//A method which takes appropriate actions depending on the user's input and returns
		//a boolean representing whether or not to continue running the scene.
		bool GetInput();
		//Loads the next slide.
		void NextSlide();
		//An array which contains all the sprites representing intro slides.
		vector<Sprite*> slides;
		//The index of the currently-shown slide (relative to the "slides" array).
		size_t currentslideindex = 0;
		//The total quantity of slides.
		int slideno = 5;
		//Display the current slide.
		void DisplaySlide();
		//A sprite representing the slide that is currently onscreen.
		Sprite* currentSlide;
};

#endif