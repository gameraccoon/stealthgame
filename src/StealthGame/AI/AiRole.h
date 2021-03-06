#ifndef AI_ROLE_H
#define AI_ROLE_H

#include <stack>

#include <Engine/AI/Role.h>

class AiRole : public Role
{
public:
	AiRole(World* world, IBody *body);
	virtual ~AiRole(void) override;

	virtual void update(float deltaTime) override;

	virtual void onTakeDamage(IActor *instigator, float damageValue, Vector2D impulse) override;
	virtual void onSeeEnemy(IActor *enemy) override;
	virtual void onHearNoise(SoundVolume *sound) override;

	virtual void gotoState(std::string stateName) override;
	virtual void endCurrentState() override;
private:
	std::stack<IAiState*> states;
	void checkStates();
};

#endif