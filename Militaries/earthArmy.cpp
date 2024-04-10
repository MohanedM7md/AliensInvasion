#include "earthArmy.h"
#include "../Game.h"

earthArmy::earthArmy(Game* gPtr) :gPtr(gPtr)
{
	pOut = gPtr->getOutputPtr();
	ES k(13, 44, 55, 66, 32, "asa");
	ES_List.enqueue(k);
	ES_List.enqueue(k);
	ES_List.enqueue(k);
	ET m(13, 44, 55, 66, 32, "asa");
	ET_List.push(m);
	ET_List.push(m);
	ET_List.push(m);


}

void earthArmy::printEarth()
{
	pOut = gPtr->getOutputPtr();
	pOut->PrintOut("========================================   ", AQUA);
	pOut->PrintOut("Earth Army ALive Units", ORANGE);
	pOut->PrintOut("   =====================================\n", AQUA);

	//=============== print ES Information ========================/
	pOut->ES_Print();
	pOut->PrintOut("ES", LIGHT_CYAN);
	pOut->PrintOut('[', LIGHT_GREEN);
	ES_List.Print();
	pOut->PrintOut("]\n\n", LIGHT_GREEN);

	//=============== print ET Information ========================/
	pOut->ET_Print();
	pOut->PrintOut("ET", LIGHT_CYAN);
	pOut->PrintOut('[', LIGHT_GREEN);
	ES_List.Print();
	pOut->PrintOut("]\n\n", LIGHT_GREEN);
}