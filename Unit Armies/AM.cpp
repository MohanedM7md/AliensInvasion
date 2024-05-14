#include "AM.h"
#include "../Game.h"
#include "../Armies' Lists/Array.h"


int AM::total = 0;
int AM::Killed = 0;
int AM::InfProb = 0;

void AM::SetInfProb(int inf)
{
	int infect = rand() % inf;
    InfProb = infect;
}

bool AM::GetInfability()
{
	int infect = rand() % 101;
	return infect <= InfProb;
}


AM::AM(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}

void AM::attack()
{
	earthArmy* EarthArmy = Gameptr->GetEarthArmy();

	/*
	* Monsters Attack Soliders and Tanks So if They Are Not Found, End The Function
	*/


	if (EarthArmy->IfListIsEmpyt("ES") && EarthArmy->IfListIsEmpyt("ET"))
		return;

	LinkedStack<ES*> TempListES;
	LinkedStack<ET*> TempListET;
	Output* pOut = Gameptr->getOutputPtr();
	bool GameMode = Gameptr->getGameMode();

	if (GameMode)
	{
		pOut->PrintOut("AM ", LIGHT_BLUE);
		pOut->PrintOut(std::to_string(ID));
		pOut->PrintOut(" Shoots ", LIGHT_RED);
		pOut->PrintOut('[', DARK_GREEN);
	}

	for (int i = 0; i < attackCapacity; i++)
	{
		ES* At_ES = nullptr;
		ET* At_ET = nullptr;
		bool ET_Found = true, ES_Found = true;
		int damage_ES, damage_ET;

		if (i % 2 == 0)
		{
			ES_Found = EarthArmy->ES_Getter(At_ES);
			if (At_ES)
			{
				damage_ES = calcDmg(this, At_ES);
				if (GameMode)
					pOut->PrintOut(" " + std::to_string(At_ES->GetID()) + ",");
				At_ES->SetHealth(At_ES->GetHealth() - damage_ES);
				At_ES->setTa(Gameptr->GetTimeStep());
				if (!At_ES->GetHealth())
				{
					ES::KilledIncreament();
					At_ES->setTd(Gameptr->GetTimeStep());
					if (At_ES->isInfected())
						ES::InfDecreament();
					Gameptr->addToKillList(At_ES);
					
				}else if (GetInfability() && !At_ES->isInfected()) {
					ES::InfIncreament();
					At_ES->setInfected(true);
					TempListES.push(At_ES);
				}
				else if ((At_ES->GetMaxHealth() / At_ES->GetHealth()) >= 5) {
					At_ES->setTjUml(Gameptr->GetTimeStep());
					Gameptr->getUML1()->enqueue(At_ES, Gameptr->UmlPriEquation(At_ES));

				}
				else
				{
					TempListES.push(At_ES);
				}
			}

		}
		else
		{
			ET_Found = EarthArmy->ET_Getter(At_ET);
			if (At_ET)
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
				else if ((At_ET->GetMaxHealth() / At_ET->GetHealth()) >= 5) {
					At_ET->setTjUml(Gameptr->GetTimeStep());
					Gameptr->getUML2()->enqueue(At_ET);
				}
				else
				{
					TempListET.push(At_ET);
				}
			}
		}
		/*
		* This condtion is To Check if There is Units To Attack
		* " Maybe Attacked Enemies Could All die Before Loop Is Completed"
		*/
		if ((ES_Found == false) && (ET_Found == false))
		{
			break;
		}
	}
	if (GameMode)
		pOut->PrintOut("\b]\n\n", DARK_GREEN);

	while (!TempListES.isEmpty())
	{
		ES* Es_temp;
		TempListES.pop(Es_temp);
		Gameptr->addEUnits(Es_temp);
	}

	while (!TempListET.isEmpty())
	{
		ET* Et_temp;
		TempListET.pop(Et_temp);
		Gameptr->addEUnits(Et_temp);
	}

}

void AM::KilledIncreament()
{
	AM::Killed++;
}

int AM::getKilled()
{
	return AM::Killed;
}

int AM::getTotal()
{
	return AM::total;
}

			/*pOut->PrintOut("In Loop Break", PINK);
			pOut->PrintOut(" Current i : ", LIGHT_BLUE);
			pOut->PrintOut(std::to_string(i), ORANGE);
			pOut->PrintOut(" EG Address ", LIGHT_BLUE);
			if (At_ES)
				pOut->PrintOut("Address is Found", DARK_GREEN);
			else
				pOut->PrintOut("Address is Not Found Found", LIGHT_RED);
			pOut->PrintOut(" ET Address ", LIGHT_BLUE);
			if (At_ET)
				pOut->PrintOut("Address is Found", DARK_GREEN);
			else
				pOut->PrintOut("Address is Not Found Found", LIGHT_RED);*/		
		
		/*pOut->PrintOut(" Current i : ", LIGHT_BLUE);
		pOut->PrintOut(std::to_string(i), ORANGE);
		pOut->PrintOut(" EG Address ", LIGHT_BLUE);
		if (At_ES)
			pOut->PrintOut("Address is Found", DARK_GREEN);
		else
			pOut->PrintOut("Address is Not Found Found", LIGHT_RED);

		pOut->PrintOut(" ET Address ", LIGHT_BLUE);
		if (At_ET)
			pOut->PrintOut("Address is Found", DARK_GREEN);
		else
			pOut->PrintOut("Address is Not Found Found", LIGHT_RED);*/