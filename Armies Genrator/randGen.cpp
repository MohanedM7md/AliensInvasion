#include "randGen.h"
#include "../Unit Armies/ES.h"
#include "../Unit Armies/ET.h"
using namespace std;

randGen::randGen():ErthIDs(1),AliensthIDs(2000)
{}


short randGen::RandmonNumGent() {
	srand(time(NULL));//Create random number
	return rand() % 100 +1;// set its range between 1 to 100
	
}

short randGen::RandmonRangeNum(int min, int max)
{
	srand(time(NULL));
	int diffBetw = max - min; //to get the range of numbers between the min and max
	int randNum = rand() % diffBetw + min; //to genrate the this number between min and max 
	return randNum;
}

void randGen::genrateUnitParam(const string& unit, int& hlth, int& pwr, int& cap)
{
	fstream inputFile;

	inputFile.open(("InputPrameters.yml"), ios::in);//open the file

	string line;
	if(inputFile.is_open())
	while (getline(inputFile, line)) {
		size_t pos = line.find(unit);
		if (pos != std::string::npos) { // If "ES" is found in the line
			// Extract the number following "ES"
				int Min, Max;

				getline(inputFile, line, ':');//first getting the health value
				inputFile >> Min >> Max;
				hlth = RandmonRangeNum(Min, Max);
				/////////////////////////////////////
				getline(inputFile, line, ':');//first getting the cap value
				inputFile >> Min >> Max;
				pwr = RandmonRangeNum(Min, Max);
				////////////////////////////////////
				getline(inputFile, line, ':');
				inputFile >> Min >> Max;
				cap = RandmonRangeNum(Min, Max);

				return;
			}
			
		}
	
}




Unit* randGen::GenrateArmy()
{
	
	fstream inputFile;
	inputFile.open(("InputPrameters.yml"), ios::in);//open the file

	if (inputFile.is_open()) {

		for (int i = 0; i < 2; i++) { //skip the first 2 lines
			string dummy;//dummy string to use getline
			getline(inputFile, dummy);
		}

		int randB = RandmonNumGent();//genrate Random number B from 1 to 100 to genrate army unit
		inputFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');//it is ignor till the : of the third line
		int perES, perET, perEG;
		inputFile >> perES >> perET >> perEG;


		string line;
		int hlth, pwr, cap;
		if (randB < perES) {
			genrateUnitParam("#ES", hlth, pwr, cap);
			return new ES(ErthIDs++, 0, hlth, pwr, cap, "ES");
		}

		if (randB <= perES + perET) {
			genrateUnitParam("#ET", hlth, pwr, cap);
			return new ET(ErthIDs++,0, hlth, pwr, cap,"ET");
		}

	}
		return NULL;
}

bool randGen::isProbValid(int& i)
{
	int randA = RandmonNumGent(); //create random number from 1to 100
	fstream inputFile; // create File object
	inputFile.open(("InputPrameters.yml"), ios::in); // open File

	if (inputFile.is_open()) {//checks if the file opened well
		int Value;
		inputFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');//it is ignor till the : of first line
		inputFile >> Value; // get value of probablity
		if (randA <= Value) { // check if Genratedprobablity less than or Equal file Prob.
			inputFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');//the same as before to get the value of N
			inputFile >> Value;
			i = Value;//return the number of itration
			return true; // return true to complete the genration
		}
		inputFile.close();//close
	}
	return false;//false probablity is greater than input File probablity
}
