#ifndef _MENU_H
#define _MENU_H

#include "Scene.h"

//A sub-class of "Scene" which represents the menu scene.
class Menu : public Scene
{
	public:
		//Constructor method.
		Menu();
		//Destructor method.
		~Menu();
		//A method which initialises this scene using a pointer to the sdl renderer.
		void Initialise(SDL_Renderer* renderer);
	private:
		//A method which takes appropriate actions depending on the user's input and returns
		//a boolean representing whether or not to continue running the scene.
		bool GetInput();
		//A method which is called once per frame.
		void Update(float deltaTime);
		//A sprite which is used to represent a button that starts the "Level" scene.
		Sprite* play_button;
		//A sprite which is used to represent a button that quits the game.
		Sprite* quit_button;
		//A sprite which is used to represent a button that loads the "Options" scene.
		Sprite* options_button;
		//A sprite which is used to represent a button that starts the "Intro" scene.
		Sprite* intro_button;
};

#endif