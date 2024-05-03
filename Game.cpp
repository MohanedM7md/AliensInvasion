#include "Game.h"


//using namespace std;

Game::Game():pOut(new Output), EarthArmies(this), UnitGen(this), AlienArmies(this),Timesteps(1)
{
	parameters param = LoadParameters();
	UnitGen.setParameters(param);
}



void Game::DisplayKilledList()
{
	
	pOut->PrintOut("Killed " + std::to_string(killed_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut(" Unit", LIGHT_CYAN);
	pOut->PrintOut("[", LIGHT_BLUE);
	killed_List.Print();
	pOut->PrintOut("]\n", LIGHT_BLUE);
}


Output* Game::getOutputPtr() const
{
	return this->pOut;
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
	std::string menueItems[] = { "Interactive", "Silent", "Back"};
	switch (pOut->ScreenMenu(menueItems, 3)) {
	case 0: GameMode = true;  return INERACT; break;
	case 1: GameMode = false; return SILENT; break;
	}
	return BACK;
}

void Game::startGameInteractive()
{

	//// GUI related functions /////
	pOut->ClearScreen();
	pOut->setFont(20);
	pOut->screenRefesher();


	while(true) {
		if (GetAsyncKeyState(VK_ESCAPE)) {
			break; // Exit the loop and end the program
		}
		UnitGen.GenrateArmy(Timesteps++);
			pOut->PrintOut("\t\t\t\t\t   Current Timestep:   " + std::to_string(Timesteps) + "\n\n", RED);

			this->EarthArmies.printEarth();//Print Earthians' Armies
			this->AlienArmies.printAlien(); //Print Alines' Armies

			pOut->PrintOut("==================================   ", AQUA);
			pOut->PrintOut("Units fighting at current step", ORANGE);
			pOut->PrintOut("   ===================================\n\n", AQUA);
			EarthArmies.attackAliens();
			AlienArmies.attackEarthians();

			pOut->PrintOut("\n\n====================================   ", RED);
			pOut->PrintOut("Killed/Destructed Units", ORANGE);
			pOut->PrintOut("   ========================================\n\n", RED);
			DisplayKilledList(); // Killed List printer
			std::cout << "\n\n\n";
			system("pause");
			std::cout << "\n\n\n\n";
		if ((!EarthArmies.GetLength("ttl") || !AlienArmies.GetLength("ttl")) && (Timesteps > 39)) {
			break;
		}
	}

	OutPutFileCreator();
	system("cls");
}

void Game::startGameSilent()
{
	pOut->PrintOut("Silent Mode\n");
	pOut->PrintOut("Simulation Starts...");
	while (true) {
		UnitGen.GenrateArmy(Timesteps++);
		EarthArmies.attackAliens();
		AlienArmies.attackEarthians();
		if ((!EarthArmies.GetLength("ttl") || !AlienArmies.GetLength("ttl")) && (Timesteps > 39))
			break;
	}

	pOut->PrintOut("Silent ends, Output file is created");
	system("pause");
	OutPutFileCreator();
	system("cls");
}

parameters Game::LoadParameters()
{
	parameters param;

	std::fstream inputFile; // create File object
	inputFile.open(("InputPrameters.txt"), std::ios::in); // open File

	if (inputFile.is_open()) {//checks if the file opened well

		//inputFile.ignore((std::numeric_limits<std::streamsize>::max)(), ':');//the same as before to get the value of N
		inputFile >> param.N; // get value of N
		//inputFile.ignore((std::numeric_limits<std::streamsize>::max)(), ':');//the same as before to get the value of ,%ES,ET,....
		inputFile >> param.ES >> param.ET >> param.EG;
		inputFile >> param.AS >> param.AM >> param.AD;
		//inputFile.ignore((std::numeric_limits<std::streamsize>::max)(), ':');//it is ignor till the : of first line of proab.
		inputFile >> param.prob; // get value of probablity
		
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
		inputFile >> param.ApwRangees[1];
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

void Game::OutPutFileCreator()
{
	std::fstream OutputFile; // create File object
	int ttlDestructedALiens = AS::getKilled() + AM::getKilled() + AD::getKilled();
	int ttlDestructedEarth = EG::getKilled() + ES::getKilled() + ET::getKilled();
	
	int ttlALiensUnit = AS::getTotal() + AM::getTotal() + AD::getTotal();
	int ttlEarthUnit = EG::getTotal() + ES::getTotal() + ET::getTotal();

	OutputFile.open(("OutputFile.txt"), std::ios::out); // open File in output mode

	if (OutputFile.is_open()) {
		Unit* u;
		OutputFile << "Td" << '\t' << "ID" << '\t' <<"Tj"<< '\t' <<"DF" << '\t' << "Dd" << '\t' << "Db" <<"\tTj" << "\n\n\n";
		while (killed_List.dequeue(u)) {
			int td = u->GetTd(), tj = u->GetTj(), ta = u->GetTa();
			OutputFile << td << '\t' << u->GetID() << '\t' << tj << '\t' << (ta - tj) << '\t' << (td - ta) << '\t' << (td - tj)<<'\t'<<ta << "\n\n";
		}

		if (!EarthArmies.GetLength("ttl")) 
			OutputFile << "\n\n\n\nAliens Won the Battle\n\n";
		else if (!AlienArmies.GetLength("ttl"))
			OutputFile << "\n\n\n\nEarth Won the Battle\n\n";
		else
			OutputFile << "\n\n\n\nDraw\n\n";
		OutputFile << "\n\n============================== Earth Statistcs  ========================\n\n"
			<< "ES #: "<<ES::getTotal()<<std::endl
			<< "Percentage of destructe: " << ((double)ES::getKilled() / (double)ES::getTotal()) * 100 << "%" <<std::endl
			<< "ET #: "<<ET::getTotal()<<std::endl
			<< "Percentage of destructe: " << ((double)ET::getKilled() / (double)ET::getTotal()) * 100 << "%" << std::endl
			<< "EG #: " << EG::getTotal() << std::endl
			<< "Percentage of destructe: " << ((double)EG::getKilled() / (double)EG::getTotal()) * 100 << "%" << std::endl
			<< "Percenta e of total destructed units: " << ((double)ttlDestructedEarth / (double)ttlEarthUnit) * 100 << "%"<<std::endl;

		OutputFile << "\n\n============================== Aliens Statistcs  ========================\n\n"
			<< "AS #: " << AS::getTotal() << std::endl
			<< "Percentage of destructe: " << ((double)AS::getKilled() / (double)AS::getTotal()) * 100 << "%" << std::endl
			<< "AM #: " << AM::getTotal() << std::endl
			<< "Percentage of destructe: " << ((double)AM::getKilled() / (double)AM::getTotal()) * 100 << "%" << std::endl
			<< "AD #: " << AD::getTotal() << std::endl
			<< "Percentage of destructe: " << ((double)AD::getKilled() / (double)AD::getTotal()) * 100 << "%" << std::endl
			<< "Percenta e of total destructed units: " << (float(ttlDestructedALiens) / float(ttlALiensUnit)) * 100 << "%" << std::endl;



		OutputFile.close();
	}
}

void Game::addEUnits(Unit* add)
{
	EarthArmies.addUnit(add);
}

void Game::addAUnits(Unit* add)
{
	AlienArmies.addUnit(add);
}

earthArmy* Game::GetEarthArmy()
{
	return &EarthArmies;
}

alienArmy* Game::GetAlienArmy()
{
	return &AlienArmies;
}

bool Game::addToKillList(Unit* unit)
{
	return killed_List.enqueue(unit);
}

bool Game::getGameMode() const
{
	return GameMode;
}


int Game::GetTimeStep() const
{
	return Timesteps;
}

Game::~Game()
{
	delete pOut;
}

