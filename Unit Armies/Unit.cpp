#include"Unit.h"
#include "../Game.h"

Unit::Unit(int id, int tj, int health, int power, int attackCap, std::string type, Game* Gptr)
{
	SetID(id);
	SetTj(tj);
	SetHealth(health);
	SetPower(power);
	SetAttackCap(attackCap);
	SetType(type);
	SetGamePtr(Gptr);
}


/* ===== Getters ======== */

int Unit::GetID() const
{
	return ID;
}

int Unit::GetTj() const
{
	return  Tj;
}
int Unit::GetHealth() const
{
	return health;
}
int Unit::GetPower() const
{
	return power;
}
int Unit::GetAttackCap() const
{
	return attackCapacity;
}
std::string Unit::GetType()
{
	return std::string(type);
}

Game* Unit::GetGamePtr() const
{
	return Gameptr;
}

/* ===== Setters ======== */

void Unit::SetID(int id)
{
	ID = id;
}

void Unit::SetTj(int tj)
{
	Tj = tj;
}

void Unit::SetHealth(int heal)
{
	if (heal > 100||heal<0)
		return;
	else
		health = heal;
}

void Unit::SetPower(int powr)
{
	if (powr < 0)
		return;
	else
	power = powr;
}

void Unit::SetAttackCap(int AttCap)
{
	if (AttCap < 0)
		return;
	else
	attackCapacity = AttCap;
}

void Unit::SetType(string type)
{
	type = type;
}

void Unit::SetGamePtr(Game* Gptr)
{
	Gameptr = Gptr;
}
;