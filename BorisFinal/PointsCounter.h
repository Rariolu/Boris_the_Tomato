#ifndef  _POINTSCOUNTER_H
#define _POINTSCOUNTER_H

#include<vector>
#include"Util.h"
#include"NumberSprite.h"


//A class which is used to display the current amount of points
//that the player has accumulated.
class PointsCounter
{
	public:
		//Constructor method.
		PointsCounter();
		//Destructor method.
		~PointsCounter();
		//A method which returns a Vector2 value representing
		//the location of this points counter.
		Vector2 GetPosition();
		//A method that sets the current location using a Vector value
		void SetPosition(Vector2 pos);
		//A method that sets the current location using separate x and y values.
		void SetPosition(float x, float y);
		//A method which returns a pointer to all the "NumberSprite" instances
		//associated with this points counter.
		vector<NumberSprite*>* GetNumberSprites();
		//A method that is called once per frame which updates the points
		//counter so that it accurately displays the current amount of points.
		void Update(float deltaTime);
	private:
		//An array containing all the pointers to "NumberSprite" instances
		//that are used to display the individual digits of the points.
		vector<NumberSprite*> numbers;
		//A value which represents the current location of the points counter.
		Vector2 position;
		//A value representing the width of each digit.
		int digitwidth=0;
};

#endif // ! _POINTSCOUNTER_H