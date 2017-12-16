#ifndef _LETTERSELECTOR_H
#define _LETTERSELECTOR_H

#include "Sprite.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "SoundManager.h"


//A class representing a collection of sprites that allows the player to select a specific letter of the alphabet.
class LetterSelector
{
	public:
		//Constructor method.
		LetterSelector();
		//Destructor method.
		~LetterSelector();
		//A method which is called once per frame to see which,
		//if any, of the sprites associated with this class are
		//currently being clicked.
		void Update(SDL_Point* mouseposition);
		//A method which returns a pointer to all the sprites associated with this class.
		vector<Sprite*>* GetSprites();
		//Return the letter that is currently being shown.
		string CurrentLetter();
		//Return a Vector2 representing the current position of the letter selector.
		Vector2 GetPosition();
		//Set the current position of the letter selector using a Vector2 value.
		void SetPosition(Vector2 position);
		//Set the current position of the letter selector using separate float values for x and y.
		void SetPosition(float x, float y);
		//Determine whether or not the sprites are active.
		void SetActive(bool active);
		//Return a value representing whether or not the sprites are active.
		bool IsActive();
	private:
		//A sprite which is used to represent a button that increments the current letter.
		Sprite* up_arrow;
		//A sprite which is used to represent a button that decrements the current letter.
		Sprite* down_arrow;
		//A sprite which is used to display the current letter.
		Sprite* letter;
		//An array of each letter of the alphabet.
		vector<char> letters;
		//A method which increments the index of the current letter.
		void IncrementIndex();
		//A method which decrements the index of the current letter.
		void DecrementIndex();
		//The index of the current letter.
		int index = 0;
		//A pointer to all the sprites associated with this class.
		vector<Sprite*>* sprites;
		//A method which displays the current letter.
		void DisplayLetter();
		//A pointer to an instance of "TextureManager".
		static TextureManager* texturemanager;
		//A pointer to an instance of "FontManager".
		static FontManager* fontmanager;
		//A pointer to an instance of "SoundManager".
		static SoundManager* soundmanager;
		//A Vector2 value representing the current position of the letter selector.
		Vector2 _position;
		//A boolean representing whether or not the sprites of this class are active.
		bool _active = false;
};

#endif