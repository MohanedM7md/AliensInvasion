#include "Game.h"

Game::Game():EarthArmies(this)
{
	pOut = new Output;//remember to de-allocate this please"
	
}

Output* Game::getOutputPtr() const
{
	return this->pOut;
}

void Game::loadingScreen()
{
	pOut->LoadingScreen();
}

MENU Game::startMenue()
{
	std::string menueItems[] = {"Start","Teams' Information","Exit"};
	switch (pOut->ScreenMenu(menueItems, 3)) {
	case 0:return START; break;
	case 1:return TEAM_INFO; break;
	}
	return EXIT;
}

MENU Game::modeMenue()
{
	std::string menueItems[] = { "Interactive","Silent","Back" };
	switch (pOut->ScreenMenu(menueItems, 3)) {
	case 0:return INERACT; break;
	case 1:return SILENT; break;
	}
	return BACK;
}

void Game::startGame()
{
	pOut->ClearScreen();
	pOut->setFont(20);
	EarthArmies.printEarth();
	system("pause");
}

Game::~Game()
{
	delete pOut;
}

