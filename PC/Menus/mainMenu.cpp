#include <iostream>
#include <string>
#include "mainMenu.h"
using namespace std;
#define SORTIR 3
#define COMMENCER 1
#define NIVEAU 2

void Menu::afficherMenu()
{
    


    // menu utilisateur
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Bienvenue au menu du jeu Raft Wars" << endl;
    cout << " 1. Commencer." << endl;
    cout << " 2. Choisir un niveau." << endl;
    cout << "3. Sortir" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    
    
    while (choix != SORTIR){
    cout << "Veuillez entrer votre selection :";
    cin >> choix;

    switch (choix){

        case COMMENCER:
               system("cls");           //clear la command prompt
                //appeler la fonction qui débute une partie

        case NIVEAU:
                system("cls");
                //appeler la fonction du choix de niveau (si on fait plusieurs niveaux)
        
        case SORTIR: 
                cout << "Au plaisir..";
                exit(0);
        default:
                cout << "Option incorrecte...";

    }
    }
    

}

void Menu::menuPause()
{
    cout << "-------------------------------------------------------------------" << endl;
    cout << "MENU PAUSE" << endl;
    cout << " 1. Reprendre" << endl;
    cout << " 2. Recommencer le niveau" << endl;
    cout << "3. Revenir au menu principal" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Veuillez entrer votre selection :";
    cin >> choix;

    switch (choix){

        case 1:
               system("cls");           //clear la command prompt
                //appeler la fonction qui débute une partie

        case 2:
                system("cls");
                //appeler la fonction du choix de niveau (si on fait plusieurs niveaux)
        
        case SORTIR: 
                system("cls");
                afficherMenu();
        default:
                cout << "Option incorrecte...";

    }

}

void Menu::menuFin()
{

    cout << "-------------------------------------------------------------------" << endl;
    cout << "Bravo, vous avez réussi le niveau!" << endl;
    cout << " 1. Prochain niveau" << endl;
    cout << " 2. Recommencer le niveau" << endl;
    cout << "3. Revenir au menu principal" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Veuillez entrer votre selection :";
    cin >> choix;

    switch (choix){

        case 1:
               system("cls");           //clear la command prompt
                //appeler la fonction qui va au next level

        case 2:
                system("cls");
                //appeler la fonction du choix de niveau (si on fait plusieurs niveaux)
        
        case SORTIR: 
                system("cls");
                afficherMenu();
        default:
                cout << "Option incorrecte...";

    }

}
