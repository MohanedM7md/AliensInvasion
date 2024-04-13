#include "AS.h"

AS::AS(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{

}


void AS::attack()
{
}
