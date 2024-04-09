#pragma once
#include <string>
#include <ostream>


/* ====================== Unit Class ===========================
 * Description
 *
 * -	This is the base class for all army units in the project
 * -	It has data members common to all units
 * -	Fuction Attack is Pure Virtual And overridden by all derived class units
 *
 * =============================================================*/
class Unit{
protected:

	int ID;
	int Tj;
	int health;
	int power;
	int attackCapacity;
	std::string type;
	

public:

	Unit(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0,
		std::string type = NULL) :ID(id), Tj(tj), health(health), power(power),
		attackCapacity(attackCap), type(type){};
	
	/* ===== Getters ======== */

	int GetID() const { return ID; };
	int GetTj() const { return Tj; };
	int GetHealth() const { return health; };
	int GetPower() const { return power; };
	int GetAttackCap() const { return attackCapacity; };
	std::string GetType() const { return type; };

	virtual void attack() = 0;
};

