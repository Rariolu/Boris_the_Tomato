#ifndef _PAUSEMENU_H
#define _PAUSEMENU_H

#include "Scene.h"
#include "SceneManager.h"

//A sub-class of "Scene" which is used to represent the pause menu scene.
class PauseMenu : public Scene
{
	public:
		//Constructor method.
		PauseMenu();
		//Destructor method.
		~PauseMenu();
		//A method which initialises this scene using a pointer to the sdl renderer.
		void Initialise(SDL_Renderer* renderer);
	private:
		//A method which takes appropriate actions depending on the user's input and returns
		//a boolean representing whether or not to continue running the scene.
		bool GetInput();
		//A method which is called once per frame.
		void Update(float deltaTime);
		//A sprite which is used to represent a button that unloads this scene and resumes
		//the game when clicked.
		Sprite* resume_button;
		//A sprite which is used to represent a button that quits the game when clicked.
		Sprite* quit_button;
		//A sprite which is used to represent a button that loads the "Options" scene
		//when clicked.
		Sprite* options_button;
};

#endif