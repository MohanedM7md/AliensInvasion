#include "Output.h"

// Constructor for the Output class
Output::Output()
{   
    // Get a handle to the standard output console
    ConsoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    // ===== SECTION FOR SETTING FONT SIZE, FONT FAMILY, AND FULL SCREEN =====
    // This section is commented out as directly changing font family 
    // Simulate Alt+Enter keypress for full screen (might not work reliably)
    Sleep(1000);
    keybd_event(VK_MENU, 0x38, 0, 0); // Alt button down
    keybd_event(VK_RETURN, 0x1c, 0, 0); // Enter button Down
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); // Alt up
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); //Enter up
    Sleep(800);// Sleep for a short time to avoid potential issues with window resizing
   

    // Get information about the console screen buffer
    GetConsoleScreenBufferInfo(ConsoleHandler, &screen);
    setFont(35);
    // ===== END OF SECTION =====
}


// Function to display a menu and handle user input 
int Output::ScreenMenu(std::string* MenuItems, int MinueSize)
{
    ClearScreen(); //clearing screen
   
    int cursor = 0; // Current selected item index(0) (cursor)
    char key = NULL;   // Key pressed by the user

   
    do {
        std::cout << "\n\n\n";
        for (int i = 0; i < MinueSize; i++) {
            // If the current item is selected
            if (i == cursor) {
                // Print arrow characters and the menu item 
                std::cout << "\n\n\n\t\t"; 
                PrintOut(">", LIGHT_YELLOW); //Right Arrow
                PrintOut("  " + MenuItems[i] + "  ", ORANGE);
                PrintOut("<", LIGHT_YELLOW); // Left arrow
            }
            else // Print the other menu items
            {
                std::cout << "\n\n\n\t\t";
                PrintOut("  " + MenuItems[i] + "  ", ORANGE);
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
        // Get the key pressed by the user
        key = _getch();
        switch (key) {
        case KEY_UP: cursor = (cursor == 0) ? 0 : --cursor; break;
        case KEY_DOWN: cursor = (cursor == MinueSize-1) ? MinueSize-1 : ++cursor; break;
        }
        Sleep(5);//smoth menue animation
        SetConsoleCursorPosition(ConsoleHandler, { 0, 0 });
    } while (key != ENTER_KEY);
    
    ClearScreen(); //clearing screen
    return cursor;
}

void Output::ClearScreen() //To clear output Screen
{
   

    DWORD written;
    FillConsoleOutputCharacterA(
        ConsoleHandler,' ', screen.dwSize.X * 50,
        { 0, 0 }, &written);
    SetConsoleCursorPosition(ConsoleHandler, { 0, 0 });
}

// Function to set the console font size and optionally the font family
void Output::setFont(short size, const std::wstring& fontType ) {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0; // Width of each character (default)
    cfi.dwFontSize.Y = size; // Height
    cfi.FontWeight = FW_BOLD; // Bold font style
    wcscpy_s(cfi.FaceName, L"Terminal");
    SetCurrentConsoleFontEx(ConsoleHandler, FALSE, &cfi);
}

HANDLE Output::getConsoleHandler() const
{
    return this->ConsoleHandler;
}

void Output::ES_Print()
{
    
    SetConsoleTextAttribute(ConsoleHandler, ORANGE);
    std::cout << "  "<< char(254) << '\n';
    SetConsoleTextAttribute(ConsoleHandler, LIGHT_GREEN);
    std::cout << ' ' << char(218) << char(197) << char(217);
    SetConsoleTextAttribute(ConsoleHandler, DARK_GREEN);
    std::cout << '\n' << "  " << char(219) << '\t';
    std::cout << '\n' << " " << char(47) << ' ' << char(92) << '\t';
    std::cout << "\x1B[1A";
    
}

void Output::ET_Print()
{

    SetConsoleTextAttribute(ConsoleHandler, DARK_GREEN);
    std::cout << "  " << static_cast<char>(178) << static_cast<char>(178) << static_cast<char>(205) << static_cast<char>(205) << ' ' << std::endl;
    std::cout << " " << static_cast<char>(219) << static_cast<char>(219) << static_cast<char>(219) << static_cast<char>(219);
    SetConsoleTextAttribute(ConsoleHandler, GRAY);
    std::cout << "\n O  O\t";
    std::cout << "\x1B[1A";
}

void Output::EG_Print()
{
    SetConsoleTextAttribute(ConsoleHandler, LIGHT_GREEN);
    std::cout << " " << static_cast<char>(219) << static_cast<char>(219)
        << static_cast<char>(223) << static_cast<char>(223);
    SetConsoleTextAttribute(ConsoleHandler, DARK_GREEN);
    std::cout << static_cast<char>(223) << '\t';
    SetConsoleTextAttribute(ConsoleHandler, GRAY);
   // std::cout << "\x1B[1A";
}

void Output::Soon_Print()
{
    SetConsoleTextAttribute(ConsoleHandler, LIGHT_RED);
    std::cout << "SOON....  ";
}

void Output::AS_print()
{
    SetConsoleTextAttribute(ConsoleHandler, PURPLE);
    std::cout << "   " << char(238) << '\n';
    std::cout << ' ' << char(174) << char(196) << char(197) << char(196) << char(175);
    std::cout << '\n' << "   " << char(219) << '\t';
    std::cout << '\n' << "  " << char(47) << ' ' << char(92) << '\t';
    std::cout << "\x1B[1A";
}

void Output::AM_print()
{
    SetConsoleTextAttribute(ConsoleHandler, ORANGE);
    std::cout << "   " << "oo" << '\n';
    std::cout << "  " << char(219) << char(223) << char(223) << char(219) << '\t';
    std::cout << "\n  " << char(186) << char(223) << char(223) << char(186) << '\t';
    std::cout << "\n  " << char(202) << "  " << char(202) << '\t';
    std::cout << "\x1B[1A";
}

void Output::AD_print()
{
    SetConsoleTextAttribute(ConsoleHandler, ORANGE);
    std::cout << "  " << char(196) << char(197) << char(196) << '\n';
    std::cout << "  "  << char(219) << char(219) << char(219) << char(205) << char(207) << '\t';
    std::cout << "\n  " << char(217) << " " << char(192) << '\t';
    std::cout << "\x1B[1A";
}



void Output::LoadingScreen()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 1,false };
    SetConsoleCursorInfo(ConsoleHandler, &cursorInfo);

    COORD AlignText = { 23,5 };
    GetConsoleScreenBufferInfo(ConsoleHandler, &screen);
    SetConsoleCursorPosition(ConsoleHandler, AlignText);

    PrintOut("Loading",ORANGE);
    AlignText = { static_cast<SHORT>(12), 10 };
    SetConsoleCursorPosition(ConsoleHandler, AlignText);

    for (int i = 0; i < 30; i++) {
        Sleep(70);//to Make smooth Real Loading.
        PrintOut(char(219),LIGHT_GREEN);//loader
    }
    std::cout << "\n\n\n\n\t";
    system("pause");
}

void Output::screenRefesher()//after changing the screen size font the console need to be resized to to make it good
{
    Sleep(1000);
    keybd_event(VK_MENU, 0x38, 0, 0); // Alt button down
    keybd_event(VK_RETURN, 0x1c, 0, 0); // Enter button Down
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); // Alt up
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); //Enter up
    Sleep(800);// Sleep for a short time to avoid potential issues with window resizing
    Sleep(1000);
    keybd_event(VK_MENU, 0x38, 0, 0); // Alt button down
    keybd_event(VK_RETURN, 0x1c, 0, 0); // Enter button Down
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); // Alt up
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); //Enter up
    Sleep(1000);// 
}


template<class T>
void Output::PrintOut(T text,COLOR color)  //Print Function to print output With Colors Defualt white
{
    
    SetConsoleTextAttribute(ConsoleHandler, color);
    std::cout << text; 
    SetConsoleTextAttribute(ConsoleHandler, WHITE);
}
