#include "AM.h"

int AM::total = 0;

AM::AM(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}

void AM::attack()
{
}

