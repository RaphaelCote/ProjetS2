#include "EndGameMenu.h"

#include "../raftWars.h"

EndGameMenu::EndGameMenu()
{}

void Update()
{
    system("cls");
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Fin du niveau" << endl;
    cout << "-" << /*(choice == 0 ? "O" : "-")*/ 0 << "- Prochain niveau." << endl;
    cout << "-" << /*(choice >= 1 ? "O" : "-")*/ 0 << "- Sélectionner un niveau" << endl;
    cout << "-" << /*(choice == 0 ? "O" : "-")*/ 0 << "- Menu." << endl;
    cout << "-------------------------------------------------------------------" << endl;
}

void NextLevel()
{
    Game *g = (Game *)scenes->get(2);
    int level = g->currentLevel + 1;
    LevelSelectionMenu *lsm = (LevelSelectionMenu *)scenes->get(2);
    lsm->SelectLevel(level);
}

void GotoLevelSelect()
{
    LevelSelectionMenu *lsm = (LevelSelectionMenu *)scenes->get(2);
    lsm->lastMenu = 0; 
    // indiquer le bon index dans scenes pour aller dans LevelSelectionMenu (2)

}

void ReturnToMenu()
{
    // indiquer le bon index dans scenes pour retourner dans MainMenu (0)
}