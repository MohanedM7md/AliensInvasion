#pragma once
#include "Unit.h"

class ET :public Unit {
	static int total;
	static int Killed;
	static  bool choice;
	static int HealedNom;
public:
	ET(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0,
		std::string type = " ", Game* Gptr = nullptr);

	static int getTotal();
	static void KilledIncreament();
	static int getKilled();
	static void HealNomIncreament();
	static int gethealed();

	void attack();



};

static std::ostream& operator<<(std::ostream& os, const ET* unit) {
	os << unit->GetID();
	return os;
}



