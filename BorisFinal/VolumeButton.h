#ifndef _VOLUMEBUTTON_H
#define _VOLUMEBUTTON_H

#include "Sprite.h"
#include "TextureManager.h"
#include "Sound.h"
#include "Util.h"

//A sub-class of "Sprite" which represents a button which changes audio volume.
class VolumeButton : public Sprite
{
	public:
		//Constructor, takes the sound type that it affects
		//and the volume that it sets that sound type to.
		VolumeButton(SoundType soundtype, int volume);
		//Destructor method.
		~VolumeButton();
		//A method which selects this button, causing it
		//to appear as such and to set the volume of
		//its given sound type to its given volume.
		void Select();
		//A method which deselects this button, causing it
		//to appear not selected.
		void DeSelect();
		//A method which returns the volume that this button
		//sets audio to.
		int GetVolume();
	private:
		//A pointer to an instance of the "TextureManager" class.
		static TextureManager* texturemanager;
		//A value representing the type of audio that
		//this button affects.
		SoundType soundType;
		//An integer which represents the volume that this button
		//sets audio to.
		int Volume;
};

#endif