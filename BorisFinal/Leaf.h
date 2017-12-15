#ifndef _LEAF_H
#define _LEAF_H

#include "Sprite.h"

//An enumeration representing the two alternate states that a leaf can be in.
enum LeafState {RETRACTED, PROTRUDING};

//A sub-class of "Sprite" representing a leaf.
class Leaf : public Sprite
{
	public:
		//Constructor method.
		Leaf();
		//Destructor method.
		~Leaf();
		//Retracts the leaf.
		void Retract();
		//Protrudes the leaf.
		void Protrude();
		//Returns the current leaf state.
		LeafState GetLeafState();
		//Retracts the leaf if it's protruding, protrudes the leaf if it's retracted.
		void AlternateLeafState();
	private:
		//A value representing the current state of the leaf.
		LeafState leafstate = RETRACTED;
};

#endif