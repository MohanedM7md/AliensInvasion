#include "Output.h"



int Output::ScreenMinue(std::string* MenuItems, int MinueSize)
{
    ClearScreen(); //clearing screen
    int cursor = 0; // set the cursor to the First item
    char key = NULL;
    PlaySound(TEXT("Menu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //PLaying undertale Menue sound
    do {
        std::cout << "\n\n\n";
        for (int i = 0; i < MinueSize; i++) {
            if (i == cursor) {
                std::cout << "\n\n\n\t\t"; 
                PrintOut(char(16), LIGHT_YELLOW); //Right Arrow
                PrintOut("  " + MenuItems[i] + "  ", ORANGE);
                PrintOut(char(17), LIGHT_YELLOW); // Left arrow

            }
            else
            {
                std::cout << "\n\n\n\t\t"; 
                PrintOut("  " + MenuItems[i] + "  ", ORANGE);
                std::cout << "\t\t";
            }
        }
        std::cout << std::endl;
        key = _getch();
        switch (key) {
        case KEY_UP: cursor = (cursor == 0) ? 0 : --cursor; break;
        case KEY_DOWN: cursor = (cursor == MinueSize-1) ? MinueSize-1 : ++cursor; break;
        }
        Sleep(5);
        ClearScreen();
    } while (key != ENTER_KEY);
    return cursor;
}
void Output::ClearScreen()
{
   
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(ConsoleHandler, &screen);
    FillConsoleOutputCharacterA(
        ConsoleHandler, ' ', screen.dwSize.X * screen.dwSize.Y,
        { 0, 0 }, &written);
    SetConsoleCursorPosition(ConsoleHandler, { 0, 0 });
}
void Output::LoadingScreen()
{
    PrintOut( "\n\n\n\n\n\n\t\t\t Loading\n\n\t\t");

    
    for (int i = 0; i < 30; i++) {
        Sleep(70);
        PrintOut(char(219),LIGHT_GREEN);
    }
    std::cout << "\n\n\n\n\n\n\t\t";
    system("pause");
}

Output::Output()
{
    ConsoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);

    //==================SetFont Size and set it to full Screen==================//
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;// Width of each character in the font
    cfi.dwFontSize.Y = 35; // Height
    wcscpy_s(cfi.FaceName, L"Terminal");
    cfi.FontWeight = FW_BOLD;
    SetCurrentConsoleFontEx(ConsoleHandler, FALSE, &cfi);
    Sleep(60);//avoid crashed due to windows delays
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++///

    
}
template<class T>
void Output::PrintOut(T text,COLOR color) //////Print Function to print With Colors//////
{
    
    SetConsoleTextAttribute(ConsoleHandler, color);
    std::cout << text; 
    SetConsoleTextAttribute(ConsoleHandler, WHITE);
}
