#include "Game.h"



int main() {
	
	//game.loadingScreen();
	MENU Choice;
	
	do{
		Game game;
		Choice = game.startMenue();
		if (Choice == START) {
			MENU mode = game.modeMenue();
			switch (mode) {
			case INERACT: game.startGame(); break;
			case SILENT: /*SILTEN*/break;
			case TEST: game.testcode(); break;
			}
		}
		else if (Choice == TEAM_INFO) {
			//tem info
		}
		system("cls");
	} while (Choice != EXIT);

}