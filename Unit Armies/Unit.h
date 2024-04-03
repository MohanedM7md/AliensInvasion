#pragma once
#include <string>
#include "../Game.h"

/* ====================== Unit Class ===========================
 * Description
 *
 * -	This is the base class for all army units in the project
 * -	It has data members common to all units
 * -	Fuction Attack is Pure Virtual And overridden by all derived class units
 *
 * =============================================================*/
class Unit{
private:

	int ID;
	int Tj;
	double health;
	float power;
	int attackCapacity;
	std::string type;
	

public:

	Unit(int id = 0, int tj = 0, double health = 0, float power = 0, int attackCap = 0,
		std::string type = NULL) :ID(id), Tj(tj), health(health), power(power),
		attackCapacity(attackCap), type(type)
	{};

	/* ===== Getters ======== */

	int GetID() const { return ID; };
	int GetTj() const { return Tj; };
	double GetHealth() const { return health; };
	float GetPower() const { return power; };
	int GetAttackCap() const { return attackCapacity; };
	std::string GetType() const { return type; };

	virtual void attack() = 0;
};

