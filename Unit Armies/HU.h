#pragma once

#include "Unit.h"
class Game;
using namespace std;

class HU: public Unit
{
private: 
	static int total;
	static int Killed;

public:
	HU(int id = 0, int tj = 0, int health = 0, int power = 0, int attackCap = 0,
		std::string type = "", Game* Gptr = nullptr);

	void attack();
	
	
};