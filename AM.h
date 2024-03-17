#pragma once
#include "UnitArmies/Unit.h"

/* ====================== AlienMonsters Class ===========================
 * Description
 *
 * -	Inherit From Unit Class
 * -	Attacks both Tanks and Earth Soldiers
 *
 *
 * ======================================================================
*/

class AlienMonsters : public Unit
{
public:

	AlienMonsters(int id, std::string typ, int tj, int h, int p, int attackCap)
		: Unit(id, tj, h, p, attackCap, "Alien Monster")
	{

	};

	void attack(Unit* Att_unit)
	{
		if (/* Att_unit->Type == "Earth Tanks" || Att_unit->Type == "Earth Soliders" */)
		{
			for (int i = 0; i < AttackCapacity; i++)
			{
				/* Choose Random Unit From The List */
				/* Att_unit->Health = Att_unit->Health - Health; */
				if (/* Att_unit->Health == 0 */)
				{
					// Killed list should have this unit
				}
				else
				{
					// The Game Should Store It in Temp List
				}
			}
		}
		// The Game Should Put Back The Temp List Into The Original List
	};
};

