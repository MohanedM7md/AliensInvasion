#include "AS.h"
#include "../Game.h"

int AS::total = 0;

AS::AS(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}

void AS::attack()
{
}



