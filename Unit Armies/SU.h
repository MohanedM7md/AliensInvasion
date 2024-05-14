#pragma once
#include "../Unit Armies/Unit.h"

class SU :public Unit{
	static int total;
	static int Killed;

public:
	SU(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0,
		std::string type = "", Game* Gptr = nullptr);
	static int getTotal();
	static void KilledIncreament();
	static int getKilled();
	void attack();

};
static std::ostream& operator<<(std::ostream& os, const SU* unit) {
	os << unit->GetID();
	return os;
}

