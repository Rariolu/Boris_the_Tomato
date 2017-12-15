#include "PauseMenu.h"

PauseMenu::PauseMenu() : Scene("Menu_Background")
{

}

PauseMenu::~PauseMenu()
{

}

void PauseMenu::Initialise(SDL_Renderer* renderer)
{
	SetMusicName("menu");
	Scene::Initialise(renderer);
	resume_button = AddSprite(textureManager->GetTexture("resume_game"), 1);
	resume_button->SetActive(true);
	resume_button->SetPosition(100, 100);
	quit_button = AddSprite(textureManager->GetTexture("quit"), 1);
	quit_button->SetActive(true);
	quit_button->SetPosition(100, 400);
	options_button = AddSprite(textureManager->GetTexture("options"), 1);
	options_button->SetActive(true);
	options_button->SetPosition(100, 250);
}

bool PauseMenu::GetInput()
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
					if (resume_button->Clicked(&mpos))
					{
						soundManager->GetSound("click")->Play();
						return false;
					}
					if (quit_button->Clicked(&mpos))
					{
						soundManager->GetSound("click")->Play();
						SetNextScene("[EXIT GAME]");
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
					if (options_button->Clicked(&mpos))
					{
						soundManager->GetSound("click")->Play();
						Scene* options = SceneManager::GetInstance()->GetScene("options");
						options->Initialise(GetRenderer());
						options->Run();
						//SetNextScene("options");
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

void PauseMenu::Update(float deltaTime)
{

}