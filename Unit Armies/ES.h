#pragma once
#include "Unit.h"


class ES :public Unit {
	static int total;
	static int Killed;
	static int InfNom;
	static int HealedNom;
	bool infected;

public:
	ES(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0,
		std::string type = "", Game* Gptr = nullptr);

	static int getTotal();
	static void KilledIncreament();
	static void InfIncreament();
	static void InfDecreament();
	static void HealNomIncreament();
	static int getKilled();
	static int getInfected();
	bool isInfected() const;
	void setInfected(bool);
	static int gethealed();

	void attack();
};

static std::ostream& operator<<(std::ostream& os, const ES* unit) {
	if(unit->isInfected())
		os <<'X'<< unit->GetID();
	else
		os << unit->GetID();
	return os;
}

