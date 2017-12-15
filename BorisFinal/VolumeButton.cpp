#include "VolumeButton.h"

TextureManager* VolumeButton::texturemanager = TextureManager::getInstance();

VolumeButton::VolumeButton(SoundType soundtype, int volume) : Sprite(texturemanager->GetTexture("inactive_volumebutton"))
{
	soundType = soundtype;
	Volume = volume;
}

VolumeButton::~VolumeButton()
{

}

void VolumeButton::Select()
{
	switch (soundType)
	{
		case SFX:
			Util::GetInstance()->SetSFXVolume(Volume);
			break;
		case MUSIC:
			Util::GetInstance()->SetMusicVolume(Volume);
			break;
	}
	SetTexture(texturemanager->GetTexture("active_volumebutton"));
}

void VolumeButton::DeSelect()
{
	SetTexture(texturemanager->GetTexture("inactive_volumebutton"));
}

int VolumeButton::GetVolume()
{
	return Volume;
}