#pragma once
#pragma once
#include "Unit.h"
#include <iostream>

/* ====================== AlienDrones Class ===========================
 * Description
 *
 * -	Inherit From Unit Class
 * -	Attacks both Tanks and Gunnery
 * -	Must Attack in Pairs
 *
 * ======================================================================
*/

class AD : public Unit
{
	static int total;
	static int Killed;
public:

	AD(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0, std::string type = "", Game* Gptr = nullptr);
	void attack();

	static void KilledIncreament();
	static int getKilled();
	static int getTotal();


};

static std::ostream& operator<<(std::ostream& os, const AD& unit) {
	os << unit.GetID();
	return os;
}

