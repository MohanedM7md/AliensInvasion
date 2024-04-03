#pragma once
#include "GUI/Output.h"



class Game
{
	Output* pOut;
public:
	Game();


	Output* getOutputPtr() const;
	MENU startMenue();
	MENU modeMenue();

	~Game();
};

