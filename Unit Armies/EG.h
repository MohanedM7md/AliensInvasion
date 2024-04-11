#pragma once
#include "Unit.h"
class EG :public Unit {
	

public:
	EG(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0,
		std::string type = "");

	void attack();
	float  GetPri();
	void Print();
	

};

inline std::ostream& operator<<(std::ostream& os, const EG* unit) {
	os << unit->GetID();
	return os;
}

