#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment (lib,"winmm.lib")

#include "../COLORS.h"
//==================================Define Key Buttons Values=============================//
#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER_KEY 13
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


class Output {
private:
    CONSOLE_FONT_INFOEX cfi;
    HANDLE ConsoleHandler;
    
public:
	Output();
    void LoadingScreen();

    template<class T>
    void PrintOut(T text, COLOR color = WHITE);
    int ScreenMinue(std::string* MenuItems, int MinueSize);
    void ClearScreen();
};
