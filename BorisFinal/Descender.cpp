#include "Descender.h"

//Descender::Descender(Texture* texture) : Sprite(texture)
//{
//
//}

Descender::Descender(DescenderType type) : Sprite(GetTextureFromType(type))
{
	descenderType = type;
	SetAbsoluteScale(0.75, 0.75);
	switch (type)
	{
		case SCISSORS:
			SetMovementPattern({0,7});
			break;
		case SUNLIGHT:
			SetMovementPattern({ 0,7 });
			break;
	}
}

Descender::~Descender()
{

}

void Descender::Update(float deltaTime)
{
	float t = deltaTime;// *1000;
	//cout << t << endl;
	//MsgPosition();
	Translate({ movementPattern.X*t,movementPattern.Y*t });
	SDL_Rect bounds = { 0,0,936,595 };
	if (!CollidesWith(&bounds))
	{
		SetActive(false);
	}
}

Vector2 Descender::GetMovementPattern()
{
	return movementPattern;
}

void Descender::SetMovementPattern(Vector2 movementpattern)
{
	movementPattern = movementpattern;
}

Texture* Descender::GetTextureFromType(DescenderType type)
{
	LPCSTR texturename = "";
	switch (type)
	{
		case SCISSORS:
			texturename = "scissors";
			break;
		case SUNLIGHT:
			texturename = "sunlight";
			break;
		case WATER:
			texturename = "water";
	}
	return texturemanager->GetTexture(texturename);
}

DescenderType Descender::GetDescenderType()
{
	return descenderType;
}