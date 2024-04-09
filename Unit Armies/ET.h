#pragma once
#include "Unit.h"

class ET :public Unit {


public:
	ET(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0,
		std::string type = " ");

	void attack();



};

inline std::ostream& operator<<(std::ostream& os, const ET* unit) {
	os << unit->GetID();
	return os;
}



