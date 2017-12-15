#include "PointsCounter.h"


PointsCounter::PointsCounter()
{
	for (int i = 0; i < 8; i++)
	{
		NumberSprite* ns = new NumberSprite();
		ns->SetActive(true);
		numbers.push_back(ns);
	}
	digitwidth = numbers.at(numbers.size() - 1)->GetDimensions().w;
	SetPosition({ 0,0 });
}

PointsCounter::~PointsCounter()
{

}

void PointsCounter::Update(float deltaTime)
{
	 string points = Operations::PadNumber(Util::GetInstance()->GetPoints(),8);
	 for (size_t i = 0; i < points.size(); i++)
	 {
		 char c = points.at(i);
		 int digit = (int)c - 48;
		 numbers.at(i)->SetDisplayNumber(digit);
		 //LPCSTR character = Operations::Char_to_LPCSTR();

	 }
}

Vector2 PointsCounter::GetPosition()
{
	return position;
}

void PointsCounter::SetPosition(Vector2 pos)
{
	position = pos;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		int index = i;//(numbers.size()-1) - i;
		int adjustment = i*digitwidth;
		numbers.at(index)->SetPosition(pos.X + adjustment, pos.Y);
	}
}

void PointsCounter::SetPosition(float x, float y)
{
	Vector2 pos;
	pos.X = x;
	pos.Y = y;
	SetPosition(pos);
}

vector<NumberSprite*>* PointsCounter::GetNumberSprites()
{
	return &numbers;
}