#include "EG.h"

int EG::total = 0;

EG::EG(int id, int tj, int health, int power, int attackCap, std::string type, Game* Gptr):Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}



void EG::attack()
{
}

int EG::GetPri()
{
	return ((power*2)+health);
}


