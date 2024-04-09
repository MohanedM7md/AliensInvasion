#include "randGen.h"
#include "../Game.h"

using namespace std;

randGen::randGen(Game* Gptr) :ErthIDs(1), AliensthIDs(2000), Gptr(Gptr)
{
}

void randGen::setParameters(parameters & param)
{
	if (param.N < 0 || param.prob < 0|| param.ES < 0 
		|| param.ET < 0 || param.EG < 0 || param.AS < 0
		|| param.AM < 0 || param.AD < 0)
		return;//will throw exception later
	if ((param.EattkCapRangees[1] - param.EattkCapRangees[0]) < 0 ||
		(param.EhtlyRangees[1] - param.EhtlyRangees[0]) < 0 ||
		(param.EpwRangees[1] - param.EpwRangees[0]) < 0)
		return;//will throw exception later

	this->param = param;
}


short randGen::RandmonNumGent() {
	std::random_device rd;
	std::uniform_int_distribution<int> dist(1, 100);
	return dist(rd);// set its range between 1 to 100

}

short randGen::RandmonRangeNum(int* range) const
{
	std::random_device rd;
	std::uniform_int_distribution<int> dist(range[0], range[1]);
	return dist(rd);// set its range between range[0] to range[1]
}

void randGen::genrateUnitParam(int& hlth, int& pwr, int& cap)
{

	hlth = RandmonRangeNum(param.EhtlyRangees);
	///////////////////////////////////////////////////
	pwr = RandmonRangeNum(param.EpwRangees);
	///////////////////////////////////////////////////
	cap = RandmonRangeNum(param.EattkCapRangees);
}




void randGen::GenrateArmy()
{
	int RandA = RandmonNumGent();
	if (!(RandA < param.prob))
		return;//if the probablity is less End the Function

	for (int i = 0; i < param.N; i++) {
		int randB = RandmonNumGent(); //genrate rando number range 1-100
		int hlth, pwr, cap;//intialize input prameter
		if (randB < param.ES) {
			genrateUnitParam(hlth, pwr, cap);
			Gptr->addEUnits(new ES(ErthIDs++, 0, hlth, pwr, cap, "ES"));
		}

		else if (randB <= param.ES + param.ET) {
			genrateUnitParam(hlth, pwr, cap);
			Gptr->addEUnits(new ET(ErthIDs++, 0, hlth, pwr, cap, "ET"));
		}

	}

}


