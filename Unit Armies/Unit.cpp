#include"Unit.h"
/* ===== Getters ======== */
int Unit::GetID() const
{
	return ID;
}

int Unit::GetTj() const
{
	return  Tj;
}
double Unit::GetHealth() const
{
	return health;
}
float Unit::GetPower() const
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
/* ===== Setters ======== */
void Unit::SetID(int id)
{
	ID = id;
}
void Unit::SetTj(int tj)
{
	Tj = tj;
}
void Unit::SetHealth(double heal)
{
	if (heal > 100||heal<0)
		return;
	else
		health = heal;
}
void Unit::SetPower(float powr)
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
;