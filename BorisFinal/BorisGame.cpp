#include "BorisGame.h"

BorisGame* BorisGame::_instance = NULL;

BorisGame::BorisGame()
{

}

BorisGame::~BorisGame()
{

}

BorisGame* BorisGame::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new BorisGame();
	}
	return _instance;
}

void BorisGame::Run()
{
	Game::Run("intro");
}