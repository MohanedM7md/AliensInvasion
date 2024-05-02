#pragma once
#include "Unit.h"


class AS :public Unit {
	static int total;
	static int Killed;

public:
	AS(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0,
		std::string type = "", Game* Gptr = nullptr);
	static int getTotal();
	static void KilledIncreament();
	static int getKilled();
	void attack();
};

static std::ostream& operator<<(std::ostream& os, const AS* unit) {
	os << unit->GetID();
	return os;
}