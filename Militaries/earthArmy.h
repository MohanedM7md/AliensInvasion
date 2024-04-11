#ifndef _EARTH_ARMY
#define _EARTH_ARMY


#include "../Unit Armies/ES.h"
#include "../Unit Armies/ET.h"
#include "../Unit Armies/EG.h"
#include "../Armies' Lists/LinkedQueue.h"
#include "../Armies' Lists/LinkedStack.h"
#include "../Armies' Lists/priQueue.h"

class Game;
class Output;

class earthArmy {
	Output* pOut;
	Game* gPtr;
	LinkedQueue<ES*> ES_List;
	LinkedStack<ET*> ET_List;
	priQueue<EG*> EG_List;

public:
	
	
	earthArmy(Game* gPtr = nullptr);
	void printEarth();
	bool addUnit(Unit*);

};

#endif