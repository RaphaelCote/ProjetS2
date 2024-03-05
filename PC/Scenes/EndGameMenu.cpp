#include "EndGameMenu.h"
#include "../raftWars.h"

EndGameMenu::EndGameMenu()
{}

void EndGameMenu::Update()
{
    system("cls");
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Fin du niveau" << endl;
    cout << "-" << (choice == 0 ? "O" : "-") << "- Prochain niveau" << endl;
    cout << "-" << (choice == 1 ? "O" : "-") << "- Sélectionner un niveau" << endl;
    cout << "-" << (choice == 2 ? "O" : "-") << "- Menu" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    controls->ListenForControls();
}

void EndGameMenu::NextLevel()
{
    Game *g = (Game *)scenes->get(2);
    int level = g->currentLevel + 1;
    LevelSelectionMenu *lsm = (LevelSelectionMenu *)scenes->get(2);
    lsm->SelectLevel(level);
    activeScene = 1;
}

void EndGameMenu::GotoLevelSelect()
{
    LevelSelectionMenu *lsm = (LevelSelectionMenu *)scenes->get(2);
    lsm->lastMenu = 0; 
    activeScene = 2;
}

void ReturnToMenu()
{
    activeScene = 0;
}