#include "AM.h"

AM::AM(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{}

void AM::attack()
{
}

