#include "ET.h"

int ET::total = 0;

ET::ET(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}

void ET::attack()
{
}



