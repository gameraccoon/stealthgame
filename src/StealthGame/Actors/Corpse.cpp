#include "Corpse.h"

Corpse::Corpse(World *world, Vector2D location, Vector2D scale, Rotator rotation) :
	Actor(world, location, rotation)
{
	this->updateActorId("Corpse");
}


Corpse::~Corpse(void)
{
}