#include "randGen.h"
#include "../Game.h"


using namespace std;

randGen::randGen(Game* Gptr) :ErthIDs(1), AliensthIDs(2000), Gptr(Gptr), SUIDS(4000)
{
}

void randGen::setParameters(parameters & param)
{
	if (param.N < 0 || param.prob < 0|| param.ES < 0 
		|| param.ET < 0 || param.EG < 0 || param.AS < 0
		|| param.AM < 0 || param.AD < 0 || param.EattkCapRangees[1] < 0
		||  param.EattkCapRangees[0] < 0 ||param.EhtlyRangees[1] < 0
		|| param.EhtlyRangees[0] < 0 || param.EpwRangees[1] < 0
		||  param.EpwRangees[0] < 0)
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




void randGen::GenrateArmy(int Tj)
{
	int RandA = RandmonNumGent();
	//Todo You have to follow tha same pattern for other Unit calss
	if (RandA  < param.prob)
		for (int i = 0; i < param.N; i++) {
			int randB = RandmonNumGent(); //genrate random number range 1-100
			int hlth, pwr, cap;//intialize input prameter


			/*======================== Earth Army ========================*/
			hlth = RandmonRangeNum(param.EhtlyRangees);
			pwr = RandmonRangeNum(param.EpwRangees);
			cap = RandmonRangeNum(param.EattkCapRangees);
			if (randB <= param.ES) {
				Gptr->addEUnits(new ES(ErthIDs++, Tj, hlth, pwr, cap, "ES", Gptr));
			}

			else if (randB <= param.ES + param.ET) {
				Gptr->addEUnits(new ET(ErthIDs++, Tj, hlth, pwr, cap, "ET", Gptr));
			}
			else if(randB <= param.ES + param.ET + param.EG)
			{
				Gptr->addEUnits(new EG(ErthIDs++, Tj, hlth, pwr, cap, "EG", Gptr));
			}
			else {
				Gptr->addEUnits(new HU(ErthIDs++, Tj, hlth, pwr, cap, "EG", Gptr));
			}

			

		}
	/*=================================================SU ARMY==========================================*/
	if (Gptr->getHelp()) {
		int RandSU = RandmonNumGent();
		if (RandSU < param.PercOfSU) {
			int hlth = RandmonRangeNum(param.SUhtlyRangees);
			int pwr = RandmonRangeNum(param.SUpwRangees);
			int cap = RandmonRangeNum(param.SUattkCapRangees);
			Gptr->addEUnits(new SU(SUIDS++, Tj, hlth, pwr, cap, "SU", Gptr));
		}
	}
	/*======================== Alien Army ========================*/
	RandA = RandmonNumGent(); //genrate random number range 1-100
	if (RandA < param.prob)
		for (int i = 0; i < param.N; i++) {
			int randB = RandmonNumGent(); //genrate random number range 1-100
			int hlth, pwr, cap;//intialize input prameter
			hlth = RandmonRangeNum(param.AhtlyRangees);
			pwr = RandmonRangeNum(param.ApwRangees);
			cap = RandmonRangeNum(param.AattkCapRangees);
			if (randB <= param.AS) {
				
				Gptr->addAUnits(new AS(AliensthIDs++, Tj, hlth, pwr, cap, "AS", Gptr));
			}

			else if (randB <= param.AS + param.AM) {

				Gptr->addAUnits(new AM(AliensthIDs++, Tj, hlth, pwr, cap, "AM", Gptr));
			}
			else
			{

				Gptr->addAUnits(new AD(AliensthIDs++, Tj, hlth, pwr, cap, "AD", Gptr));
			}
		}
}


