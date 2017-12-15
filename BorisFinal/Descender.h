#ifndef _DESCENDER_H
#define _DESCENDER_H


#include "Sprite.h"

//Create an enumeration to represent the different types of descending obstacles.
enum DescenderType {SUNLIGHT, WATER, SCISSORS};

//A sub-class of "Sprite" used to represent a descending obstacle.
class Descender : public Sprite
{
	public:
		//Constructor, taking in a descender type in order to differentiate texture and movement pattern.
		Descender(DescenderType type);
		//Destructor
		~Descender();
		//Update method which is called once per second to move the descender downwards.
		void Update(float deltaTime);
		//Get a Vector2 value containing the per-second movement of the descender.
		Vector2 GetMovementPattern();
		//Set the per-frame movement of the descender.
		void SetMovementPattern(Vector2 movementpattern);
		//Get the type of this descender.
		DescenderType GetDescenderType();
	private:
		//Declare the per-second movement and set it to go downwards 2 units.
		Vector2 movementPattern = { 0,2};
		//The type of this descending obstacle.
		DescenderType descenderType;
		//A method used to get an instance of "Texture" resembling the image of the given descender type.
		static Texture* GetTextureFromType(DescenderType type);
};

#endif