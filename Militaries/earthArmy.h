#ifndef _EARTH_ARMY
#define _EARTH_ARMY

class Game;
class Output;
#include "../Unit Armies/ES.h"
#include "../Unit Armies/ET.h"
#include "../Armies' Lists/LinkedQueue.h"
#include "../Armies' Lists/LinkedStack.h"





//class Game;
class earthArmy {
	Output* pOut;
	Game* gPtr;
	LinkedQueue<ES> ES_List;
	LinkedStack<ET> ET_List;
	
	
public:
	
	
	earthArmy(Game* gPtr = nullptr);
	void printEarth();

};

#endif