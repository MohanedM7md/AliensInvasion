#include "AM.h"

int AM::total = 0;
int AM::Killed = 0;

AM::AM(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}

void AM::attack()
{
}

void AM::KilledIncreament()
{
	AM::Killed++;
}

int AM::getKilled()
{
	return AM::Killed;
}

int AM::getTotal()
{
	return AM::total;
}

