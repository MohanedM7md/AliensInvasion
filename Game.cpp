#include "Game.h"

Game::Game()
{
	std::string SatartMinue[] = {"Start", "Teams' Information","Exit"};
	POut = new Output;//remember to de-allocate this please
	POut->LoadingScreen();
	switch (POut->ScreenMinue(SatartMinue, 3)) {
	case 1:break;
	case 2:break;
	case 3:this->~Game(); break;
	}
}
Game::~Game()
{
	delete POut;
}
