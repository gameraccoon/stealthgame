#include "AiRole.h"

#include <LuaInterface/LuaAiState.h>

AiRole::AiRole(World* world, IBody *body) : Role(world, body)
{
	this->states.push(new LuaAiState(world, body, this));
}

AiRole::~AiRole(void)
{
	IAiState *deletedState = this->states.top();
	delete deletedState;
	this->states.pop();
}

void AiRole::update(float deltaTime)
{

}

void AiRole::onTakeDamage(IActor* instigator, float damageValue, Vector2D impulse)
{
	this->states.top()->onTakeDamage(instigator, damageValue, impulse);
}

void AiRole::onSeeEnemy(IActor *enemy)
{
	this->states.top()->onSeeEnemy(enemy);
}

void AiRole::onHearNoise(SoundVolume *sound)
{
}