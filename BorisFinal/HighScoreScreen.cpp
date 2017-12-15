#include "HighScoreScreen.h"



HighScoreScreen::HighScoreScreen() : Scene("highscore")
{

}

HighScoreScreen::~HighScoreScreen()
{

}

void HighScoreScreen::Initialise(SDL_Renderer* renderer)
{
	SetMusicName("gameover");
	Scene::Initialise(renderer);
	letterselector1 = new LetterSelector();
	letterselector2 = new LetterSelector();
	letterselector3 = new LetterSelector();
	letterselector1->SetPosition(20, 75);
	letterselector2->SetPosition(150, 75);
	letterselector3->SetPosition(280, 75);
	AddLetterSelectorSprites(letterselector1);
	AddLetterSelectorSprites(letterselector2);
	AddLetterSelectorSprites(letterselector3);
	back_button = AddSprite(textureManager->GetTexture("back"), 2);
	back_button->SetPosition(650, 400);
	back_button->SetActive(true);
	save_button = AddSprite(textureManager->GetTexture("save_button"), 2);
	save_button->SetPosition(650, 200);
	save_button->SetActive(true);
}

void HighScoreScreen::AddLetterSelectorSprites(LetterSelector* ls)
{
	for (vector<Sprite*>::iterator sprite = ls->GetSprites()->begin(); sprite < ls->GetSprites()->end(); sprite++)
	{
		AddSprite((*sprite), 1);
	}
}

bool HighScoreScreen::GetInput()
{
	SDL_Event event;
	SDL_Point mouseposition;
	while (SDL_PollEvent(&event))
	{
		mouseposition.x = event.button.x;
		mouseposition.y = event.button.y;
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
						letterselector1->Update(&mouseposition);
						letterselector2->Update(&mouseposition);
						letterselector3->Update(&mouseposition);
						if (back_button->Clicked(&mouseposition))
						{
							soundManager->GetSound("click")->Play();
							SetNextScene("gameover");
							return false;
						}
						if (save_button->Clicked(&mouseposition))
						{
							soundManager->GetSound("click")->Play();
							string message = GetInitials() + ": " + to_string(Util::GetInstance()->GetPoints()) + "\n";
							cout << message << endl;
							ofstream file;
							file.open("Scores\\scores.txt", ios::out | ios::app);
							file << message;
							file.close();
							cout << "Score saved." << endl;
							SetNextScene("gameover");
							return false;
						}
						break;
				}
				break;
		}
	}
	return true;
}

void HighScoreScreen::Update(float deltaTime)
{

}

string HighScoreScreen::GetInitials()
{
	return letterselector1->CurrentLetter() + letterselector2->CurrentLetter() + letterselector3->CurrentLetter();
}