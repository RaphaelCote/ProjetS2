#include "LevelSelectionMenu.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "../Controls/keyboardControls.h"
#include "../Game/levelGetter.h"

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
        if (choice < levelGetter->nbLevel+1)
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
    cout << "------------------------------------------------------" << endl;
    cout << "Sélectionner un niveau" << endl;
    for (int i = 0; i < levelGetter->nbLevel; i++)
    {
        cout << (choice == i ? "O" : "-") << "- Niveau " << i << endl;
    }
    cout << "-" << (choice >= levelGetter->nbLevel ? "O" : "-") << "- Retour" << endl;
    cout << "------------------------------------------------------" << endl;
}

void LevelSelectionMenu::Selection()
{
    if (choice < levelGetter->nbLevel)
    {
        OnDisable();
        SelectLevel(choice);
    }
    else if (choice == levelGetter->nbLevel)
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
    game->currentLevel = level;
    activeScene = 1;
}

void LevelSelectionMenu::Back()
{
    choice = 0;
    activeScene = lastMenu;
}