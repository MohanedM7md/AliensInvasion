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
int ES::getInfected()
{
	return ES::InfNom;
}



void ES::attack()
{

	alienArmy* Aarmy = Gameptr->GetAlienArmy();
	earthArmy* Earmy = Gameptr->GetEarthArmy();
	bool gameMode = Gameptr->getGameMode();//check if the mode is interactive to print
	Output* pOut = Gameptr->getOutputPtr();// get Output ptr
	if (gameMode) {
		pOut->PrintOut("Infected Percentage: ", DARK_GREEN);
			pOut->PrintOut(std::to_string(((float)ES::InfNom / (ES::total - ES::Killed))*100) + "%\n\n", LIGHT_RED);
	}
	if (Aarmy->IfListIsEmpyt("AS"))
		return; // ends the function if it attacking empty list

	LinkedStack<AS*> tempList; // intialize temp list to hold AS units
	LinkedStack<ES*> tempList_ES;

	if (gameMode) { // For the Fight scene output
		if (isInfected())
		{
			pOut->PrintOut("Infected ES ", LIGHT_BLUE);
			pOut->PrintOut(std::to_string(ID));
			pOut->PrintOut(" Shots ", LIGHT_RED);
			pOut->PrintOut('[', DARK_GREEN);
		}
		else
		{
			pOut->PrintOut("ES ", LIGHT_BLUE);
			pOut->PrintOut(std::to_string(ID));
			pOut->PrintOut(" Shots ", LIGHT_RED);
			pOut->PrintOut('[', DARK_GREEN);
		}
	}


	
	for (int i = 0; i < attackCapacity; i++) {
		AS* as = nullptr;
		ES* es = nullptr;
		int dmge;
		bool ES_Found = true, AS_Found = true;
		//if there is no more unit to attack end the loop.

		if (isInfected())
		{
			ES_Found = Earmy->ES_Getter(es);
			if (es)
			{
				if (es != this)
				{
					dmge = calcDmg(this, es);

					if (gameMode)
						pOut->PrintOut(" " + std::to_string(es->GetID()) + ",");// print the attacked units

					es->SetHealth(es->GetHealth() - dmge); // Set New health
					es->setTa(Gameptr->GetTimeStep()); // Set time attacked

					if (!es->GetHealth()) {
						es->setTd(Gameptr->GetTimeStep());
						ES::KilledIncreament();
						Gameptr->addToKillList(es);
					}
					else {
						tempList_ES.push(es);
					}
				}
			}

		}
		else
		{
			AS_Found = Aarmy->AS_Getter(as);
			if (as)
			{
				dmge = calcDmg(this, as);

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

		}
		if ((ES_Found == false) &&(AS_Found ==  false)) break;
		 
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
	while (!tempList_ES.isEmpty()) { //remove units from temp list
		ES* es;
		tempList_ES.pop(es);
		Gameptr->addEUnits(es);
	}
}
