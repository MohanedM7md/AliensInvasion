#ifndef GAME_
#define GAME_
#include <fstream>
#include <sstream>
#include "GUI/Output.h"
#include "Militaries/earthArmy.h"
#include "Armies Genrator/randGen.h"


class Game
{
	Output* pOut;
	earthArmy EarthArmies;
	randGen UnitGen;

public:
	Game();

	Output* getOutputPtr() const;
	void loadingScreen();
	MENU startMenue();
	MENU modeMenue();
	void startGame();
	parameters LoadParameters();
	void addEUnits(Unit*);
	void addAUnits();
	~Game();
};
#endif 

