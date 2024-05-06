#pragma once
#include "Unit.h"


class ES :public Unit {
	static int total;
	static int Killed;
	

public:
	ES(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0,
		std::string type = "", Game* Gptr = nullptr);

	static int getTotal();
	static void KilledIncreament();
	static int getKilled();

	void attack();
};

static std::ostream& operator<<(std::ostream& os, const ES* unit) {
	os << unit->GetID();
	return os;
}

