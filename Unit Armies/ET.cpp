#include "ET.h"

int ET::total = 0;
int ET::Killed = 0;
ET::ET(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}

int ET::getTotal()
{
	return ET::total;
}

void ET::KilledIncreament()
{
	ET::Killed++;
}

int ET::getKilled()
{
	return ET::Killed;
}

void ET::attack()
{
}



