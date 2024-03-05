#include "LevelSelectionMenu.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "../Controls/keyboardControls.h"

LevelSelectionMenu::LevelSelectionMenu()
{}

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

void LevelSelectionMenu::changeSelection(EventParameters ep) /*****/
{

}

void LevelSelectionMenu::ShowMenu() /****/
{
    Game *g = (Game *)scenes->get(2);
    system("cls");
    cout << "------------------------------------------------------" << endl;
    // cout << "Sélectionner un niveau" << endl;
    // cout << "-" << (g->currentLevel == 0 ? "O" : "-") << "- Niveau 1" << endl;
    // cout << "-" << (g->currentLevel == 1 ? "O" : "-") << "- Niveau 2" << endl;
    // cout << "-" << (g->currentLevel == 3 ? "O" : "-") << "- Niveau 3" << endl;
    // cout << "-" << (g->currentLevel >= 4 ? "O" : "-") << "- Retour" << endl;
    cout << "------------------------------------------------------" << endl;
}

void LevelSelectionMenu::Selection() /*****/
{
    OnDisable();
    SelectLevel(choice);
}

void LevelSelectionMenu::Update()
{
    OnDisable();
    ShowMenu();
    controls->ListenForControls();
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
    activeScene = lastMenu;
}