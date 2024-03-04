#include "LevelSelectionMenu.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "../Controls/keyboardControls.h"

LevelSelectionMenu::LevelSelectionMenu()
{}

void LevelSelectionMenu::Update()
{
    Game *g = (Game *)scenes->get(2);
    system("cls");
    cout << "------------------------------------------------------" << endl;
    cout << "Sélectionner un niveau" << endl;
    cout << "-" << (g->currentLevel == 0 ? "0" : "-") << "- Niveau 1" << endl;
    cout << "-" << (g->currentLevel == 1 ? "0" : "-") << "- Niveau 2" << endl;
    cout << "-" << (g->currentLevel == 3 ? "0" : "-") << "- Niveau 3" << endl;
    cout << "-" << (g->currentLevel >= 4 ? "0" : "-") << "- Retour" << endl;
    cout << "------------------------------------------------------" << endl;
}

void LevelSelectionMenu::SelectLevel(int Level)
{
    system("cls");
    if (Level == 1)
    {
        // sélectionner niveau 1
    }
    else if (Level == 2)
    {
        // sélectionner niveau 2
    }
    else
    {
        Back();
    }
}

void LevelSelectionMenu::Back()
{
    // aller dans scenes à la variable lastMenu
}