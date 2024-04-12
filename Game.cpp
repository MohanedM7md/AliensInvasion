#include "Game.h"


//using namespace std;

Game::Game():EarthArmies(this),UnitGen(this),AlienArmies(this)
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
	Sleep(1000);
	keybd_event(VK_MENU, 0x38, 0, 0); // Alt button down
	keybd_event(VK_RETURN, 0x1c, 0, 0); // Enter button Down
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); // Alt up
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); //Enter up
	Sleep(800);// Sleep for a short time to avoid potential issues with window resizing
	Sleep(1000);
	keybd_event(VK_MENU, 0x38, 0, 0); // Alt button down
	keybd_event(VK_RETURN, 0x1c, 0, 0); // Enter button Down
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); // Alt up
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); //Enter up
	Sleep(1000);// 
	for (int i = 1; i != 50; i++) {

		pOut->PrintOut("\t\t\t\t\t   Current Timestep:   " + std::to_string(i) + "\n\n", RED);
		UnitGen.GenrateArmy();
		EarthArmies.printEarth();
		AlienArmies.printAlien();
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
	Sleep(1000);
	keybd_event(VK_MENU, 0x38, 0, 0); // Alt button down
	keybd_event(VK_RETURN, 0x1c, 0, 0); // Enter button Down
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); // Alt up
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); //Enter up
	Sleep(800);// Sleep for a short time to avoid potential issues with window resizing
	Sleep(1000);
	keybd_event(VK_MENU, 0x38, 0, 0); // Alt button down
	keybd_event(VK_RETURN, 0x1c, 0, 0); // Enter button Down
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); // Alt up
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); //Enter up
	Sleep(1000);// 
	for (int i = 1; i != 50; i++) {
		pOut->PrintOut("\t\t\t\t\t   Current Timestep:   " + std::to_string(i) + "\n\n", RED);
		UnitGen.GenrateArmy();
		// Generate a number X from 1 to 100
		int X = UnitGen.RandmonNumGent();

		if (X >= 1 && X <= 9)

		{ // If X is between 1 and 9
			// Select an ES unit from its list and insert it again
			ES* selectedES = nullptr;
			if (EarthArmies.ES_List.dequeue(selectedES))
			{
				EarthArmies.ES_List.enqueue(selectedES);
			}
		}





		else if (X >= 11 && X <= 19)

		{
			// Select an ES unit from its list and insert it again
			ET* selectedET = nullptr;
			if (EarthArmies.ET_List.pop(selectedET))
			{
				killed_List.enqueue(selectedET);
			}

		}





		else if (X >= 21 && X <= 29)

		{
			EG* selectedEG = nullptr;
			int pri = NULL;
			if (EarthArmies.EG_List.dequeue(selectedEG, pri))
			{
				selectedEG->SetHealth(selectedEG->GetHealth() / 2);

				EarthArmies.EG_List.enqueue(selectedEG, pri);



			}
		}

		else if (X >= 31 && X <= 39)
		{
			AS* selectedAS = nullptr;
			for (int i = 0; i < 5; i++)
			{

				if (AlienArmies.AS_List.dequeue(selectedAS))
				{
					selectedAS->SetHealth(selectedAS->GetHealth()-1);

					Temp_List.enqueue(selectedAS);
					AlienArmies.AS_List.enqueue(selectedAS);
				}



			}

        }

		else if (X >= 41 && X <= 49)

		{
			AM* selectedAM = nullptr;
			for (int i = 0; i < 5; i++) 
			{

				if (AlienArmies.AM_List.remove(selectedAM))
				{
					AlienArmies.AM_List.add(selectedAM);

				}

			}

		}

		//else if  (X >= 41 && X <= 49)
		//{
		//	AD* selectedAD = nullptr;
		//	for (int i = 0; i < 5; i++)
		//	{

		//		if (AlienArmies.AD_List.dequeue()
		//		{
		//			

		//		}

		//	}

		//}

		//print all info
	}
}



Game::~Game()
{
	delete pOut;
}

