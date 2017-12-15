#include "NumberSprite.h"

NumberSprite::NumberSprite() : Sprite(texturemanager->GetTexture(Operations::Int_to_LPCSTR(0)))
{

}

NumberSprite::~NumberSprite()
{

}

int NumberSprite::GetDisplayNumber()
{
	return displayNumber;
}

void NumberSprite::SetDisplayNumber(int num)
{
	displayNumber = num;
	SetTexture(texturemanager->GetTexture(Operations::Int_to_LPCSTR(num)));
}