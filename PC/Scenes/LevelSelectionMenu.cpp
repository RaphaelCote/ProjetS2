#include "LevelSelectionMenu.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "../Controls/keyboardControls.h"

void OnLevelSelectionMenuMainActionCall(EventParameters ep)
{
    Menu *menu = (Menu *)scenes->get(activeScene);
    menu->Selection();
}

void OnLevelSelectionMenuJoystickCall(EventParameters ep)
{
    Menu *menu = (Menu *)scenes->get(activeScene);
    menu->changeSelection(ep);
}

void LevelSelectionMenu::OnEnable()
{
    eventManager->on("MainAction", OnLevelSelectionMenuMainActionCall);
    eventManager->on("Joystick", OnLevelSelectionMenuJoystickCall);
}

void LevelSelectionMenu::OnDisable()
{
    eventManager->off("MainAction", OnLevelSelectionMenuMainActionCall);
    eventManager->off("Joystick", OnLevelSelectionMenuJoystickCall);
}

LevelSelectionMenu::LevelSelectionMenu()
{
}

void LevelSelectionMenu::changeSelection(EventParameters ep)
{
    if (ep.parameter2 > 0.5)
    {
        choice--;
        if (choice < 0)
        {
            choice = 0;
        }
    }
    else if (ep.parameter2 < -0.5)
    {
        if (choice < 1)
        {
            choice++;
        }
    }
}

void LevelSelectionMenu::Update()
{
    OnEnable();
    ShowMenu();
    controls->ListenForControls();
}

void LevelSelectionMenu::ShowMenu()
{
    Game *g = (Game *)scenes->get(2);
    system("cls");
    cout << "------------------------------------------------------" << endl;
    // cout << "Sélectionner un niveau" << endl;
    cout << "-" << (g->currentLevel == 0 ? "O" : "-") << "- Niveau 1" << endl;
    // cout << "-" << (g->currentLevel == 1 ? "O" : "-") << "- Niveau 2" << endl;
    // cout << "-" << (g->currentLevel == 3 ? "O" : "-") << "- Niveau 3" << endl;
    cout << "-" << (g->currentLevel >= 1 ? "O" : "-") << "- Retour" << endl;
    cout << "------------------------------------------------------" << endl;
}

void LevelSelectionMenu::Selection()
{
    if (choice == 1)
    {
        SelectLevel(choice);
    }
    else
    {
        Back();
    }
}

void LevelSelectionMenu::SelectLevel(int Level)
{
    OnDisable();
    system("cls");
    if (Level == 1)
    {
        // sélectionner niveau 1
    }
    else if (Level == 2)
    {
        // sélectionner niveau 2
    }
}

void LevelSelectionMenu::Back()
{
    activeScene = lastMenu;
    OnDisable();
}