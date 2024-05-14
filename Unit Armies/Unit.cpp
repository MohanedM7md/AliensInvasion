#include"Unit.h"
#include "../Game.h"

int Unit::calcDmg(Unit* U1, Unit* U2)
{
	return (U1->power * (U1->health / static_cast<double>(100))) / (sqrt(U2->GetHealth()));
}

Unit::Unit(int id, int tj, int health, int power, int attackCap, std::string type, Game* Gptr)
{
	SetID(id);
	SetTj(tj);
	SetHealth(health);
	MaxHelth = health;
	SetPower(power);
	SetAttackCap(attackCap);
	SetType(type);
	SetGamePtr(Gptr);
	Ta = 0;
	Td = 0;
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
int Unit::GetTd() const
{
	return  Td;
}
int Unit::GetTa() const
{
	return  Ta;
}
int Unit::GetHealth() const
{
	return health;
}
int Unit::GetMaxHealth() const
{
	return this->MaxHelth;
}
int Unit::GetPower() const
{
	return power;
}
int Unit::GetAttackCap() const
{
	return attackCapacity;
}
int Unit::getTjUml() const
{
	return this->TjUml;
}
std::string Unit::GetType()
{
	return std::string(type);
}

//Game* Unit::GetGamePtr() const
//{
//	return Gameptr;
//}

/* ===== Setters ======== */

void Unit::SetID(int id)
{
	ID = id;
}

void Unit::SetTj(int tj)
{
	Tj = tj;
}

void Unit::setTa(int ta)
{
	if(ta > 0 && !Ta)
		this->Ta = ta;
}

void Unit::setTd(int td)
{
	if (td > 0)
		this->Td = td;
}

void Unit::setTjUml(int t)
{
	this->TjUml = t;
}

void Unit::SetHealth(int heal)
{
	health = heal > 0 ? heal : 0;
}

void Unit::SetPower(int powr)
{
	if (powr < 0)
		return;

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