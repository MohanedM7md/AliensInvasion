#include "Game.h"



int main() {
	
	//game.loadingScreen();
	MENU Choice;
	Output::FullScreenSetter();
	do{
		Game game;
		Choice = game.startMenue();
		if (Choice == START) {
			MENU mode = game.modeMenue();
			switch (mode) {
			case INERACT: game.startGameInteractive(); break;
			case SILENT: game.startGameSilent();  break;
			
			}
		}
		else if (Choice == TEAM_INFO) {
			//tem info
		}
		system("cls");
	} while (Choice != EXIT);

}