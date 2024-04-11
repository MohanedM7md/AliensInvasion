#include "Game.h"


//using namespace std;

Game::Game():EarthArmies(this),UnitGen(this)
{
	pOut = new Output;//remember to de-allocate this please"
	parameters param = LoadParameters();
	UnitGen.setParameters(param);
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
	for (int i = 1; i != 50; i++) {

		pOut->PrintOut("\t\t\t\t\t   Current Timestep:   " + std::to_string(i) + "\n\n", RED);
		UnitGen.GenrateArmy();
		EarthArmies.printEarth();
		system("pause");
		std::cout << "\n\n\n\n";
	}
	
}

parameters Game::LoadParameters()
{
	parameters param;

	std::fstream inputFile; // create File object
	inputFile.open(("InputPrameters.txt"), std::ios::in); // open File

	if (inputFile.is_open()) {//checks if the file opened well

		//inputFile.ignore((std::numeric_limits<std::streamsize>::max)(), ':');//it is ignor till the : of first line of proab.
		inputFile >> param.prob; // get value of probablity
		//inputFile.ignore((std::numeric_limits<std::streamsize>::max)(), ':');//the same as before to get the value of N
		inputFile >> param.N; // get value of N
		//inputFile.ignore((std::numeric_limits<std::streamsize>::max)(), ':');//the same as before to get the value of ,%ES,ET,....
		inputFile >> param.ES >> param.ET >> param.EG;
		
		//inputFile.ignore((std::numeric_limits<std::streamsize>::max)(), ':'); //the same as before to get the value of ranges.
		std::string s;
		///Get Earth rranges
		//power Range
		std::getline(inputFile, s,'-');
		param.EpwRangees[0] = std::stoi(s);
		inputFile >> param.EpwRangees[1];
		//health range
		std::getline(inputFile, s,'-');
		param.EhtlyRangees[0] = std::stoi(s);
		inputFile >> param.EhtlyRangees[1];
		//Earth capacity range
		std::getline(inputFile, s,'-');
		param.EattkCapRangees[0] = std::stoi(s);
		inputFile >> param.EattkCapRangees[1];

		//inputFile.ignore((std::numeric_limits<std::streamsize>::max)(), ':');//it is ignor till the : of the third line
		///Get Aliens rranges
		//power Range
		std::getline(inputFile, s,'-');
		param.ApwRangees[0] = std::stoi(s);
		inputFile >> param.AhtlyRangees[1];
		//health range
		std::getline(inputFile, s,'-');
		param.AhtlyRangees[0] = std::stoi(s);
		inputFile >> param.AhtlyRangees[1];
		//Earth capacity range
		std::getline(inputFile, s,'-');
		param.AattkCapRangees[0] = std::stoi(s);
		inputFile >> param.AattkCapRangees[1];

		inputFile.close();//close
	}
	
	return param;
}

void Game::addEUnits(Unit* add)
{
	EarthArmies.addUnit(add);
}


Game::~Game()
{
	delete pOut;
}

