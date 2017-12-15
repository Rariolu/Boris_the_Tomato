#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <vector>
#include "Scene.h"
#include "VolumeButton.h"


//A sub-class of "Scene" representing the "Options" scene.
class Options : public Scene
{
	public:
		//Constructor method.
		Options();
		//Destructor method.
		~Options();
		//A method which initialises this scene using a pointer to the sdl renderer.
		void Initialise(SDL_Renderer* renderer);
	private:
		//A method which takes appropriate actions depending on the user's input and returns
		//a boolean representing whether or not to continue running the scene.
		bool GetInput();
		//A method which is called once per frame.
		void Update(float deltaTime);
		//A sprite which is used to represent a button that returns to the "Menu" scene
		//once clicked.
		Sprite* back_button;
		//An array containing all the "VolumeButton" instances that are used to affect
		//the volume of the sound effects.
		vector<VolumeButton*> sfx_buttons;
		//A method that updates which sound effects buttons are and aren't selected
		//depending on which was clicked.
		void SFX_button_selected(VolumeButton* button);
		//An array containing all the "VolumeButton" instances that are used to affect
		//the volume of the music.
		vector<VolumeButton*> music_buttons;
		//A method that updates which music buttons are and aren't selected
		//depending on which was clicked.
		void Music_button_selected(VolumeButton* button);
		//A method which initialises a set of volume buttons using a given sound type and start location.
		void init_buttons(vector<VolumeButton*>* buttons,SoundType soundtype,float startx, float y);
};

#endif