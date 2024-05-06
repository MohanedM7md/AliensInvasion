#include "ES.h"
#include "../Game.h"

int ES::total = 0;
int ES::Killed= 0;
int ES::InfNom= 0;



ES::ES(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr):Unit(id,tj,health,power, attackCap, type, Gptr)
{
	infected = false;
	total++;
}


int ES::getTotal()
{
	return ES::total;
}

bool ES::isInfected()const
{
	return infected;
}

void ES::setInfected(bool inf)
{
	infected = inf;
}

void ES::KilledIncreament()
{
	ES::Killed++;
}
void ES::InfIncreament()
{
	ES::InfNom++;
}
void ES::InfDecreament()
{
	ES::InfNom--;
}

int ES::getKilled()
{
	return ES::Killed;
}



void ES::attack()
{

	alienArmy* Aarmy = Gameptr->GetAlienArmy();
	bool gameMode = Gameptr->getGameMode();//check if the mode is interactive to print
	Output* pOut = Gameptr->getOutputPtr();// get Output ptr
	if (gameMode) {
		pOut->PrintOut("Infected Percentage: ", DARK_GREEN);
		pOut->PrintOut(std::to_string(((float)ES::InfNom / (ES::total - ES::Killed + 1))*100) + "\n\n", LIGHT_RED);
	}
	if (Aarmy->IfListIsEmpyt("AS"))
		return; // ends the function if it attacking empty list

	LinkedStack<AS*> tempList; // intialize temp list to hold AS units

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
			AS::KilledIncreament();
			Gameptr->addToKillList(as);
		}
		else {
			tempList.push(as);
		}
		 
	}
	for (int i = 0; i < InfNom; i++) {
		int randNom = rand()%101;
		if (randNom < 3) {
			ES* es;
			earthArmy* Aarmy = Gameptr->GetEarthArmy();
			if (Aarmy->ES_randGetter(es))
				es->setInfected(true);
		}
	}
	if (gameMode) {
		pOut->PrintOut("\b]\n\n", DARK_GREEN);

	}
	while (!tempList.isEmpty()) { //remove units from temp list
		AS* as;
		tempList.pop(as);
		Gameptr->addAUnits(as);
	}
}
