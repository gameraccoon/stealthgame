#include "PlayerRole.h"

PlayerRole::PlayerRole(World* world, IBody *body) : Role(world, body)
{
}

PlayerRole::~PlayerRole(void)
{
}

void PlayerRole::update(float deltaTime)
{
}

void PlayerRole::onTakeDamage(IActor* instigator, float damageValue, Vector2D impulse)
{
}

void PlayerRole::onSeeEnemy(IActor *enemy)
{
}

void PlayerRole::onHearNoise(SoundVolume *sound)
{
}

void PlayerRole::gotoState(std::string stateName)
{
}

void PlayerRole::endCurrentState()
{
}