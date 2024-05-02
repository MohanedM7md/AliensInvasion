#include "AD.h"

int AD::total = 0;

AD::AD(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}

void AD::attack()
{
}


