#pragma once
#include <ostream>
#include "Unit.h"
class ostream;
class ES :public Unit{


public:
	ES(int id = 0, int tj = 0, double health = 0, float power = 0, int attackCap = 0,
		std::string type = NULL);

	friend ostream& operator<<(ostream& os, const ES& dt);
	void attack();
};



