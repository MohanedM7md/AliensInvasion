#include "ET.h"
#include"../Game.h"
bool ET::choice = false;
int ET::total = 0;
int ET::Killed = 0;
int ET::HealedNom = 0;
ET::ET(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}

int ET::getTotal()
{
	return ET::total;
}

void ET::KilledIncreament()
{
	ET::Killed++;
}

int ET::getKilled()
{
	return ET::Killed;
}
void ET::HealNomIncreament()
{
	HealedNom++;
}
void ET::attack()
{
	alienArmy* Aarmy = Gameptr->GetAlienArmy();
	earthArmy* Barmy = Gameptr->GetEarthArmy();
	if (Aarmy->IfListIsEmpyt("AM"))
		return; // ends the function if it attacking empty list
	LinkedStack<AM*> tempList;
	LinkedStack<AS*> tempList2;
	Output* pOut = Gameptr->getOutputPtr();// get Output ptr
	bool gameMode = Gameptr->getGameMode();//check if the mode is interactive to print


	if (gameMode) { // For the Fight scene output
		pOut->PrintOut("ET ", LIGHT_BLUE);
		pOut->PrintOut(std::to_string(ID));
		pOut->PrintOut(" Shots ", LIGHT_RED);
		pOut->PrintOut('[', DARK_GREEN);
	}



	if (Barmy->GetLength("ES") <= 0.3 * Aarmy->GetLength("AS"))
		choice = true;
	else if (Barmy->GetLength("ES") >= 0.8 * Aarmy->GetLength("AS"))
		choice = false;
	int c = 0;
	if (choice)
	{
		for (int i = 0; i < attackCapacity / 2; i++)
		{
			AS* as = nullptr;
			if (!Aarmy->AS_Getter(as)) break;//if there is no more unit to attack end the loop.
			int dmge = calcDmg(this, as);
			if (gameMode)
				pOut->PrintOut(" " + std::to_string(as->GetID()) + ",");// print the attacked units

			as->SetHealth(as->GetHealth() - dmge); // Set New health
			as->setTa(Gameptr->GetTimeStep()); // Set time attacked
			c++;
			if (!as->GetHealth()) {
				as->setTd(Gameptr->GetTimeStep());
				AS::KilledIncreament();
				Gameptr->addToKillList(as);
			}
			else
				tempList2.push(as);
		}

		while (!tempList2.isEmpty()) { //remove units from temp list
			AS* as;
			tempList2.pop(as);
			Gameptr->addAUnits(as);
		}
		for (int i = c; i < attackCapacity; i++)
		{
			AM* am = nullptr;
			if (!Aarmy->AM_Getter(am)) break;//if there is no more unit to attack end the loop.
			int dmge = calcDmg(this, am);

			if (gameMode)
				pOut->PrintOut(" " + std::to_string(am->GetID()) + ",");// print the attacked units

			am->SetHealth(am->GetHealth() - dmge); // Set New health
			am->setTa(Gameptr->GetTimeStep()); // Set time attacked

			if (!am->GetHealth()) {
				am->setTd(Gameptr->GetTimeStep());
				AM::KilledIncreament();
				Gameptr->addToKillList(am);
			}
			else {
				tempList.push(am);
			}

		}
	}
		if (!choice)
		{
			for (int i = 0; i < attackCapacity; i++) {
				AM* am = nullptr;
				if (!Aarmy->AM_Getter(am)) break;//if there is no more unit to attack end the loop.
				int dmge = calcDmg(this, am);

				if (gameMode)
					pOut->PrintOut(" " + std::to_string(am->GetID()) + ",");// print the attacked units

				am->SetHealth(am->GetHealth() - dmge); // Set New health
				c++;
				am->setTa(Gameptr->GetTimeStep()); // Set time attacked

				if (!am->GetHealth()) {
					am->setTd(Gameptr->GetTimeStep());
					AM::KilledIncreament();
					Gameptr->addToKillList(am);
				}
				else {
					tempList.push(am);
				}

			}



			while (!tempList.isEmpty()) { //remove units from temp list
				AM* am;
				tempList.pop(am);
				Gameptr->addAUnits(am);
			}
		}

		if (gameMode)
			pOut->PrintOut("\b]\n\n", DARK_GREEN);



		while (!tempList.isEmpty()) { //remove units from temp list
			AM* am;
			tempList.pop(am);
			Gameptr->addAUnits(am);
		}

	
}





