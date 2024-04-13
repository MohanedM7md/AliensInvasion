#pragma once
#include "Unit.h"


class AS :public Unit {


public:
	AS(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0,
		std::string type = "", Game* Gptr = nullptr);

	void attack();
};

inline std::ostream& operator<<(std::ostream& os, const AS* unit) {
	os << unit->GetID();
	return os;
}