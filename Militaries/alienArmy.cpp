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

	//=============== print AS Information ========================/

	pOut->Soon_Print();
	pOut->PrintOut(std::to_string(AS_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut("  AS", LIGHT_CYAN);
	pOut->PrintOut('[', LIGHT_GREEN);
	AS_List.Print();
	pOut->PrintOut("]\n\n", LIGHT_GREEN);

	//=============== print AM Information ========================/
	pOut->Soon_Print();
	pOut->PrintOut(std::to_string(AM_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut("  AM", LIGHT_CYAN);
	pOut->PrintOut('[', LIGHT_GREEN);
	AM_List.print();
	pOut->PrintOut("]\n\n", LIGHT_GREEN);

	//=============== print AD Information ========================/
	pOut->Soon_Print();
	pOut->PrintOut(std::to_string(AD_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut("  ET", LIGHT_CYAN);
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
