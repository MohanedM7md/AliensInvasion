#pragma once
#include "../Unit Armies/Unit.h"
#include "../Unit Armies/ES.h"
#include "../Armies' Lists/LinkedQueue.h"
//#include "../Game.h"


//int id, int tj, double health, float power, int attackCap,
//std::string type, Game* Gptr
class earthArmy {
	Output* pOut;
	LinkedQueue <ES> EsList;
	
public:
	
	
	earthArmy();
	void printEarth();
};

inline earthArmy::earthArmy()
{
	ES Man(12, 2, 500, 40, 3, "ES");
	EsList.enqueue(Man);
}

inline void earthArmy::printEarth()
{
	EsList.Print();
}
