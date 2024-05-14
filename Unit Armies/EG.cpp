#include "EG.h"
#include"../Game.h"

int EG::total = 0;
int EG::Killed = 0;

EG::EG(int id, int tj, int health, int power, int attackCap, std::string type, Game* Gptr):Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}



void EG::attack()
{
	alienArmy* Aarmy = Gameptr->GetAlienArmy();
	if (Aarmy->IfListIsEmpyt("AM"))
		return; // ends the function if it attacking empty list

	LinkedStack<AM*> tempList;
	LinkedStack<AD*> tempList1;// initialize temp list ot hold AS units
	Output* pOut = Gameptr->getOutputPtr();// get Output ptr
	bool gameMode = Gameptr->getGameMode();//check if the mode is interactive to print

	if (gameMode) { // For the Fight scene output
		pOut->PrintOut("EG ", LIGHT_BLUE);
		pOut->PrintOut(std::to_string(ID));
		pOut->PrintOut(" Shots ", LIGHT_RED);
		pOut->PrintOut('[', DARK_GREEN);
	}
	int c = 0;
	for (int i = 0; i < attackCapacity/2; i++) {
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
	for ( int i = c; i < attackCapacity; i++)
	{
		AD* ad1 = nullptr;
		AD* ad2 = nullptr;
		if (!Aarmy->AD_Getter(ad1,ad2)) break;//if there is no more unit to attack end the loop.
		int dmge = calcDmg(this, ad1);


		if (gameMode) {
			pOut->PrintOut(" " + std::to_string(ad1->GetID()) + ",");// print the attacked units
			pOut->PrintOut(" " + std::to_string(ad2->GetID()) + ",");
		}

		ad1->SetHealth(ad1->GetHealth() - dmge); // Set New health
		ad2->SetHealth(ad2->GetHealth() - calcDmg(this, ad2)); // Set New health
		ad1->setTa(Gameptr->GetTimeStep()); // Set time attacked
		ad2->setTa(Gameptr->GetTimeStep()); // Set time attacked


		if (!ad1->GetHealth()) {
			ad1->setTd(Gameptr->GetTimeStep());
			AD::KilledIncreament();
			Gameptr->addToKillList(ad1);
		}
		else {
			tempList1.push(ad1);
		}
		if (!ad2->GetHealth()) {
			ad2->setTd(Gameptr->GetTimeStep());
			AD::KilledIncreament();
			Gameptr->addToKillList(ad2);
		}
		else {
			tempList1.push(ad2);
		}
	}
	if (gameMode)
		pOut->PrintOut("\b]\n\n", DARK_GREEN);

	while (!tempList.isEmpty()) { //remove units from temp list
		AM* am;
		tempList.pop(am);
		Gameptr->addAUnits(am);
	}while (!tempList1.isEmpty()) { //remove units from temp list
		AD* ad;
		tempList1.pop(ad);
		Gameptr->addAUnits(ad);
	}
	
}

int EG::GetPri()
{
	return ((power*2)+health);
}

void EG::KilledIncreament()
{
	EG::Killed++;
}

int EG::getKilled()
{
	return EG::Killed;
}

int EG::getTotal()
{
	return EG::total;
}


