#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <string>
#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER_KEY 13

class Output {
private:
    CONSOLE_FONT_INFOEX cfi;
    HANDLE console_color;
    std::string MenuItems[3];
    void fullscreen();
    void LoadingScreen();
    
public:
	Output();
    template<class T>
    void PrintOut(T text, char color = '7');
};
