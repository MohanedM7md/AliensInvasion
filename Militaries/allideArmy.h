#ifndef _ALLIDE_ARMY
#define _ALLIDE_ARMY

#include "../Unit Armies/SU.h"
#include "../Armies' Lists/LinkedQueue.h"


class Game;
class Output;

class allideArmy {
	Output* pOut;
	Game* gPtr;

	LinkedQueue<SU*> SU_List;

	


public:
	
	allideArmy(Game* gPtr = nullptr);
	void printAllide();
	bool addUnit(Unit*);

	/////////// Units Getters ///////////////////////
	bool SU_Getter(SU*&);

	bool IfListIsEmpyt(string s) const;

	///////////// Attack Function //////////////////////
	void attackAliens();
	int GetLength(string s) const;
	void FreeArmy();

};

#endif