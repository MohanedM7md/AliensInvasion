#include "ES.h"

ES::ES(int id, int tj, double health, float power, int attackCap,
	std::string type):Unit(id,tj,health,power, attackCap, type)
{
	
}

void ES::attack()
{
	std::cout << "Attack";
}

