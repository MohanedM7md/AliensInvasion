#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment (lib,"winmm.lib")

#include "../DEFS.h"
//==================================Define Key Buttons Values=============================//
#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER_KEY 13
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


class Output {
private:
    
    HANDLE ConsoleHandler;
    CONSOLE_SCREEN_BUFFER_INFO screen;
   
public:
	Output();
    void LoadingScreen();

    template<class T>
    void PrintOut(T text, COLOR color = WHITE);
    int ScreenMenu(std::string MenuItems[], int MinueSize);
    void ClearScreen();
    void setFont(short size, const std::wstring& fontType = L"Terminal");
    HANDLE getConsoleHandler ()const;
    //=============== Armies Info Outputs ====================//
    void ES_Print();
    void ET_Print();
    void EG_Print();

};
