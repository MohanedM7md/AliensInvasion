#ifndef GAME_
#define GAME_
#include <fstream>
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


	priQueue<ES*> UML1;
	LinkedQueue<ET*> UML2;

	int Timesteps;
	
	void DisplayKilledList();
	void DisplayUML1List();
	void DisplayUML2List();
	int TresholdPercentage;
	bool help;
	bool GameMode;

public:
	Game();

	Output* getOutputPtr() const;
	/*void loadingScreen();*/
	MENU startMenue();
	MENU modeMenue();
	void startGameInteractive();
	void startGameSilent();

	parameters LoadParameters();
	void OutPutFileCreator();

	void addEUnits(Unit*);
	void addAUnits(Unit*);

	earthArmy* GetEarthArmy();
	alienArmy* GetAlienArmy();

	bool addToKillList(Unit* unit);
	bool getGameMode() const;
	
	int UmlPriEquation(Unit* u) const;

	int GetTimeStep() const;

	bool getHelp() const;
	priQueue<ES*>* getUML1();
	LinkedQueue<ET*>* getUML2();
	~Game();
};
#endif 

