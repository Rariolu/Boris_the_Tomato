#ifndef _BORISGAME_H
#define _BORISGAME_H

#include "Game.h"

//A sub-class of "Game" used to represent the specific "Boris the Tomato" game.
//Singleton so that only one instance can be accessed.
class BorisGame : public Game
{
	public:
		//A method which returns a pointer to the only instance of this class.
		static BorisGame* GetInstance();
		//Destructor method.
		~BorisGame();
		//A method which starts the actual gameplay.
		void Run();
	private:
		//Constructor method, private so that an instance can't be created outside of this class.
		BorisGame();
		//A pointer to the only instance of this class.
		static BorisGame* _instance;
		
};

#endif // !_BORISGAME_H