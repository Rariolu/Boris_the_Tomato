#include "LetterSelector.h"

TextureManager* LetterSelector::texturemanager = TextureManager::getInstance();
FontManager* LetterSelector::fontmanager = FontManager::GetInstance();
SoundManager* LetterSelector::soundmanager = SoundManager::GetInstance();

LetterSelector::LetterSelector()
{
	//http://www.cplusplus.com/forum/beginner/62381/
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector<char> alphabet(alpha, alpha + sizeof(alpha) - 1);

	this->letters = alphabet;
	if (!texturemanager->GetTexture("char_A"))
	{
		texturemanager->AddTexture("char_A",fontmanager->GetFont("Calibri")->CreateTextTexture("A", SOLID));
	}
	sprites = new vector<Sprite*>();
	up_arrow = new Sprite(texturemanager->GetTexture("arrow"));
	down_arrow = new Sprite(texturemanager->GetTexture("down_arrow"));
	letter = new Sprite(texturemanager->GetTexture("char_A"));
	sprites->push_back(up_arrow);
	sprites->push_back(letter);
	sprites->push_back(down_arrow);

	SetActive(true);
	_position = { 0,0 };
	SetPosition(0, 0);
}

LetterSelector::~LetterSelector()
{

}

vector<Sprite*>* LetterSelector::GetSprites()
{
	return sprites;
}

void LetterSelector::Update(SDL_Point* mouseposition)
{
	if (up_arrow->Clicked(mouseposition))
	{
		soundmanager->GetSound("click")->Play();
		//DecrementIndex();
		IncrementIndex();
	}
	if (down_arrow->Clicked(mouseposition))
	{
		soundmanager->GetSound("click")->Play();
		//IncrementIndex();
		DecrementIndex();
	}
}

void LetterSelector::DecrementIndex()
{
	index--;
	if (index < 0)
	{
		index = letters.size() - 1;
	}
	DisplayLetter();
}

void LetterSelector::IncrementIndex()
{
	index++;
	if (index >= letters.size())
	{
		index = 0;
	}
	DisplayLetter();
}

void LetterSelector::DisplayLetter()
{
	char c = letters.at(index);
	string name = "char_" + Operations::CharToString(c);
	if (!texturemanager->GetTexture(name))
	{
		texturemanager->AddTexture(name,fontmanager->GetFont("Calibri")->CreateTextTexture(Operations::Char_to_LPCSTR(c),SOLID));
	}
	letter->SetTexture(texturemanager->GetTexture(name));
}

string LetterSelector::CurrentLetter()
{
	return Operations::CharToString(letters.at(index));
}

Vector2 LetterSelector::GetPosition()
{
	return _position;
}

void LetterSelector::SetPosition(Vector2 position)
{
	_position = position;
	up_arrow->SetPosition(position.X + (letter->GetDimensions().w/2), position.Y);
	letter->SetPosition(position.X, position.Y + up_arrow->GetDimensions().h);
	down_arrow->SetPosition(position.X + (letter->GetDimensions().w / 2), position.Y + up_arrow->GetDimensions().h + letter->GetDimensions().h);
}

void LetterSelector::SetPosition(float x, float y)
{
	SetPosition({x, y});
}

void LetterSelector::SetActive(bool active)
{
	_active = active;
	for (vector<Sprite*>::iterator sprite = sprites->begin(); sprite < sprites->end(); sprite++)
	{
		(*sprite)->SetActive(active);
	}
}

bool LetterSelector::IsActive()
{
	return _active;
}