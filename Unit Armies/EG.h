#pragma once
#include "Unit.h"
class EG :public Unit {
	

public:
	EG(int id = 0, int tj = 0, double health = 0, float power = 0, int attackCap = 0,
		std::string type = "");

	void attack();
	float  GetPri();
	void Print();
	

};
