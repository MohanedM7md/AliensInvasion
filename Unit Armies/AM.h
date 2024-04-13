#pragma once
#include "Unit.h"
#include <iostream>

/* ====================== AlienMonsters Class ===========================
 * Description
 *
 * -	Inherit From Unit Class
 * -	Attacks both Tanks and Earth Soldiers
 *
 *
 * ======================================================================
*/

class AM : public Unit
{
public:

	AM(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0, std::string type = "", Game* Gptr = nullptr);
	void attack();
};

inline std::ostream& operator<<(std::ostream& os, const AM* unit) {
	os << unit->GetID();
	return os;
}