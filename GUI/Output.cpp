#include "Output.h"

void Output::fullscreen()
{
       keybd_event(VK_MENU, 0x38, 0, 0);
       keybd_event(VK_RETURN, 0x1c, 0, 0);
       keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
       keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
       cfi.cbSize = sizeof(cfi);
       cfi.nFont = 0;
       cfi.dwFontSize.X = 0;                   // Width of each character in the font
       cfi.dwFontSize.Y = 40; // Height
       cfi.FontFamily = FF_DONTCARE;
       cfi.FontWeight = FW_NORMAL;
       cfi.FontWeight = FW_BOLD;// Height
       SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void Output::LoadingScreen()
{
    PrintOut( "\n\n\n\n\t\t\t\t Loading\n\n\t\t");

    
    for (int i = 0; i < 40; i++) {
        Sleep(70);
        PrintOut(char(219),'g');
    }
    std::cout << "\n\n\n\n\n\n\t\t";
    system("pause");
}

Output::Output()
{
	fullscreen();
	Sleep(25);
    LoadingScreen();
    MenuItems[0] = "Start";
    MenuItems[1] = "Team Info";
    MenuItems[2] = "Exit";

    int cursor = 0;
    int value = -1;
    char key = ' ';

     system("cls");
     do{
        std::cout << "\n\n\n";
        for (int i = 0; i < 3; i++) {
            if (i == cursor) {
                std::cout<<"\n\n\n\t\t\t\t";  PrintOut(char(16), 'y'); PrintOut("  " + MenuItems[i] + "  ", 'b'); PrintOut(char(17), 'y');

            }
            else
            {
               std::cout << "\n\n\n\t\t\t\t"; PrintOut("  " + MenuItems[i] + "  ", 'b'); std::cout << "\t\t\t\t";
            }
        }
        std::cout << std::endl;
        key = _getch();
        switch (key) {
        case KEY_UP: cursor = (cursor == 0) ? 0 : --cursor; break;
        case KEY_DOWN: cursor = (cursor == 2) ? 2 : ++cursor; break;
        case ENTER_KEY:break;
        }
        Sleep(20);
        system("cls");  
     } while (key != ENTER_KEY);
}
template<class T>
void Output::PrintOut(T text,char color)
{
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (color) {
    case 'r': SetConsoleTextAttribute(console_color, 4); break;
    case 'g': SetConsoleTextAttribute(console_color, 2); break;
    case 'b': SetConsoleTextAttribute(console_color, 1); break;
    case 'y': SetConsoleTextAttribute(console_color, 6); break;
    default:  SetConsoleTextAttribute(console_color, 7); break;
    }
    std::cout << text; 
    SetConsoleTextAttribute(console_color, 7);
}
