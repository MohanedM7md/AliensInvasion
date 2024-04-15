#ifndef _ALIENARMY
#define _ALIENARMY

#include "../Unit Armies/AD.h"
#include "../Unit Armies/AM.h"
#include "../Unit Armies/AS.h"
#include "../Armies' Lists/DoubleQueue.h"
#include "../Armies' Lists/LinkedQueue.h"
#include "../Armies' Lists/Array.h"



class Game;
class Output;

class alienArmy {
	Output* pOut;
	Game* gPtr;

	LinkedQueue<AS*> AS_List;
	Array <AM*> AM_List;
	DoubleQueue<AD*> AD_List;
public:


	alienArmy(Game* gPtr = nullptr);
	void printAlien();
	bool addUnit(Unit*);

	//////////// Each Alien Printer   /////////////
	void AS_printer();
	void AM_printer();
	void AD_printer();

	/////////////// Alien Unit remover ///////////////
	bool AS_Getter(AS*&);
	bool AM_Getter(AM*&);
	bool AD_Getter(AD*&, AD*&);

};


#endif