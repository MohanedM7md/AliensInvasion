#include "AM.h"

AM::AM(int id, int tj, int health, int power, int attackCap,
	std::string type) :Unit(id, tj, health, power, attackCap, type)
{};

void AM::attack()
{};