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

void OnLevelSelectionMenuBackCall(EventParameters)
{
    LevelSelectionMenu *menu = (LevelSelectionMenu *)scenes->get(activeScene);
    menu->Back();
    menu->OnDisable();
}

void LevelSelectionMenu::OnEnable()
{
    eventManager->on("MainAction", OnLevelSelectionMenuMainActionCall);
    eventManager->on("Joystick", OnLevelSelectionMenuJoystickCall);
    eventManager->on("Back", OnLevelSelectionMenuBackCall);
}

void LevelSelectionMenu::OnDisable()
{
    eventManager->off("MainAction", OnLevelSelectionMenuMainActionCall);
    eventManager->off("Joystick", OnLevelSelectionMenuJoystickCall);
    eventManager->off("Back", OnLevelSelectionMenuBackCall);
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
        if (choice < levelGetter->nbLevel + 1)
        {
            choice++;
        }
    }

    ShowMenu();
}

void LevelSelectionMenu::Update()
{
    if (doOnce)
    {
        OnEnable();
        ShowMenu();
        doOnce = false;
    }
}

void LevelSelectionMenu::ShowMenu()
{
    // ClearMenu();
    cons->SupprimerObjet("s0");
    cons->SupprimerObjet("s1");
    cons->SupprimerObjet("s2");
    cons->SupprimerObjet("s3");

    for (int i = 0; i < levelGetter->nbLevel; i++)
    {
        string key = "sl";
        key += i;

        cons->SupprimerObjet("sl");
    }

    Sleep(50);

    string s0 = "------------------------------------------------------------------- ";
    string s1 = "Selectionner un niveau";
    for (int i = 0; i < levelGetter->nbLevel; i++)
    {
        string sl = "-";
        sl += (choice == i ? "O" : "-");
        sl += "- Niveau ";
        sl += i + 1;

        string key = "sl";
        key += i;

        int y = cons->MaxRows - (5 + i);
        int x = 2;

        cons->AfficherTexte(std::cout, sl, &x, &y, key);
    }
    string s2 = "-";
    s2 += (choice >= levelGetter->nbLevel ? "O" : "-");
    s2 += "- Retour ";
    string s3 = "------------------------------------------------------------------- ";

    int y0 = cons->MaxRows - 3;
    int y1 = cons->MaxRows - 4;

    int y2 = cons->MaxRows - 5 + levelGetter->nbLevel;
    int y3 = cons->MaxRows - 6 + levelGetter->nbLevel;
    int x = 2;

    cons->AfficherTexte(std::cout, s0, &x, &y0, "s0");
    cons->AfficherTexte(std::cout, s1, &x, &y1, "s1");
    cons->AfficherTexte(std::cout, s2, &x, &y2, "s2");
    cons->AfficherTexte(std::cout, s3, &x, &y3, "s3");
}

void LevelSelectionMenu::ClearMenu()
{
    cons->SupprimerObjet("s0");
    cons->SupprimerObjet("s1");
    cons->SupprimerObjet("s2");
    cons->SupprimerObjet("s3");

    for (int i = 0; i < levelGetter->nbLevel; i++)
    {
        string key = "sl";
        key += i;

        cons->SupprimerObjet("sl");
    }
}

void LevelSelectionMenu::Selection()
{
    OnDisable();
    ClearMenu();

    if (choice < levelGetter->nbLevel)
    {
        SelectLevel(choice);
    }
    else if (choice == levelGetter->nbLevel)
    {
        Back();
    }
}

void LevelSelectionMenu::SelectLevel(int level)
{
    choice = 0;
    system("cls");
    Game *game = (Game *)scenes->get(1);
    game->SetLevelIndex(level);
    game->isNewLevel = true;
    activeScene = 1;
}

void LevelSelectionMenu::Back()
{
    choice = 0;
    activeScene = lastMenu;
}