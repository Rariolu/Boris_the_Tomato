#include "Intro.h"

Intro::Intro() : Scene("intro")
{

}

Intro::~Intro()
{

}

void Intro::Initialise(SDL_Renderer* renderer)
{
	SetMusicName("intro");
	Scene::Initialise(renderer);
	for (int i = 0; i < slideno; i++)
	{
		string name = "intro_" + to_string(i);
		slides.push_back(AddSprite(textureManager->GetTexture(name),1));
	}
	DisplaySlide();
}

void Intro::Update(float deltaTime)
{
	accumulatedtime += deltaTime;
	if (accumulatedtime >= 200)
	{
		NextSlide();
		
	}
	//cout << (200-accumulatedtime) << endl;
}

bool Intro::GetInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
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
						NextSlide();
						break;
				}
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_SPACE:
						NextSlide();
						break;
					case SDLK_ESCAPE:
						return false;
				}
				break;
		}
	}
	return true;
}

void Intro::NextSlide()
{
	accumulatedtime = 0;
	soundManager->GetSound("click")->Play();
	currentslideindex++;
	if (currentslideindex < slides.size())
	{
		currentSlide->SetActive(false);
		DisplaySlide();
	}
	else
	{
		SetNextScene("menu");
	}
}

void Intro::DisplaySlide()
{
	string name = "intro_" + to_string(currentslideindex);
	currentSlide = slides.at(currentslideindex);
	currentSlide->SetActive(true);
}