#include "Game.h"


//using namespace std;

void Game::DisplayLists()
{
	this->EarthArmies.printEarth();
	this->AlienArmies.printAlien();
	pOut->PrintOut("=======================================   ", LIGHT_RED);
	pOut->PrintOut("Killed/Destructed Units", ORANGE);
	pOut->PrintOut("   =====================================\n", LIGHT_RED);

	DisplayKilledList();
	pOut->PrintOut("=======================================   ", LIGHT_RED);
	pOut->PrintOut("TEMP LIST", ORANGE);
	pOut->PrintOut("   =====================================\n", LIGHT_RED);
	DisplayTemp();
	
}

void Game::DisplayKilledList()
{
	
	pOut->PrintOut("Killed " + std::to_string(killed_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut(" Unit", LIGHT_CYAN);
	pOut->PrintOut("[", LIGHT_BLUE);
	killed_List.Print();
	pOut->PrintOut("]\n", LIGHT_BLUE);
}

void Game::DisplayTemp()
{
	
	pOut->PrintOut("Temp " + std::to_string(killed_List.getLength()), LIGHT_YELLOW);
	pOut->PrintOut(" Unit", LIGHT_CYAN);
	pOut->PrintOut("[", LIGHT_BLUE);
	Temp_List.Print();
	pOut->PrintOut("]\n", LIGHT_BLUE);
}

Game::Game():pOut(new Output), EarthArmies(this), UnitGen(this), AlienArmies(this)
{
	parameters param = LoadParameters();
	UnitGen.setParameters(param);
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
	std::string menueItems[] = { "Interactive","Silent","Test","Back"};
	switch (pOut->ScreenMenu(menueItems, 4)) {
	case 0:return INERACT; break;
	case 1:return SILENT; break;
	case 2:return TEST; break;
	}
	return BACK;
}

void Game::startGame()
{

	
	pOut->ClearScreen();
	pOut->setFont(20);
	pOut->screenRefesher();
	for (int i = 1; i != 50; i++) {
		if (GetAsyncKeyState(VK_ESCAPE)) {
			break; // Exit the loop and end the program
		}
		this->UnitGen.GenrateArmy();
		pOut->PrintOut("\t\t\t\t\t   Current Timestep:   " + std::to_string(i) + "\n\n", RED);
		DisplayLists();
		system("pause");
		std::cout << "\n\n\n\n";
	}
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

void Game::testcode() 
{
	pOut->ClearScreen();
	pOut->setFont(20);
	pOut->screenRefesher();

	for (int i = 1; i <= 50; i++) {
		pOut->PrintOut("\t\t\t\t\t   Current Timestep:   " + std::to_string(i) + "\n\n", RED);
		UnitGen.GenrateArmy();
		// Generate a number X from 1 to 100
		int X = UnitGen.RandmonNumGent();
		pOut->PrintOut("\t\tthe value of X: " + std::to_string(X) + " \n\n\n", GRAY);
		if (X >= 1 && X <= 9)

		{ // If X is between 1 and 9
			// Select an ES unit from its list and insert it again
			ES* selectedES = nullptr;
			pOut->PrintOut("The ES before remove: \n");
			EarthArmies.ES_printer();
			std::cout << '\n';
			if (EarthArmies.ES_List.dequeue(selectedES))
			{
				pOut->PrintOut("The ES After remove :\n");
				EarthArmies.ES_printer();
				pOut->PrintOut("The ES After return: \n");
				EarthArmies.ES_List.enqueue(selectedES);
				EarthArmies.ES_printer();
				std::cout << '\n';
			}
		}else if (X >= 11 && X <= 19)
		{// Select an ES unit from its list and insert it again
			ET* selectedET = nullptr;
			EarthArmies.ET_printer();
			if (EarthArmies.ET_List.pop(selectedET))
			{
				EarthArmies.ET_printer();
				killed_List.enqueue(selectedET);
				DisplayKilledList();
			}

		}
		else if (X >= 21 && X <= 29)
		{
			EG* selectedEG = nullptr;
			int pri = NULL;
			pOut->PrintOut("The ET before remove:\n");
			EarthArmies.EG_printer();
			if (EarthArmies.EG_List.dequeue(selectedEG, pri))
			{
				pOut->PrintOut("The ET after remove: \n");
				EarthArmies.EG_printer();
				std::cout << "\nthe Pickied one ID:" << selectedEG->GetID() << "\n Health: " << selectedEG->GetHealth()<<std::endl;
				selectedEG->SetHealth(selectedEG->GetHealth() * 0.5);
				std::cout << "\nthe Pickied one ID:" << selectedEG->GetID() << "\n Health After Decrement: " << selectedEG->GetHealth()<<std::endl;

				EarthArmies.EG_List.enqueue(selectedEG, pri);
				pOut->PrintOut("The ET after return: \n");
				EarthArmies.EG_printer();
			}
		}
		else if (X >= 31 && X <= 39)
		{
			AS* selectedAS = nullptr;

			AlienArmies.AS_printer();
			for (int i = 0; i < 5; i++)
			{
				if (AlienArmies.AS_List.dequeue(selectedAS))
				{
					std::cout <<i+1<<" : " << "\nthe Pickied one ID:" << selectedAS->GetID() << "\n Health: " << selectedAS->GetHealth() << std::endl;
					selectedAS->SetHealth(selectedAS->GetHealth() * 0.5);
					std::cout << "====\nthe Pickied one ID:" << selectedAS->GetID() << "\n Health After Decrement: " << selectedAS->GetHealth() << "\n\n";
					Temp_List.enqueue(selectedAS);

				}
			}
			this->DisplayTemp();
			AlienArmies.AS_printer();
			Unit* getFromTemp = nullptr;
			for (int i = 0; i < 5; i++)
			{
				if (Temp_List.dequeue(getFromTemp))
				{
					AlienArmies.AS_List.enqueue(dynamic_cast<AS*>(getFromTemp));

				}
			}
			this->DisplayTemp();
			AlienArmies.AS_printer();

        }

		else if (X >= 41 && X <= 49)

		{
			AM* selectedAM[5];
			for (int i = 0; i < 5; i++)
				selectedAM[i] = nullptr;
			AlienArmies.AM_printer();

			for (int i = 0; i < 5; i++)
				AlienArmies.AM_List.remove(selectedAM[i]);
			AlienArmies.AM_printer();
			for (int i = 0; i < 5; i++)
				if(selectedAM[i])
					AlienArmies.AM_List.add(selectedAM[i]);
			AlienArmies.AM_printer();


		}
		else if (X > 49 && X <= 60) {
			AD* selectedAD[6];
			for (int i = 0; i < 6; i++)
				selectedAD[i] = nullptr;
			AlienArmies.AD_printer();
			for (int i = 0; i < 6; i++) {
				if(i%2)
				AlienArmies.AD_List.dequeueBack(selectedAD[i]);
				else
				AlienArmies.AD_List.dequeueFront(selectedAD[i]);
				AlienArmies.AD_printer();
			}
			for (int i = 0; i < 6; i++)
				if (selectedAD[i])
					killed_List.enqueue(selectedAD[i]);
			
			this->DisplayKilledList();
			AlienArmies.AD_printer();
		}
	}
	system("pause");
}



Game::~Game()
{
	delete pOut;
}

