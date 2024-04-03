//#include "Game.h"
//#include "GUI/Output.h"
#include "Militaries/earthArmy.h"


int main() {
	Game game;
	//Output* out;
	MENU UserChoice = game.startMenue();
	while (UserChoice != EXIT) {
		switch (UserChoice) {

		case START: UserChoice = game.modeMenue();
			switch (UserChoice) {
				case INERACT: /*play ineract*/break;
				case SILENT: /*play Silent*/break;
				default: break;
			}
			break;

		case TEAM_INFO:/*Shows team Information*/break;

		default: break;
		}
		UserChoice = game.startMenue();
	}
}