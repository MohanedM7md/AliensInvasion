#include "alienArmy.h"
#include "../Game.h"



alienArmy::alienArmy(Game* gPtr) :gPtr(gPtr)
{
	pOut = gPtr->getOutputPtr();
}

void alienArmy::printAlien()
{
	pOut = gPtr->getOutputPtr();
	pOut->PrintOut("========================================   ", AQUA);
	pOut->PrintOut("Alien Army ALive Units", ORANGE);
	pOut->PrintOut("   =====================================\n", AQUA);
	//print Unit Charcter then the list of it
	//=============== print AS Information ========================/
	pOut->AS_print();
	pOut->PrintOut(std::to_string(AS_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut("  AS", LIGHT_CYAN);
	pOut->PrintOut('[', LIGHT_GREEN);
	AS_List.Print();
	pOut->PrintOut("]\n\n", LIGHT_GREEN);
	//=============== print AM Information ========================/
	pOut->AM_print();
	pOut->PrintOut(std::to_string(AM_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut("  AM", LIGHT_CYAN);
	pOut->PrintOut('[', LIGHT_GREEN);
	AM_List.print();
	pOut->PrintOut("]\n\n", LIGHT_GREEN);
	//=============== print AD Information ========================/
	pOut->AD_print();
	pOut->PrintOut(std::to_string(AD_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut("  AD", LIGHT_CYAN);
	pOut->PrintOut('[', LIGHT_GREEN);
	AD_List.Print();
	pOut->PrintOut("]\n\n", LIGHT_GREEN);
}

bool alienArmy::addUnit(Unit* unit)
{
	if (dynamic_cast<AS*>(unit))
		return AS_List.enqueue((dynamic_cast<AS*>(unit)));

	else if (dynamic_cast<AM*>(unit))
	{
		
		return AM_List.add(dynamic_cast<AM*>(unit));
	}

	else if (dynamic_cast<AD*>(unit)) {
		if (AD_List.getLength() % 2)
			return AD_List.enqueueFront((dynamic_cast<AD*>(unit)));
		else
			return AD_List.enqueueBack((dynamic_cast<AD*>(unit)));
	}

	return false;
}


bool alienArmy::AS_Getter(AS*& as)
{
	return AS_List.dequeue(as);
}

bool alienArmy::AM_Getter(AM*& am)
{
	return AM_List.remove(am);
}

bool alienArmy::AD_Getter(AD*& adFrnt, AD*&adBack)
{
	
	if (AD_List.getLength() < 2)
		return false;

	return (AD_List.dequeueFront(adFrnt) && AD_List.dequeueBack(adBack));
}

bool alienArmy::AD_Getter_Back(AD*& adBack)
{

	if (AD_List.getLength() < 2)
		return false;

	return (AD_List.dequeueBack(adBack));
}

bool alienArmy::IfListIsEmpyt(string s) const
{
	if (s == "AS")
		return AS_List.isEmpty();
	else if (s == "AM")
		return AM_List.isEmpty();
	else if(s == "AD")
		return AD_List.isEmpty();
	return false;
}

void alienArmy::attackEarthians()
{
	AS* ASattcker;
	if (AS_List.peek(ASattcker))
		ASattcker->attack();

	AM* AMattcker;
	if (AM_List.RandomPeek(AMattcker))
		AMattcker->attack();


	AD* AD_Pair1;
	AD* AD_Pair2;
	
	if (AD_List.peek(AD_Pair1) && AD_List.peekBack(AD_Pair2) && AD_List.getLength() != 1)
	{
		AD_Pair1->attack();
	}
}

int alienArmy::GetLength(string s) const
{
	if (s == "AS")
		return AS_List.getLength();
	else if (s == "AM")
		return AM_List.getLength();
	else if(s == "AD")
		return AD_List.getLength();
	else if (s == "ttl")
		return AS_List.getLength() + AD_List.getLength() + AM_List.getLength();
	return -1;
}
