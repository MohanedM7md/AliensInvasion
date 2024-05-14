#include "AS.h"
#include "../Game.h"

int AS::total = 0;
int AS::Killed = 0;

AS::AS(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}

int AS::getTotal()
{
	return AS::total;
}

void AS::KilledIncreament()
{
	AS::Killed++;
}

int AS::getKilled()
{
	return AS::Killed;
}

void AS::attack()
{

	earthArmy* Aarmy = Gameptr->GetEarthArmy();
	if (Aarmy->IfListIsEmpyt("ES"))
		return; // ends the function if it attacking empyt list

	LinkedStack<ES*> tempList; // intialize temp list ot hold AS units
	Output* pOut = Gameptr->getOutputPtr();// get Output ptr
	bool gameMode = Gameptr->getGameMode();//check if the mode is interactive to print

	if (gameMode) { // For the Fight scene output
		pOut->PrintOut("AS ", LIGHT_BLUE);
		pOut->PrintOut(std::to_string(ID));
		pOut->PrintOut(" Shots ", LIGHT_RED);
		pOut->PrintOut('[', DARK_GREEN);
	}



	for (int i = 0; i < attackCapacity; i++) {
		ES* es = nullptr;
		if (!Aarmy->ES_Getter(es)) break;//if there is no more unit to attack end the loop.
		int dmge = calcDmg(this, es);

		if (gameMode)
			pOut->PrintOut(" " + std::to_string(es->GetID()) + ",");// print the attacked units

		es->SetHealth(es->GetHealth() - dmge); // Set New health
		es->setTa(Gameptr->GetTimeStep()); // Set time attacked

		if (!es->GetHealth()) {
			ES::KilledIncreament();
			es->setTd(Gameptr->GetTimeStep());
			Gameptr->addToKillList(es);
		}
		else {
			tempList.push(es);
		}

	}
	if (gameMode)
	pOut->PrintOut("\b]\n\n", DARK_GREEN);

	while (!tempList.isEmpty()) { //remove units from temp list
		ES* es;
		tempList.pop(es);
		Gameptr->addEUnits(es);
	}
	Gameptr->GetEarthArmy()->printEarth();
}



