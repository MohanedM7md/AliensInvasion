#pragma once
#include <iostream>
#include "../Game.h"

/* ====================== Unit Class ===========================
 * Description
 *
 * -	This is the base class for all army units in the project 
 * -	It has data members common to all units
 * -	Fuction Attack is Pure Virtual And overridden
 *      by all derived class units
 *
 * =============================================================
*/

class Unit 
{
private:

	int ID;
	int Tj;
	double Health;
	float Power;
	int AttackCapacity;
	std::string Type;
	Game* Gptr;

	/*
	Note : A Pointer To Game Class Should Be Added
		   As Stated In The Document
	*/

public:

	Unit (int id, int tj, double health, float power, int attackCap, std::string T)
	{
		SetID(id);
		SetTj(tj);
		SetHealth(health);
		SetPower(power);
		SetAttackCap(attackCap);
		SetType(T);
	};

	/* ===== Getters ======== */

	int GetID() { return ID; };
	int GetTj() { return Tj; };
	double GetHealth() { return Health; };
	float GetPower() { return Power; };
	int GetAttackCap() { return AttackCapacity; };
	std::string GetType() { return Type; };

	/* ======= Setters ======= */

	void SetID(int id)
	{ 
		if (id < 0)
		{
			std::cout << "Join Time Cannot Be Negative\n";
			return;
		}
		ID = id;
	};

	void SetTj(int tj)
	{
		if (tj < 0)
		{
			std::cout << "Join Time Cannot Be Negative\n";
			return;
		}
		Tj = tj;
	};

	double SetHealth(double health) 
	{
		if (health < 0)
		{
			std::cout << "Health Cannot Be Negative\n";
			return;
		}
		Health = health;
	};

	void SetPower(float power)
	{
		if (power < 0)
		{
			std::cout << "Power Cannot Be Negative\n";
			return;
		}
		Power = power;
	};

	void SetAttackCap(int attackCap) 
	{
		if (attackCap < 0)
		{
			std::cout << "Attack Capacity Cannot Be Negative\n";
			return;
		}
		AttackCapacity = attackCap;
	};

	void SetType(std::string T)
	{
		Type = T;
	};

	virtual void attack() = 0;
};
