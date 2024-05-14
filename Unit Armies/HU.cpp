#include "HU.h"
#include "../Game.h"

int HU::total = 0;
int HU::Killed = 0;


HU::HU(int id, int tj, int health, int power, int attackCap,
	std::string type, Game* Gptr) :Unit(id, tj, health, power, attackCap, type, Gptr)
{
	total++;
}



void HU::attack() 
{
	
	priQueue<ES*>* UML1 = Gameptr->getUML1();
	LinkedQueue<ET*>* UML2 = Gameptr->getUML2();
	if (UML1->isEmpty() && UML2->isEmpty())
		return; // ends the function if it attacking empyt list


	LinkedStack<ES*> tempList1; // intialize temp list ot hold AS units
	LinkedStack<ET*> tempList2; // intialize temp list ot hold AS units
	Output* pOut = Gameptr->getOutputPtr();// get Output ptr
	bool gameMode = Gameptr->getGameMode();//check if the mode is interactive to print

	if (gameMode) { // For the Fight scene output
		pOut->PrintOut("HU ", LIGHT_BLUE);
		pOut->PrintOut(std::to_string(ID));
		pOut->PrintOut(" Healed ", LIGHT_RED);
		pOut->PrintOut('[', DARK_GREEN);
	}

	//setTjUml

	while(attackCapacity-- > 0) {
		ES* es = nullptr;
		int dummy;
		if (!UML1->dequeue(es,dummy)) break;//if there is no more unit to attack end the loop.
		if (Gameptr->GetTimeStep() - es->getTjUml() == 10) {
			ES::KilledIncreament();
			Gameptr->addToKillList(es);
			if (!UML1->dequeue(es, dummy)) break;//if there is no more unit to attack end the loop.
		}
		int Healing = calcDmg(this, es);

		if (gameMode)
			pOut->PrintOut(" " + std::to_string(es->GetID()) + ",");// print the attacked units
		if(es->isInfected())
			es->SetHealth((es->GetHealth() + Healing)/2); // Set New health
		else
			es->SetHealth((es->GetHealth() + Healing)); // Set New health

		if ((es->GetMaxHealth() / es->GetHealth()) <= 5) {
			if (es->isInfected())
				es->setInfected(false);
			ES::HealNomIncreament();
			Gameptr->addEUnits(es);
		}
		else {
			tempList1.push(es);
		}

	}
	while (attackCapacity-- > 0) {
		ET* et = nullptr;
		
		if (!UML2->dequeue(et)) break;//if there is no more unit to attack end the loop.
		if (Gameptr->GetTimeStep() - et->getTjUml() == 10) {
			ET::KilledIncreament();
			Gameptr->addToKillList(et);
			if (!UML2->dequeue(et)) break;//if there is no more unit to attack end the loop.
		}
		int Healing = calcDmg(this, et);

		if (gameMode)
			pOut->PrintOut(" " + std::to_string(et->GetID()) + ",");// print the attacked units

		et->SetHealth(et->GetHealth() + Healing); // Set New health

		if (float(et->GetHealth() / et->GetMaxHealth()) * 10 > 20) {
			ET::HealNomIncreament();
			Gameptr->addEUnits(et);
		}
		else {
			tempList2.push(et);
		}

	}
	if (gameMode)
		pOut->PrintOut("\b]\n\n", DARK_GREEN);

	while (!tempList1.isEmpty()) { //remove units from temp list
		ES* es;
		tempList1.pop(es);
		UML1->enqueue(es,Gameptr->UmlPriEquation(es));
	}
	while (!tempList2.isEmpty()) { //remove units from temp list
		ET* et;
		tempList2.pop(et);
		UML2->enqueue(et);
	}

}




	


	

	

	








