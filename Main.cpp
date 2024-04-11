#include "Game.h"



int main() {
	Game game;
	Output* pOut;
	pOut = game.getOutputPtr();
//	game.loadingScreen();
	MENU Choice = game.startMenue();
	while (Choice != EXIT) {
		if (Choice == START) {
			MENU mode = game.modeMenue();
			switch (mode) {
			case INERACT: game.startGame(); break;
			case SILENT: /*SILTEN*/break;
			}
			pOut->ClearScreen();
		}
		else if (Choice == TEAM_INFO) {
			//tem info
		}
		Choice = game.startMenue();
	}
	
}