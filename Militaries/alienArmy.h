#ifndef _ALIENARMY
#define _ALIENARMY

#include "../Unit Armies/AD.h"
#include "../Unit Armies/AM.h"
#include "../Unit Armies/AS.h"
#include "../Armies' Lists/LinkedQueue.h"
#include "../Armies' Lists/priQueue.h"
#include "../Armies' Lists/Array.h"



class Game;
class Output;

class alienArmy {
	Output* pOut;
	Game* gPtr;
public:


	LinkedQueue<AS*> AS_List;
	Array <AM*> AM_List;
	LinkedQueue<AD*> AD_List;

	alienArmy(Game* gPtr = nullptr);
	void printAlien();
	bool addUnit(Unit*);

};


#endif