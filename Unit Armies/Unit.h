#pragma once
#include <string>
#include <ostream>

using std::string;
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
	double health;
	float power;
	int attackCapacity;
	std::string type;
	

public:

	Unit(int id = 0, int tj = 0, double health = 0, float power = 0, int attackCap = 0,
		std::string type = NULL) :ID(id), Tj(tj), health(health), power(power),
		attackCapacity(attackCap), type(type){};
	
	/* ===== Getters ======== */

	int GetID() const;
	int GetTj() const ;
	double GetHealth() const;
	float GetPower() const ;
	int GetAttackCap() const;
	string GetType();
	/* ===== Setters ======== */
	void SetID(int id);
	void SetTj(int tj);
	void SetHealth(double heal);
	void SetPower(float powr);
	void SetAttackCap(int AttCap);
	void SetType(string type);




	virtual void attack() = 0;
};

