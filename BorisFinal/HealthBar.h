#ifndef _HEALTHBAR_H
#define _HEALTHBAR_H

#include "Sprite.h"

//A sub-class of "Sprite" which is used to display a health bar.
class HealthBar : public Sprite
{
	public:
		//Constructor method.
		HealthBar();
		//Destructor method.
		~HealthBar();
		//A method which is run once per frame which updates the healthbar's appearance to
		//appropriately match the amount of health that the player has.
		void Update();
};

#endif