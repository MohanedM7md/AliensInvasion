#pragma once
class Unit {
	const int ID;
	int Tj;
	double Health;
	float Power;
	int AttackCapacity;
public:
	virtual void attack() = 0;
};
