#ifndef _HIGHSCORESCREEN_H
#define _HIGHSCORESCREEN_H

#include <fstream>
#include "Scene.h"
#include "LetterSelector.h"

//A sub=class of "Scene" which is used to represent the high score screen.
class HighScoreScreen : public Scene
{
	public:
		//Constructor method.
		HighScoreScreen();
		//Destructor method.
		~HighScoreScreen();
		//A method which initialises this scene using a pointer to the sdl renderer.
		void Initialise(SDL_Renderer* renderer);
	private:
		//A method which takes appropriate actions depending on the user's input and returns
		//a boolean representing whether or not to continue running the scene.
		bool GetInput();
		//A method which is called once per frame.
		void Update(float deltaTime);
		//A pointer to an instance of "LetterSelector" representing the first letter selector.
		LetterSelector* letterselector1;
		//A pointer to an instance of "LetterSelector" representing the second letter selector.
		LetterSelector* letterselector2;
		//A pointer to an instance of "LetterSelector" representing the third letter selector.
		LetterSelector* letterselector3;
		//A method which calls the "AddSprite" method for all of the letter selectors.
		void AddLetterSelectorSprites(LetterSelector* letterselector);
		//Gets a combined string representation of the letters that were represented in the three letter selectors.
		string GetInitials();
		//A sprite which is used to represent a button that returns to the "Game over" screen.
		Sprite* back_button;
		//A sprite which is used to represent a button that saves the player's score using the given initials.
		Sprite* save_button;
};

#endif