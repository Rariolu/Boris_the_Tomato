#include "Menu.h"
#include "SceneManager.h"

Menu::Menu() : Scene("Menu_Background")
{
	
}

Menu::~Menu()
{
	Scene::~Scene();
}

void Menu::Initialise(SDL_Renderer* renderer)
{
	SetMusicName("menu");
	Scene::Initialise(renderer);
	play_button = AddSprite(textureManager->GetTexture("play_game"),1);
	play_button->SetActive(true);
	play_button->SetPosition(100, 50);
	quit_button = AddSprite(textureManager->GetTexture("quit"), 1);
	quit_button->SetActive(true);
	quit_button->SetPosition(100, 400);
	options_button = AddSprite(textureManager->GetTexture("options"), 1);
	options_button->SetActive(true);
	options_button->SetPosition(100, 175);
	intro_button = AddSprite(textureManager->GetTexture("intro_button"), 1);
	intro_button->SetActive(true);
	intro_button->SetPosition(100, 300);
}

bool Menu::GetInput()
{
	SDL_Event event;
	SDL_Point mpos;
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
					if (play_button->Clicked(&mpos))
					{
						SetNextScene("level");
						soundManager->GetSound("click")->Play();
						return false;
					}
					//break;
					if (quit_button->Clicked(&mpos))
					{
						soundManager->GetSound("click")->Play();
						Operations::WaitForMusicToStop();
						//int num = 0;
						//Mix_HaltMusic();
						//while (Mix_Playing(-1) != 0)
						//{
						//	num++;
						//	cout << "Waiting for sfx to finish. Messaged " << num << " times." << endl;
						//}
						return false;
					}
					//break;
					if (options_button->Clicked(&mpos))
					{
						SetNextScene("options");
						soundManager->GetSound("click")->Play();
						return false;
					}
					if (intro_button->Clicked(&mpos))
					{
						SetNextScene("intro");
						soundManager->GetSound("click")->Play();
						return false;
					}
					break;
				}
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						return false;
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
	return true;
}

void Menu::Update(float deltaTime)
{

}