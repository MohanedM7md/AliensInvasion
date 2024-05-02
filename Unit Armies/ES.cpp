#include "ES.h"
#include "../Game.h"

int ES::total = 0;

ES::ES(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr):Unit(id,tj,health,power, attackCap, type, Gptr)
{
	total++;
}


void ES::attack()
{

	alienArmy* Aarmy = Gameptr->GetAlienArmy();
	if (Aarmy->IfListIsEmpyt("AS"))
		return; // ends the function if it attacking empyt list

	LinkedStack<AS*> tempList; // intialize temp list ot hold AS units
	Output* pOut = Gameptr->getOutputPtr();// get Output ptr
	bool gameMode = Gameptr->getGameMode();//check if the mode is interactive to print

	if (gameMode) { // For the Fight scene output
		pOut->PrintOut("ES ", LIGHT_BLUE);
		pOut->PrintOut(std::to_string(ID));
		pOut->PrintOut(" Shots ", LIGHT_RED);
		pOut->PrintOut('[', DARK_GREEN);
	}


	
	for (int i = 0; i < attackCapacity; i++) {
		AS* as = nullptr;
		if (!Aarmy->AS_Getter(as)) break;//if there is no more unit to attack end the loop.
		int dmge = calcDmg(this, as);

		if(gameMode)
			pOut->PrintOut(" " + std::to_string(as->GetID()) + ",");// print the attacked units

		as->SetHealth(as->GetHealth() - dmge); // Set New health
		as->setTa(Gameptr->GetTimeStep()); // Set time attacked

		if (!as->GetHealth()) {
			as->setTd(Gameptr->GetTimeStep());
			Gameptr->addToKillList(as);
		}
		else {
			tempList.push(as);
		}
		 
	}

	pOut->PrintOut("\b]", DARK_GREEN);

	while (!tempList.isEmpty()) { //remove units from temp list
		AS* as;
		tempList.pop(as);
		Gameptr->addAUnits(as);
	}
}
