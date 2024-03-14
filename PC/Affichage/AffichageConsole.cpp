
#include <windows.h>
#include <thread>
#include <string>
#include <cwchar>
#include "AffichageConsole.h"

static DWORD WINAPI ThreadEntry(LPVOID lpParam) {
        auto* data = reinterpret_cast<std::pair<AffichageConsole*, int>*>(lpParam);
        if (data) {
            data->first->UpdateUI();
            delete data;
        }
        return 0;
    }

AffichageConsole::AffichageConsole()
{
    ModificationAFaire = true;
    MaxRows = 80;
    MaxColumns = 119;

    ScreenWidth = 1250;
    ScreenHeight = 750;
    FontX = 8;
    FontY = 12;

    /////////////////////////////////////////////////////////////////////////////////////////

    // Create a lambda function to capture the instance of MyClass and call its member function
    auto lambda = [&](int arg) {
        this->UpdateUI();
    };

    // Create a pair to store MyClass instance and the argument
    auto* data = new std::pair<AffichageConsole*, int>(this,42);

    // Create a thread and pass the entry point function
    HANDLE threadHandle = CreateThread(nullptr, 0, ThreadEntry, data, 0, nullptr);

    if (threadHandle == nullptr) {
        std::cerr << "Error creating thread.\n";
    }
    /////////////////////////////////////////////////////////////////////////////////////////

    
    screen = new Pixels *[MaxRows];
    for (int i = 0; i < MaxRows; ++i)
    {
        screen[i] = new Pixels[MaxColumns];
    }

    ResizeConsole();
}

AffichageConsole::AffichageConsole(int width, int height, int fontX, int fontY)
{
    ModificationAFaire = true;
    MaxRows = 44;
    MaxColumns = 169;

    ScreenWidth = width;
    ScreenHeight = height;
    FontX = fontX;
    FontY = fontY;

    // Create a lambda function to capture the instance of MyClass and call its member function
    auto lambda = [&](int arg) {
        this->UpdateUI();
    };

    // Create a pair to store MyClass instance and the argument
    auto* data = new std::pair<AffichageConsole*, int>(this,42);

    // Create a thread and pass the entry point function
    HANDLE threadHandle = CreateThread(nullptr, 0, ThreadEntry, data, 0, nullptr);

    if (threadHandle == nullptr) {
        std::cerr << "Error creating thread.\n";
    }
    /////////////////////////////////////////////////////////////////////////////////////////

    screen = new Pixels *[MaxRows];
    for (int i = 0; i < MaxRows; ++i)
    {
        screen[i] = new Pixels[MaxColumns];
    }

    ResizeConsole();
}

AffichageConsole::~AffichageConsole()
{
    for (int i = 0; i < MaxRows; ++i) {
        delete[] screen[i];
    }
    delete[] screen;
}

// bool AffichageConsole::SetConsoleFontSize(COORD dwFontSize) {
//     HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
//     CONSOLE_FONT_INFOEX info{ sizeof(CONSOLE_FONT_INFOEX) };
//     if (!GetCurrentConsoleFontEx(output, false, &info))
//         return false;
//     info.dwFontSize = dwFontSize;
//     return SetCurrentConsoleFontEx(output, false, &info);
// }


void AffichageConsole::ResizeConsole()
{
    // COORD coord;
    // coord.X = 8;
    // coord.Y = 9;
    //SetConsoleFontSize(coord);

    HWND console = GetConsoleWindow();
    RECT rect = { 10, 10, ScreenWidth, ScreenHeight };
    MoveWindow(console, rect.left, rect.top, rect.right, rect.bottom, TRUE);
}


void AffichageConsole::AfficherEnBasGauche(Pixels** tab, int x, int y, int width, int height)
{
    for (int j = 0; j < height; j++)
    {
        for(int i = 0; i < width; i++)
        {
            
            if(!(tab[j][i].FrontColour == colors::transparant || tab[j][i].BackColour == colors::transparant))
            {
                screen[y + j][x+i].BackColour = tab[j][i].BackColour;
                screen[y + j][x+i].FrontColour = tab[j][i].FrontColour;
                screen[y + j][x+i].texture = tab[j][i].texture;
            }

            // if(!(tab[i][j].FrontColour == colors::transparant || tab[i][j].BackColour == colors::transparant))
            // {
            //     screen[i][j].BackColour = tab[i][j].BackColour;
            //     screen[i][j].FrontColour = tab[i][j].FrontColour;
            //     screen[i][j].texture = tab[i][j].texture;
            // }
        }
    }

    ModificationAFaire = true;
}


void AffichageConsole::UpdateUI()
{
    if(ModificationAFaire)
    {
        for (int j = 0; j < MaxRows; j++)
        {
            for(int i = 0; i < MaxColumns; i++)
            {
                if(!(screen[j][i].FrontColour == colors::transparant || screen[j][i].BackColour == colors::transparant))
                {
                    SetTerminalCursorPosition(i, j);
                    ConsecutiveChar(cout, screen[j][i].texture, screen[j][i].FrontColour, screen[j][i].BackColour, 1, false);
                }
            }
        }
        ModificationAFaire = false;
    }
    Sleep(1);


    
}


void AffichageConsole::ResetUI()
{
    for (int j = 0; j < MaxRows; j++)
    {
        for(int i = 0; i < MaxColumns; i++)
        {
            screen[j][i].BackColour = colors::black;
            screen[j][i].FrontColour = colors::black;
            screen[j][i].texture = ' ';
        }
    }


    ModificationAFaire = false;
}






void AffichageConsole::SetTerminalCursorPosition(int column, int row)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {column, row};
    SetConsoleCursorPosition(hConsole, pos);
    return;
}


void AffichageConsole::PrintInColour(std::ostream & os, std::string toBePrinted, int foregroundColour, int backgroundColour)
{
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   int colour = backgroundColour * 16 + foregroundColour;
   SetConsoleTextAttribute(hConsole, colour);
   os << toBePrinted;
   SetConsoleTextAttribute(hConsole, 7);
}

/**
 * @brief 
 * # ConsecutiveChar
 * @brief
 * Allows you to spam a character for X amount of times on your terminal.
 * This allows waaaay easier prints of decors.
 * @param os 
 * @param characterToDraw 
 * @param foregroundColour 
 * @param backgroundColour 
 * @param howMuchToRepeat 
 * @param lineEnd 
 */
void AffichageConsole::ConsecutiveChar(std::ostream & os, char characterToDraw, int foregroundColour, int backgroundColour, int howMuchToRepeat, bool lineEnd)
{
    std::string result = "";
    for(int i=0; i<howMuchToRepeat; i++)
    {
        result += characterToDraw;
    }

    if(lineEnd)
    {
        result += '\n';
    }

    PrintInColour(os, result, foregroundColour, backgroundColour);
}