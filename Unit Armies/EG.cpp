#include "EG.h"

EG::EG(int id, int tj, double health, float power, int attackCap, std::string type):Unit(id, tj, health, power, attackCap, type)
{
}

void EG::attack()
{

}

float EG::GetPri()
{
	return ((power*2)+health);
}

void EG::Print()
{

}
