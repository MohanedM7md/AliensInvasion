#ifndef GAME_
#define GAME_
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

	~Game();
};
#endif 

