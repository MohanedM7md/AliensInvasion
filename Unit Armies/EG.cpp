#include "EG.h"

EG::EG(int id, int tj, int health, int power, int attackCap, std::string type):Unit(id, tj, health, power, attackCap, type)
{
}

void EG::attack()
{

}

int EG::GetPri()
{
	return ((power*2)+health);
}

void EG::Print()
{

}
