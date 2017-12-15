#include "Options.h"

Options::Options() : Scene("Menu_Background")
{

}

Options::~Options()
{

}

void Options::Initialise(SDL_Renderer* renderer)
{
	SetMusicName("menu");
	Scene::Initialise(renderer);
	back_button = AddSprite(textureManager->GetTexture("back"), 1);
	back_button->SetActive(true);
	back_button->SetPosition(100, 400);

	const float sfxY = 250;
	
	sfx_buttons.clear();

	
	//sfx_buttons.push_back(sfx_0);
	//sfx_buttons.push_back(sfx_25);
	//sfx_buttons.push_back(sfx_75);
	//sfx_buttons.push_back(sfx_100);
	

	init_buttons(&sfx_buttons, SFX, 100, sfxY);

	const float musicY = 75;

	music_buttons.clear();

	//music_buttons.push_back(music_0);
	//music_buttons.push_back(music_25);
	//music_buttons.push_back(music_75);
	//music_buttons.push_back(music_100);

	init_buttons(&music_buttons, MUSIC, 100, musicY);

	if (!textureManager->GetTexture("lblMusic"))
	{
		textureManager->AddTexture("lblMusic", fontmanager->GetFont("Consolas")->CreateTextTexture("Music", SOLID));
	}
	if (!textureManager->GetTexture("lblSFX"))
	{
		textureManager->AddTexture("lblSFX", fontmanager->GetFont("Consolas")->CreateTextTexture("SFX", SOLID));
	}

	Sprite* lblMusic = new Sprite(textureManager->GetTexture("lblMusic"));
	lblMusic->SetPosition(100, 40);
	lblMusic->SetActive(true);
	AddSprite(lblMusic, 5);

	Sprite* lblSFX = new Sprite(textureManager->GetTexture("lblSFX"));
	lblSFX->SetPosition(100, 200);
	lblSFX->SetActive(true);
	AddSprite(lblSFX, 5);
}

void Options::init_buttons(vector<VolumeButton*>* buttons,SoundType soundtype,float startx, float y)
{
	vector<int> volumes;
	volumes.push_back(0);
	volumes.push_back(25);
	volumes.push_back(75);
	volumes.push_back(100);
	
	for (size_t i = 0; i < volumes.size(); i++)
	{
		int volume = volumes.at(i);
		//if (i < volumes.size())
		//{
		//	volume = volumes.at(i);
		//}
		//else
		//{
		//	volume = 50;
		//	cout << "Error: volume button (" << soundtype<< ", " << i << ") set to volume of 50" << endl;
		//}
		buttons->push_back(new VolumeButton(soundtype, volume));
		//buttons->at(i) = new VolumeButton(soundtype, volume);
		buttons->at(i)->SetScale(0.75, 0.75);
		buttons->at(i)->SetPosition(startx + (150 * i), y);
		buttons->at(i)->SetActive(true);
		switch (soundtype)
		{
			case MUSIC:
				if (volume == Util::GetInstance()->GetMusicVolume())
				{
					buttons->at(i)->Select();
				}
				break;
			case SFX:
				if (volume == Util::GetInstance()->GetSFXVolume())
				{
					buttons->at(i)->Select();
				}
				break;
			default:
				break;
		}
		AddSprite(buttons->at(i), 1);
	}
}

bool Options::GetInput()
{
	SDL_Event event;
	SDL_Point mpos;
	//bool sfx_volume_clicked = false;
	//bool music_volume_clicked = false;
	while (SDL_PollEvent(&event))
	{
		mpos.x = event.button.x;
		mpos.y = event.button.y;
		if (event.type == SDL_QUIT)
		{
			return false;
		}
		switch (event.type)
		{
			case SDL_MOUSEBUTTONDOWN:
				switch (event.button.button)
				{
					case SDL_BUTTON_LEFT:
						if (back_button->Clicked(&mpos))
						{
							SetNextScene("menu");
							soundManager->GetSound("click")->Play();
							return false;
						}
						for (vector<VolumeButton*>::iterator i = sfx_buttons.begin(); i < sfx_buttons.end(); i++)
						{
							if ((*i)->Clicked(&mpos))
							{
								//(*i)->Select();
								//sfx_volume_clicked = true;
								SFX_button_selected((*i));
								soundManager->GetSound("click")->Play();
							}
							//else if (sfx_volume_clicked)
							//{
							//	(*i)->DeSelect();
							//}
						}
						for (vector<VolumeButton*>::iterator i = music_buttons.begin(); i < music_buttons.end(); i++)
						{
							if ((*i)->Clicked(&mpos))
							{
								//(*i)->Select();
								//music_volume_clicked = true;
								Music_button_selected((*i));
								soundManager->GetSound("click")->Play();
							}
							//else if (music_volume_clicked)
							//{
							//	(*i)->DeSelect();
							//}
						}
						break;
				}
				break;
		}
	}
	return true;
}

void Options::Update(float deltaTime)
{

}

void Options::SFX_button_selected(VolumeButton* button)
{
	for (vector<VolumeButton*>::iterator i = sfx_buttons.begin(); i < sfx_buttons.end(); i++)
	{
		if ((*i) == button)
		{
			(*i)->Select();
		}
		else
		{
			(*i)->DeSelect();
		}
	}
}

void Options::Music_button_selected(VolumeButton* button)
{
	for (vector<VolumeButton*>::iterator i = music_buttons.begin(); i < music_buttons.end(); i++)
	{
		if ((*i) == button)
		{
			(*i)->Select();
		}
		else
		{
			(*i)->DeSelect();
		}
	}
}