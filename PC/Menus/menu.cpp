#include <iostream>
#include <string>
#include "menu.h"

#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "../Controls/keyboardControls.h"

using namespace std;

Menu::Menu()
{
}

void OnMenuMainActionCall(EventParameters ep)
{
        if (menu->lastActiveMenu == 0)
        {
                menu->selectionMenuPrincipal();
        }
        else if (menu->lastActiveMenu == 1)
        {
                menu->selectionMenuPause();
        }
        else if (menu->lastActiveMenu == 2)
        {
                menu->selectionMenuFin();
        }
}

void OnMenuJoystickCall(EventParameters ep)
{
        menu->changeSelection(ep);
}

void Menu::OnEnable()
{
        eventManager->on("MainAction", OnMenuMainActionCall);
        eventManager->on("Joystick", OnMenuJoystickCall);
        // cout << "did on Enable" << endl;
}

void Menu::OnDisable()
{
        eventManager->off("MainAction", OnMenuMainActionCall);
        eventManager->off("Joystick", OnMenuJoystickCall);
}

void Menu::changeSelection(EventParameters ep)
{
        if (ep.parameter2 > 0.5)
        {
                choix--;
                if (choix < 0)
                {
                        choix = 0;
                }
        }
        else if (ep.parameter2 < -0.5)
        {
                choix++;
        }
}

void Menu::menuController(int menu)
{
        OnEnable();
        if (menu == 0)
        {
                while (true)
                {
                        afficherMenuPrincipal();
                        controls->ListenForControls();
                }
        }
        else if (menu == 1)
        {
                afficherMenuPause();
                controls->ListenForControls();
        }
        else if (menu == 2)
        {
                afficherMenuFin("Test");
                controls->ListenForControls();
        }
}

void Menu::afficherMenuPrincipal()
{
        // menu utilisateur
        system("cls");
        lastActiveMenu = 0;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Bienvenue au menu du jeu Raft Wars" << endl;
        cout << "-" << (choix == 0 ? "O" : "-") << "- Commencer." << endl;
        // cout << " 2. Choisir un niveau." << endl;
        cout << "-" << (choix >= 1 ? "O" : "-") << "- Sortir" << endl;
        cout << "-------------------------------------------------------------------" << endl;
}

void Menu::selectionMenuPrincipal()
{
        if (choix == 0)
        {

                system("cls"); // clear la command prompt
                OnDisable();
                game->PlayGame();
        }
        else if (choix >= 1)
        {

                system("cls"); // clear la command prompt
                cout << "Au plaisir.." << endl;
                system("PAUSE");
                exit(0);
        }
}

void Menu::afficherMenuPause()
{
        system("cls");
        lastActiveMenu = 1;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "MENU PAUSE" << endl;
        cout << "-" << (choix == 0 ? "O" : "-") << "- Reprendre" << endl;
        cout << "-" << (choix == 0 ? "O" : "-") << "- Revenir au menu principal" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Veuillez entrer votre selection :";
        cin >> choix;
}

void Menu::selectionMenuPause()
{
        switch (choix)
        {

        case 0:
                system("cls"); // clear la command prompt
                               // appeler la fonction qui débute une partie

        case 1:
                system("cls");
                // appeler la fonction du choix de niveau (si on fait plusieurs niveaux)

        case 2:
                system("cls");
                afficherMenuPrincipal();
        default:
                cout << "Option incorrecte...";
        }
}

void Menu::afficherMenuFin(string message)
{
        system("cls");
        lastActiveMenu = 2;
        cout << "-------------------------------------------------------------------" << endl;
        //"Bravo, vous avez réussi le niveau!"
        cout << message << endl;
        cout << "-" << (choix == 0 ? "O" : "-") << "- Prochain niveau" << endl;
        cout << "-" << (choix == 0 ? "O" : "-") << "- Recommencer le niveau" << endl;
        cout << "-" << (choix == 0 ? "O" : "-") << "- Revenir au menu principal" << endl;
        cout << "-------------------------------------------------------------------" << endl;
}

void Menu::selectionMenuFin()
{
        switch (choix)
        {

        case 0:
                system("cls"); // clear la command prompt
                               // appeler la fonction qui va au next level

        case 1:
                system("cls");
                // appeler la fonction du choix de niveau (si on fait plusieurs niveaux)

        case 2:
                system("cls");
                afficherMenuPrincipal();
        default:
                cout << "Option incorrecte...";
        }
}
