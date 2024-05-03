#include "AD.h"
#include "../Game.h"

int AD::total = 0;
int AD::Killed = 0;

AD::AD(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}

void AD::KilledIncreament()
{
	AD::Killed++;
}

int AD::getKilled()
{
	return AD::Killed;
}

int AD::getTotal()
{
	return AD::total;
}

void AD::attack()
{
	earthArmy* EarthArmy = Gameptr->GetEarthArmy();

	/*
	* Drones Attack Gunnery and Tanks So if They Are Not Found, End The Function
	*/

	if (EarthArmy->IfListIsEmpyt("ET") && EarthArmy->IfListIsEmpyt("EG"))
		return;

	LinkedStack<EG*> TempListEG;
	LinkedStack<ET*> TempListET;
	int Dummy;
	Output* pOut = Gameptr->getOutputPtr();
	bool GameMode = Gameptr->getGameMode();

	if (GameMode)
	{
		pOut->PrintOut("AD ", LIGHT_BLUE);
		pOut->PrintOut(std::to_string(ID));
		pOut->PrintOut(" Shoots ", LIGHT_RED);
		pOut->PrintOut('[', DARK_GREEN);
	}

	for (int i = 0; i < attackCapacity; i++)
	{
		EG* At_EG = nullptr;
		ET* At_ET = nullptr;

		/*
		* This condtion is To Check if There is Units To Attack
		* " Maybe Attacked Enemies Could All die Before Loop Is Completed"
		*/
		if (!EarthArmy->EG_Getter(At_EG, Dummy) && !EarthArmy->ET_Getter(At_ET))
			break;

		int damage_ET, damage_EG;
		if (i % 2 == 0)
		{
			if (At_EG != nullptr)
			{
				damage_EG = calcDmg(this, At_EG);
				if (GameMode)
					pOut->PrintOut(" " + std::to_string(At_EG->GetID()) + ",");
				At_EG->SetHealth(At_EG->GetHealth() - damage_EG);
				At_EG->setTa(Gameptr->GetTimeStep());
				if (!At_EG->GetHealth())
				{
					ES::KilledIncreament();
					At_EG->setTd(Gameptr->GetTimeStep());
					Gameptr->addToKillList(At_EG);
				}
				else
				{
					TempListEG.push(At_EG);
				}
			}

		}
		else
		{
			if (At_ET != nullptr)
			{
				damage_ET = calcDmg(this, At_ET);
				At_ET->SetHealth(At_ET->GetHealth() - damage_ET);
				if (GameMode)
					pOut->PrintOut(" " + std::to_string(At_ET->GetID()) + ",");
				At_ET->setTa(Gameptr->GetTimeStep());
				if (!At_ET->GetHealth())
				{
					ET::KilledIncreament();
					At_ET->setTd(Gameptr->GetTimeStep());
					Gameptr->addToKillList(At_ET);
				}
				else
				{
					TempListET.push(At_ET);
				}
			}
		}
	}
	if (GameMode)
		pOut->PrintOut("\b]\n\n", DARK_GREEN);

	while (!TempListEG.isEmpty())
	{
		EG* EG_temp;
		TempListEG.pop(EG_temp);
		Gameptr->addEUnits(EG_temp);
	}

	while (!TempListET.isEmpty())
	{
		ET* Et_temp;
		TempListET.pop(Et_temp);
		Gameptr->addEUnits(Et_temp);
	}

}