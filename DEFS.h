#pragma once
enum COLOR {
	DUMMY,
	DARK_BLUE,
	DARK_GREEN,
	AQUA,
	RED,
	PURPLE,
	ORANGE,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	PINK,
	LIGHT_YELLOW
};

enum MENU {
	START,
	TEAM_INFO,
	EXIT,


	INERACT = 0,
	SILENT,
	TEST,
	BACK
};

struct parameters {
	int N;
	int prob;
	int ES = 0;
	int ET = 0;
	int EG = 0;
	int AS = 0;
	int AM = 0;
	int AD = 0;
	int EpwRangees[2];
	int EhtlyRangees[2];
	int EattkCapRangees[2];
	int ApwRangees[2];
	int AhtlyRangees[2];
	int AattkCapRangees[2];
};