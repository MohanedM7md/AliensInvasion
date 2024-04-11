#include "AD.h"

AD::AD(int id, int tj, int health, int power, int attackCap,
	std::string type) :Unit(id, tj, health, power, attackCap, type)
{

};

void AD::attack()
{};