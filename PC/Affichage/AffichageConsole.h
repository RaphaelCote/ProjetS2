#ifndef AFFICHAGE_CONSOLE_H
#define AFFICHAGE_CONSOLE_H

#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include <string>
#include <cwchar>
#include <wincon.h>
#include "../Vecteur.h"
#include "../Game/Boat.h"
#include "../Game/character.h"
#include "../Game/projectile.h"

using namespace std;

#define _WIN32_WINNT 0x0601

typedef struct _CONSOLE_FONT_INFOEX
{
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT  FontFamily;
    UINT  FontWeight;
    WCHAR FaceName[LF_FACESIZE];
}CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;
//the function declaration begins
#ifdef __cplusplus
extern "C" {
#endif
BOOL WINAPI GetCurrentConsoleFontEx(HANDLE hConsoleOutput,BOOL bMaximumWindow,PCONSOLE_FONT_INFOEX lpConsoleCurrentFont);
BOOL WINAPI SetCurrentConsoleFontEx(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx);
#ifdef __cplusplus
}
#endif



using namespace std;

#define CHAR_HEARTH                         '\x03'
#define CHAR_DIAMONDS                       '\x04'
#define CHAR_CLUB                           '\x05'
#define CHAR_SPADE                          '\x06'
#define CHAR_MALE                           '\x0B'
#define CHAR_FEMALE                         '\x0C'
#define CHAR_MUSIC                          '\x0E'
#define CHAR_SPIKE_BALL                     '\x0F'
#define CHAR_RIGHT_TRIANGLE                 '\x10'
#define CHAR_LEFT_TRIANGLE                  '\x11'
#define CHAR_UP_TRIANGLE                    '\x1E'
#define CHAR_DOWN_TRIANGLE                  '\x1F'
#define CHAR_BORDER_VERTICAL                '\xBA'
#define CHAR_BORDER_HORIZONTAL              '\xCD'
#define CHAR_BORDER_CROSS                   '\xEE'
#define CHAR_BORDER_TR_CORNER               '\xBB'
#define CHAR_BORDER_TL_CORNER               '\xC9'
#define CHAR_BORDER_BR_CORNER               '\xBC'
#define CHAR_BORDER_BL_CORNER               '\xC8'
#define CHAR_CONTRAST_LOW                   '\xB0'
#define CHAR_CONTRAST_MED                   '\xB1'
#define CHAR_CONTRAST_HIGH                  '\xB2'
#define CHAR_BORDER_R_JUNCTION              '\xCC'
#define CHAR_BORDER_L_JUNCTION              '\xB9'
#define CHAR_BORDER_T_JUNCTION              '\xCA'
#define CHAR_BORDER_B_JUNCTION              '\xCB'

#define STRING_BORDER_R_JUNCTION              "\xCC"
#define STRING_BORDER_L_JUNCTION              "\xB9"
#define STRING_BORDER_T_JUNCTION              "\xCA"
#define STRING_BORDER_B_JUNCTION              "\xCB"
#define STRING_HEARTH                         "\x03"
#define STRING_DIAMONDS                       "\x04"
#define STRING_CLUB                           "\x05"
#define STRING_SPADE                          "\x06"
#define STRING_MALE                           "\x0B"
#define STRING_FEMALE                         "\x0C"
#define STRING_MUSIC                          "\x0E"
#define STRING_SPIKE_BALL                     "\x0F"
#define STRING_RIGHT_TRIANGLE                 "\x10"
#define STRING_LEFT_TRIANGLE                  "\x11"
#define STRING_UP_TRIANGLE                    "\x1E"
#define STRING_DOWN_TRIANGLE                  "\x1F"
#define STRING_BORDER_VERTICAL                "\xBA"
#define STRING_BORDER_HORIZONTAL              "\xCD"
#define STRING_BORDER_CROSS                   "\xEE"
#define STRING_BORDER_TR_CORNER               "\xBB"
#define STRING_BORDER_TL_CORNER               "\xC9"
#define STRING_BORDER_BR_CORNER               "\xBC"
#define STRING_BORDER_BL_CORNER               "\xC8"
#define STRING_CONTRAST_LOW                   "\xB0"
#define STRING_CONTRAST_MED                   "\xB1"
#define STRING_CONTRAST_HIGH                  "\xB2"





struct Pixels
    {
        char texture;
        int FrontColour;
        int BackColour;
    };

struct ObjetAffichage
{
    Pixels **pix;
    bool pointeur;
    int couche;
    int x_coor; 
    int y_coor; 
    int *x; 
    int *y; 
    int width;
    int height;
    string name;
};

enum colors {
    black = 0,
    electric = 1,
    leaf = 2,
    lightblue = 3,
    red = 4,
    darkpurple = 5,
    gold = 6,
    lightgrey = 7,
    grey = 8,
    blue = 9,
    green = 10,
    aqua = 11,
    lightred = 12,
    purple = 13,
    yellow = 14,
    white = 15,
    transparant = 16,
};


class AffichageConsole
{
    bool Thread_Actif; 
    bool ModificationAFaire; 

    int NumberRows;
    int NumberColumns; 

    Pixels **screen;
    Pixels **screen_new;

    Vecteur<ObjetAffichage *> v_objet;
    
    
    DWORD WINAPI threadFunction(LPVOID lpParam);


    void PrintInColour(std::ostream & os, std::string toBePrinted, int foregroundColour, int backgroundColour);

    void SetTerminalCursorPosition(int column, int row);

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
    void ConsecutiveChar(std::ostream & os, char characterToDraw, int foregroundColour, int backgroundColour, int howMuchToRepeat, bool lineEnd);
    

public:
    int MaxRows;
    int MaxColumns;

    int MinRows;
    int Mincolums;

    int ScreenWidth;
    int ScreenHeight;

    int FontX;
    int FontY;



    AffichageConsole();
    AffichageConsole(int width, int height, int fontX, int fontY);
    ~AffichageConsole();

    void AjouterObjet(Pixels** tab, int x, int y, int width, int height, int couche, string name);
    void AjouterObjet(Pixels** tab, int *x, int *y, int width, int height, int couche, string name);
    void AjouterObjet(Pixels** tab, Character *charact, int couche, string name);
    void AjouterObjet(Pixels** tab, Boat *boat, int couche, string name);
    void AjouterObjet(Pixels** tab, Projectile *project, int couche, string name);
    void SupprimerObjet(string name);
    void AfficherEnBasGauche(Pixels** tab, int x, int y, int width, int height);
    void AfficherTexte(std::ostream & os, string s, int *x, int *y, string name);
    void AfficherTexte(std::ostream &os, string s, int x, int y, string name);
    void AfficherTexte(std::ostream & os, string s, int *x, int *y, int background, int frontcolor, string name);
    void AfficherTexte(std::ostream & os, string s, int x, int y, int background, int frontcolor, string name);
    void ResizeConsole();
    bool SetConsoleFontSize(COORD dwFontSize);

    void UpdateUI_Console();
    void ResetUI();
    void UpdateVecteurUI();
};


#endif