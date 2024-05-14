
 
#include"../Unit Armies/Unit.h"
#include "../Unit Armies/SU.h"
#include "../Armies' Lists/LinkedQueue.h"

class Game;
class Output;

class alliedArmy
{
	Output* pOut;
	Game* gPtr;
	LinkedQueue<SU*> SU_List;


	public:

alliedArmy(Game* gPtr = nullptr);
void printAllied();
bool addUnit(Unit*);
bool SU_Getter(SU*&su);
bool IfListIsEmpyt(string s) const;
void attackAliens();
int GetLength(string s) const;

};

