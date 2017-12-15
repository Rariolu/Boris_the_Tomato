#include "Leaf.h"


Leaf::Leaf() : Sprite(texturemanager->GetTexture("retracted_leaf"))
{

}

Leaf::~Leaf()
{

}

void Leaf::Protrude()
{
	if (leafstate == RETRACTED && IsActive())
	{
		SetTexture(texturemanager->GetTexture("protruding_leaf"));
		soundmanager->GetSound("protrude")->Play();
		leafstate = PROTRUDING;
	}
}

void Leaf::Retract()
{
	if (leafstate == PROTRUDING && IsActive())
	{
		SetTexture(texturemanager->GetTexture("retracted_leaf"));
		soundmanager->GetSound("retract")->Play();
		leafstate = RETRACTED;
	}
}

LeafState Leaf::GetLeafState()
{
	return leafstate;
}
//Retract protruding leaf or protrude retracted leaf.
void Leaf::AlternateLeafState()
{
	if (leafstate == PROTRUDING)
	{
		Retract();
	}
	else
	{
		Protrude();
	}
}