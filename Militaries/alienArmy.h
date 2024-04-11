#ifndef _ALIENARMY
#define _ALIENARMY

#include "../Unit Armies/AD.h"
#include "../Unit Armies/AM.h"
#include "../Unit Armies/AS.h"
#include "../Armies' Lists/LinkedQueue.h"
#include "../Armies' Lists/LinkedStack.h"
#include "../Armies' Lists/priQueue.h"
#define MAX 100


class Game;
class Output;

class alienArmy {
	Output* pOut;
	Game* gPtr;
	LinkedQueue<AS*> AS_List;
	AM* AM_list[MAX];
	int AM_count = 0;
	LinkedQueue<AD*> AD_List;

public:


	alienArmy(Game* gPtr = nullptr);
	void printAlien();
	bool addUnit(Unit*);

};


#endif