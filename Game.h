#ifndef GAME_
#define GAME_
#include "GUI/Output.h"
#include "Militaries/earthArmy.h"


class Game
{
	Output* pOut;
	earthArmy EarthArmies;
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

