#pragma once
#include <string>
#include <ostream>

class Game;

using std::string;
/* ====================== Unit Class ===========================
 * Description
 *
 * -	This is the base class for all army units in the project
 * -	It has data members common to all units
 * -	Fuction Attack is Pure Virtual And overridden by all derived class units
 *
 * =============================================================
 */
class Unit{
protected:

	int ID;
	int Tj;
	int health;
	int power;
	int attackCapacity;
	std::string type;
	Game* Gameptr;
	

public:

	Unit(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0, std::string type = "", Game* Gptr = NULL);
	
	/* ===== Getters ======== */

	int GetID() const;
	int GetTj() const ;
	int GetHealth() const;
	int GetPower() const ;
	int GetAttackCap() const;
	Game* GetGamePtr() const;
	string GetType();

	/* ===== Setters ======== */

	void SetID(int id);
	void SetTj(int tj);
	void SetHealth(int heal);
	void SetPower(int powr);
	void SetAttackCap(int AttCap);
	void SetType(string type);
	void SetGamePtr(Game* Gptr);

	virtual void attack() = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Unit* unit) {
	os << unit->GetID();
	return os;
}