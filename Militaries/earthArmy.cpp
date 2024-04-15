#include "earthArmy.h"
#include "../Game.h"



earthArmy::earthArmy(Game* gPtr) :gPtr(gPtr)
{
	pOut = gPtr->getOutputPtr();
}

void earthArmy::printEarth()
{
	pOut = gPtr->getOutputPtr();
	pOut->PrintOut("========================================   ", AQUA);
	pOut->PrintOut("Earth Army ALive Units", ORANGE);
	pOut->PrintOut("   =====================================\n", AQUA);

	//=============== print ES Information ========================/
	pOut->ES_Print();
	ES_printer();

	//=============== print ET Information ========================/
	pOut->ET_Print();
	ET_printer();

	//=============== print EG Information ========================/
	pOut->EG_Print();
	EG_printer();
}

bool earthArmy::addUnit(Unit* unit)
{
	if (dynamic_cast<ES*>(unit)) 
		return ES_List.enqueue((dynamic_cast<ES*>(unit)));

	else if(dynamic_cast<ET*>(unit))
		return ET_List.push((dynamic_cast<ET*>(unit)));

	else if (dynamic_cast<EG*>(unit)) {
		EG_List.enqueue(dynamic_cast<EG*>(unit), dynamic_cast<EG*>(unit)->GetPri());
		return true;
	}

	return false;
}



void earthArmy::ES_printer()
{
	
	pOut->PrintOut(std::to_string(ES_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut("  ES", LIGHT_CYAN);
	pOut->PrintOut('[', LIGHT_GREEN);
	ES_List.Print();
	pOut->PrintOut("]\n\n", LIGHT_GREEN);
}
void earthArmy::ET_printer()
{
	
	pOut->PrintOut(std::to_string(ET_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut("  ET", LIGHT_CYAN);
	pOut->PrintOut('[', LIGHT_GREEN);
	ET_List.print();
	pOut->PrintOut("]\n\n", LIGHT_GREEN);
}
void earthArmy::EG_printer()
{
	
	pOut->PrintOut(std::to_string(EG_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut("  EG", LIGHT_CYAN);
	pOut->PrintOut('[', LIGHT_GREEN);
	EG_List.Print();
	pOut->PrintOut("]\n\n", LIGHT_GREEN);
}

bool earthArmy::ES_Getter(ES*& es)
{
	return ES_List.dequeue(es);
}

bool earthArmy::ET_Getter(ET*& et)
{
	return ET_List.pop(et);
}

bool earthArmy::EG_Getter(EG*& eg,int& pri)
{
	return EG_List.dequeue(eg, pri);
}
