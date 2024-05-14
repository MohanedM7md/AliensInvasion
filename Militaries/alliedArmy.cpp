#include "alliedArmy.h"
#include "../Game.h"

alliedArmy::alliedArmy(Game* gPtr)
{
	pOut = gPtr->getOutputPtr();
}

void alliedArmy::printAllied()
{
	pOut = gPtr->getOutputPtr();
	pOut->PrintOut("========================================   ", AQUA);
	pOut->PrintOut("Earth Army ALive Units", ORANGE);
	pOut->PrintOut("   =====================================\n", AQUA);

	//=============== print SU Information ========================/
	pOut->ES_Print();
	pOut->PrintOut(std::to_string(SU_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut("  ES", LIGHT_CYAN);
	pOut->PrintOut('[', LIGHT_GREEN);
	SU_List.Print();
	pOut->PrintOut("]\n\n", LIGHT_GREEN);
}

bool alliedArmy::addUnit(Unit*unit)
{
	if (dynamic_cast<SU*>(unit))
		return SU_List.enqueue((dynamic_cast<SU*>(unit)));

	return false;
}

bool alliedArmy::SU_Getter(SU*&su)
{
	return SU_List.dequeue(su);
}

bool alliedArmy::IfListIsEmpyt(string s) const
{
	if (s == "ES")
		return SU_List.isEmpty();

	return -1;
}

void alliedArmy::attackAliens()
{
	SU* SUattcker;
	if (SU_List.peek(SUattcker))
		SUattcker->attack();
}

int alliedArmy::GetLength(string s) const
{
	if (s == "ES")
		return SU_List.getLength();
}
