#include "allideArmy.h"
#include "../Game.h"



allideArmy::allideArmy(Game* gPtr):gPtr(gPtr)
{
	pOut = gPtr->getOutputPtr();
}

void allideArmy::printAllide()
{
	pOut = gPtr->getOutputPtr();
	pOut->PrintOut("========================================   ", AQUA);
	pOut->PrintOut("Allide Army ALive Units", ORANGE);
	pOut->PrintOut("   ====================================\n", AQUA);

	//=============== print ES Information ========================/
	pOut->ES_Print();
	pOut->PrintOut(std::to_string(SU_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut("  SU", LIGHT_CYAN);
	pOut->PrintOut('[', LIGHT_GREEN);
	SU_List.Print();
	pOut->PrintOut("]\n\n\n\n", LIGHT_GREEN);


}

bool allideArmy::addUnit(Unit* unit)
{
	if (dynamic_cast<SU*>(unit)) 
		return SU_List.enqueue((dynamic_cast<SU*>(unit)));

	return false;
}

bool allideArmy::SU_Getter(SU*& es)
{
	return SU_List.dequeue(es);
}



bool allideArmy::IfListIsEmpyt(string s) const
{
	if (s == "SU")
		return SU_List.isEmpty();


	return false;
}

int allideArmy::GetLength(string s) const
{
	if (s == "ES")
		return SU_List.getLength();

	
	return -1;

}

void allideArmy::FreeArmy()
{
	SU* su;
	while (SU_List.dequeue(su));

}


void allideArmy::attackAliens()
{
	SU* SUattcker;
	if (SU_List.peek(SUattcker))
		SUattcker->attack();
	
}
