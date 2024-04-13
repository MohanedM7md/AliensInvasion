#ifndef GAME_
#define GAME_
#include <fstream>
#include <sstream>
#include "GUI/Output.h"
#include "Militaries/earthArmy.h"
#include "Militaries/alienArmy.h"
#include "Armies Genrator/randGen.h"


class Game
{
	Output* pOut;
	earthArmy EarthArmies;
	alienArmy AlienArmies;
	randGen UnitGen;
	LinkedQueue<Unit*> killed_List;
	LinkedQueue<Unit*> Temp_List;
	void DisplayLists();

public:
	Game();

	Output* getOutputPtr() const;
	void loadingScreen();
	MENU startMenue();
	MENU modeMenue();
	void startGame();
	parameters LoadParameters();
	void addEUnits(Unit*);
	void addAUnits(Unit*);
	void testcode();
	earthArmy* GetEarthArmy();
	alienArmy* GetAlienArmy();
	~Game();
};
#endif 

