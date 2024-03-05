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
    system("cls");
    // Boucler au travers des ficher de niveaux pour afficher les choix
    cout << "------------------------------------------------------" << endl;
    cout << "Selectionner un niveau" << endl;
    cout << "-" << (choice == 0 ? "O" : "-") << "- Niveau 1" << endl;
    // cout << "-" << (choice == 1 ? "O" : "-") << "- Niveau 2" << endl;
    // cout << "-" << (choice == 3 ? "O" : "-") << "- Niveau 3" << endl;
    cout << "-" << (choice >= 1 ? "O" : "-") << "- Retour" << endl;
    cout << "------------------------------------------------------" << endl;
}

void LevelSelectionMenu::Selection()
{
    if (choice == 0)
    {
        OnDisable();
        SelectLevel(choice);
    }
    else if (choice == 1)
    {
        OnDisable();
        Back();
    }
}

void LevelSelectionMenu::SelectLevel(int level)
{
    choice = 0;
    system("cls");
    Game *game = (Game *)scenes->get(1);
    game->currentLevel == level;
    activeScene = 1;
}

void LevelSelectionMenu::Back()
{
    choice = 0;
    activeScene = lastMenu;
}