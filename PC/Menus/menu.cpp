#include <iostream>
#include <string>
#include "menu.h"

#include "../raftWars.h"
#include "../controls/EventManager.h"

using namespace std;

void OnMainActionCall(EventParameters ep)
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

void OnJoystickCall(EventParameters ep)
{
        menu->changeSelection(ep);
}

void Menu::OnEnable()
{
        eventManager->on("MainAction", OnMainActionCall);
        eventManager->on("Joystick", OnJoystickCall);
}

void Menu::OnDisable()
{
        eventManager->off("MainAction", OnMainActionCall);
        eventManager->off("Joystick", OnJoystickCall);
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

void Menu::menuController()
{
        OnEnable();
        afficherMenuPrincipal();
        controls->ListenForControls();
}

void Menu::afficherMenuPrincipal()
{
        // menu utilisateur
        lastActiveMenu = 0;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Bienvenue au menu du jeu Raft Wars" << endl;
        cout << "-" << (choix == 0 ? "O" : "-") << "- Commencer." << endl;
        // cout << " 2. Choisir un niveau." << endl;
        cout << "-" << (choix >= 1 ? "O" : "-") << "- Sortir" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Veuillez entrer votre action : ";
}

void Menu::selectionMenuPrincipal()
{
        if (choix == 0)
        {

                system("cls"); // clear la command prompt
                game->StartGame();
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
        lastActiveMenu = 1;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "MENU PAUSE" << endl;
        cout << "0. Reprendre" << endl;
        cout << "1. Recommencer le niveau" << endl;
        cout << "2. Revenir au menu principal" << endl;
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

void Menu::afficherMenuFin()
{
        lastActiveMenu = 2;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Bravo, vous avez réussi le niveau!" << endl;
        cout << "0. Prochain niveau" << endl;
        cout << "1. Recommencer le niveau" << endl;
        cout << "2. Revenir au menu principal" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Veuillez entrer votre selection :";
        cin >> choix;
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
