#ifndef IACTOR_H
#define IACTOR_H

#include "../src/Globals.h"
#include "../src/Vector2D.h"
#include "../src/Rotator.h"
#include "../src/BoundingBox.h"
#include "../src/Hull.h"

/** Types of an actors */
enum EActorType
{
	AT_Ghost,	// haven't collision, may not be shown
	AT_Static,	// static objects like wall			// added in collisions list
	AT_Dynamic,	// movable objects like barrel		// added in collisions list and check collisions only on moving
	AT_Living,	// player or NPC					// added in collisions list and check collisions always
	AT_Bullet,	// basic bullets					// check collisions all life cycle but not be added in collisions list
	AT_Special,	// doors, rockets, turrels, etc.
	AT_Light
};

/**
 * Interface for class Actor
 */
class IActor
{
public:
	/** Set new location of the actor in the World */
	virtual void SetLocation(const Vector2D& newLocations) = 0;
	/** Get actor's world location */
	virtual Vector2D GetLocation() = 0;
	/** Set actor's rotation */
	virtual void SetRotation(const Rotator& newRotation) = 0;
	/** Get actor's rotation */
	virtual Rotator GetRotation() = 0;
	/** Set actor's scale */
	virtual void SetScale(const Vector2D& newScale) = 0;
	/** Get actor's scale */
	virtual Vector2D GetScale() = 0;
	/** Process moving and other actions of the Actor */
	virtual void Update(float deltaTime) = 0;
	/** Render the actor in the current location */
	virtual void Render(Vector2D shift, Rotator angle) = 0;
	/** Get actor type */
	virtual EActorType GetType() = 0;
	/** Get axis-aligned bounding box */
	virtual BoundingBox GetBoundingBox() = 0;
	/** Get hull of this actor */
	virtual Hull* GetHull() = 0;
	/** Take some damage to the actor */
	virtual void TakeDamage(float damageValue, Vector2D impulse) = 0;
	/** Returns class identificator of this actor */
	virtual std::string GetClassID() = 0;
};

#endif