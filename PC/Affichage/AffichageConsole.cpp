

#include "AffichageConsole.h"

static DWORD WINAPI ThreadEntry(LPVOID lpParam)
{
    auto *data = reinterpret_cast<std::pair<AffichageConsole *, int> *>(lpParam);
    if (data)
    {
        data->first->UpdateUI_Console();
        delete data;
    }
    return 0;
}

AffichageConsole::AffichageConsole()
{
    ModificationAFaire = true;

    NumberRows = 65;
    NumberColumns = 120;
    MaxRows = NumberRows;
    MaxColumns = NumberColumns;

    MinRows = 0;
    Mincolums = 0;
    ScreenWidth = 1300;
    ScreenHeight = 750;
    FontX = 10;
    FontY = 10;

    screen = new Pixels *[MaxRows];
    for (int i = 0; i < MaxRows; ++i)
    {
        screen[i] = new Pixels[MaxColumns];
        for (int j = 0; j < MaxColumns; j++)
        {
            screen[i][j] = {colors::black, colors::black, ' '};
        }
    }

    screen_new = new Pixels *[MaxRows];
    for (int i = 0; i < MaxRows; ++i)
    {
        screen_new[i] = new Pixels[MaxColumns];
        for (int j = 0; j < MaxColumns; j++)
        {
            screen_new[i][j] = {colors::black, colors::black, ' '};
        }
    }

    Thread_Actif = true;
    /////////////////////////////////////////////////////////////////////////////////////////

    // Create a lambda function to capture the instance of MyClass and call its member function
    auto lambda = [&](int arg)
    {
        this->UpdateUI_Console();
    };

    // Create a pair to store MyClass instance and the argument
    auto *data = new std::pair<AffichageConsole *, int>(this, 42);

    // Create a thread and pass the entry point function
    HANDLE threadHandle = CreateThread(nullptr, 0, ThreadEntry, data, 0, nullptr);

    if (threadHandle == nullptr)
    {
        std::cerr << "Error creating thread.\n";
    }
    /////////////////////////////////////////////////////////////////////////////////////////

    ResizeConsole();
}

AffichageConsole::AffichageConsole(int width, int height, int fontX, int fontY)
{
    ModificationAFaire = true;
    NumberRows = 44;
    NumberColumns = 169;
    MaxRows = NumberRows;
    MaxColumns = NumberColumns;

    MinRows = 0;
    Mincolums = 0;
    ScreenWidth = width;
    ScreenHeight = height;
    FontX = fontX;
    FontY = fontY;

    screen = new Pixels *[MaxRows];
    for (int i = 0; i < MaxRows; ++i)
    {
        screen[i] = new Pixels[MaxColumns];
        for (int j = 0; j < MaxColumns; j++)
        {
            screen[i][j] = {colors::black, colors::black, ' '};
        }
    }

    screen_new = new Pixels *[MaxRows];
    for (int i = 0; i < MaxRows; ++i)
    {
        screen_new[i] = new Pixels[MaxColumns];
        for (int j = 0; j < MaxColumns; j++)
        {
            screen_new[i][j] = {colors::black, colors::black, ' '};
        }
    }

    Thread_Actif = true;

    // Create a lambda function to capture the instance of MyClass and call its member function
    auto lambda = [&](int arg)
    {
        this->UpdateUI_Console();
    };

    // Create a pair to store MyClass instance and the argument
    auto *data = new std::pair<AffichageConsole *, int>(this, 42);

    // Create a thread and pass the entry point function
    HANDLE threadHandle = CreateThread(nullptr, 0, ThreadEntry, data, 0, nullptr);

    if (threadHandle == nullptr)
    {
        std::cerr << "Error creating thread.\n";
    }
    /////////////////////////////////////////////////////////////////////////////////////////

    ResizeConsole();
}

AffichageConsole::~AffichageConsole()
{
    Thread_Actif = false;
    for (int i = 0; i < MaxRows; ++i)
    {
        delete[] screen[i];
    }
    delete[] screen;
}

bool AffichageConsole::SetConsoleFontSize(COORD dwFontSize)
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = FontX; // Width of each character in the font
    cfi.dwFontSize.Y = FontY; // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetCurrentConsoleFontEx(output, false, &cfi);
}

void AffichageConsole::ResizeConsole()
{
    COORD coord;
    coord.X = FontX;
    coord.Y = FontY;
    SetConsoleFontSize(coord);

    HWND console = GetConsoleWindow();
    RECT rect = {0, 0, ScreenWidth, ScreenHeight};
    MoveWindow(console, rect.left, rect.top, rect.right, rect.bottom, TRUE);
}

void AffichageConsole::AjouterObjet(Pixels **tab, int *x, int *y, int width, int height, int couche, string name)
{
    ObjetAffichage *obj1 = new ObjetAffichage;
    obj1->pix = tab;
    obj1->x = x;
    obj1->y = y;
    obj1->width = width;
    obj1->height = height;
    obj1->couche = couche;
    obj1->name = name;

    v_objet.add(obj1);
}

void AffichageConsole::AjouterObjet(Pixels **tab, Character *charact, int couche, string name)
{
    Coordonnee *coor = charact->PointeurPosition();
    ObjetAffichage *obj1 = new ObjetAffichage;
    obj1->pix = tab;
    obj1->x = &coor->x;
    obj1->y = &coor->y;
    obj1->width = charact->getHitboxWidth() / 10;
    obj1->height = charact->getHitboxHeight() / 10;
    obj1->couche = couche;
    obj1->name = name;

    v_objet.add(obj1);
}

void AffichageConsole::AjouterObjet(Pixels **tab, Boat *boat, int couche, string name)
{
    ObjetAffichage *obj1 = new ObjetAffichage;
    obj1->pix = tab;
    obj1->x = boat->getPointerPositionBoat_X();
    obj1->y = boat->getPointerPositionBoat_X();
    obj1->width = boat->getHitboxBoat().width;
    obj1->height = boat->getHitboxBoat().height;
    obj1->couche = couche;
    obj1->name = name;

    v_objet.add(obj1);
}

void AffichageConsole::AjouterObjet(Pixels **tab, Projectile *project, int couche, string name)
{
    ObjetAffichage *obj1 = new ObjetAffichage;
    obj1->pix = tab;
    obj1->x = &project->bulletCurrentPosition.x;
    obj1->y = &project->bulletCurrentPosition.y;
    obj1->width = 1;
    obj1->height = 1;
    obj1->couche = couche;
    obj1->name = name;

    v_objet.add(obj1);
}

void AffichageConsole::SupprimerObjet(string name)
{
    for (int i = 0; i < v_objet.getSize(); i++)
    {
        if (v_objet[i]->name == name)
        {
            v_objet.remove(i);
        }
    }
}

void AffichageConsole::AfficherEnBasGauche(Pixels **tab, int x, int y, int width, int height)
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {

            if (!(tab[j][i].FrontColour == colors::transparant || tab[j][i].BackColour == colors::transparant))
            {
                if (!(y - j >= MaxRows || x + i >= MaxColumns))
                {
                    if (y - j >= 0)
                    {
                        screen[y - j][x + i].BackColour = tab[j][i].BackColour;
                        screen[y - j][x + i].FrontColour = tab[j][i].FrontColour;
                        screen[y - j][x + i].texture = tab[j][i].texture;
                    }
                }
            }
        }
    }

    ModificationAFaire = true;
}

void AffichageConsole::AfficherTexte(std::ostream &os, string s, int *x, int *y, string name)
{
    ObjetAffichage *obj1 = new ObjetAffichage;

    obj1->pix = new Pixels *[1];
    for (int i = 0; i < 1; ++i)
    {
        obj1->pix[i] = new Pixels[s.length()];
    }

    for (int i = 0; i < s.length(); i++)
    {
        obj1->pix[0][i].BackColour = colors::black;
        obj1->pix[0][i].FrontColour = colors::white;
        obj1->pix[0][i].texture = s[i];
    }

    obj1->x = x;
    obj1->y = y;
    obj1->width = s.length();
    obj1->height = 1;
    obj1->couche = 0;
    obj1->name = name;

    v_objet.add(obj1);
}

void AffichageConsole::AfficherTexte(std::ostream &os, string s, int *x, int *y, int background, int frontcolor, string name)
{
    ObjetAffichage *obj1 = new ObjetAffichage;

    obj1->pix = new Pixels *[1];
    for (int i = 0; i < 1; ++i)
    {
        obj1->pix[i] = new Pixels[s.length()];
    }

    for (int i = 0; i < s.length(); i++)
    {
        obj1->pix[0][i].BackColour = background;
        obj1->pix[0][i].FrontColour = frontcolor;
        obj1->pix[0][i].texture = s[i];
    }

    obj1->x = x;
    obj1->y = y;
    obj1->width = s.length();
    obj1->height = 1;
    obj1->couche = 0;
    obj1->name = name;

    v_objet.add(obj1);
}

void AffichageConsole::UpdateUI_Console()
{
    // Sleep(1000);
    while (Thread_Actif)
    {
        if (ModificationAFaire)
        {
            SetTerminalCursorPosition(0, 0);
            UpdateVecteurUI();
            // main affichage(affichage static)
            for (int j = 0; j < NumberRows; j++)
            {
                for (int i = 0; i < NumberColumns; i++)
                {
                    if (!(screen[j][i].FrontColour == colors::transparant || screen[j][i].BackColour == colors::transparant))
                    {
                        if ((screen_new[j][i].FrontColour != screen[j][i].FrontColour || screen_new[j][i].BackColour != screen[j][i].BackColour || screen_new[j][i].texture != screen[j][i].texture))
                        {
                            screen_new[j][i].BackColour = screen[j][i].BackColour;
                            screen_new[j][i].FrontColour = screen[j][i].FrontColour;
                            screen_new[j][i].texture = screen[j][i].texture;
                            SetTerminalCursorPosition(i, j);
                            ConsecutiveChar(cout, screen_new[j][i].texture, screen_new[j][i].FrontColour, screen_new[j][i].BackColour, 1, false);
                        }
                    }
                    else
                    {
                        screen_new[j][i].BackColour = screen[j][i].BackColour;
                        screen_new[j][i].FrontColour = screen[j][i].FrontColour;
                        screen_new[j][i].texture = screen[j][i].texture;
                    }
                }
            }
            // ModificationAFaire = false;
        }
        Sleep(1);
    }
}

void AffichageConsole::ResetUI()
{
    for (int j = 0; j < NumberRows; j++)
    {
        for (int i = 0; i < NumberColumns; i++)
        {
            screen[j][i].BackColour = colors::black;
            screen[j][i].FrontColour = colors::black;
            screen[j][i].texture = ' ';
        }
    }

    ModificationAFaire = true;
}

void AffichageConsole::UpdateVecteurUI()
{
    ResetUI();
    MaxRows = MinRows + NumberRows;
    MaxColumns = Mincolums + NumberColumns;
    for (int comptObjet = 0; comptObjet < v_objet.getSize(); comptObjet++)
    {
        ObjetAffichage *aff = v_objet[comptObjet];

        for (int j = 0; j < aff->height; j++)
        {
            for (int i = 0; i < aff->width; i++)
            {
                if (!((*aff->y) - j >= MaxRows || (*aff->x) + i >= MaxColumns))
                {
                    if ((*aff->y) - j >= MinRows && (*aff->x) + i >= Mincolums)
                    {
                        if (!(aff->pix[j][i].FrontColour == colors::transparant || aff->pix[j][i].BackColour == colors::transparant))
                        {
                            screen[(*aff->y) - j + MinRows][(*aff->x) + i - Mincolums].BackColour = aff->pix[j][i].BackColour;
                            screen[(*aff->y) - j + MinRows][(*aff->x) + i - Mincolums].FrontColour = aff->pix[j][i].FrontColour;
                            screen[(*aff->y) - j + MinRows][(*aff->x) + i - Mincolums].texture = aff->pix[j][i].texture;
                        }
                    }
                }
            }
        }
    }
}

void AffichageConsole::SetTerminalCursorPosition(int column, int row)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {column, row};
    SetConsoleCursorPosition(hConsole, pos);
    return;
}

void AffichageConsole::PrintInColour(std::ostream &os, string toBePrinted, int foregroundColour, int backgroundColour)
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

void AffichageConsole::ConsecutiveChar(std::ostream &os, char characterToDraw, int foregroundColour, int backgroundColour, int howMuchToRepeat, bool lineEnd)
{
    std::string result = "";
    for (int i = 0; i < howMuchToRepeat; i++)
    {
        result += characterToDraw;
    }

    if (lineEnd)
    {
        result += '\n';
    }

    PrintInColour(os, result, foregroundColour, backgroundColour);
}