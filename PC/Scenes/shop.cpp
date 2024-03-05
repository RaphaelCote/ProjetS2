#include "shop.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"

void OnShopMainActionCall(EventParameters ep)
{
    Menu *menu = (Menu *)scenes->get(activeScene);
    menu->Selection();
}

void OnShopJoystickCall(EventParameters ep)
{
    Menu *menu = (Menu *)scenes->get(activeScene);
    menu->changeSelection(ep);
}

void shop::OnEnable()
{
    eventManager->on("MainAction", OnShopMainActionCall);
    eventManager->on("Joystick", OnShopJoystickCall);
}

void shop::OnDisable()
{
    eventManager->off("MainAction", OnShopMainActionCall);
    eventManager->off("Joystick", OnShopJoystickCall);
}

shop::shop()
{
}

void shop::changeSelection(EventParameters ep)
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
        if (choice < 4)
        {
            choice++;
        }
    }
}

void shop::Update()
{
    OnEnable();
    ShowMenu();
    controls->ListenForControls();
}

void shop::ShowMenu()
{
    system("cls");
    // récupérer les qté et les prix dans inventaire, afficher l'argent
    cout << "-------------------------------------------------------------------" << endl;
    cout << "BOUTIQUE" << endl;
    cout << "-" << (choice == 0 ? "O" : "-") << "- Acheter une roquette : 100$" << endl;
    cout << "-" << (choice == 1 ? "O" : "-") << "- Acheter une grenade : 150$" << endl;
    cout << "-" << (choice == 2 ? "O" : "-") << "- Acheter une petite armure : 100$" << endl;
    cout << "-" << (choice == 3 ? "O" : "-") << "- Acheter une moyenne armure : 250$" << endl;
    cout << "-" << (choice == 4 ? "O" : "-") << "- Acheter une grande armure : 500$" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "INVENTAIRE" << endl;
    cout << "Roquettes :" << nbRoquettes << endl;
    cout << "Grenades :" << nbGrenades << endl;
    cout << "Petites armures : " << nbLittleShield << endl;
    cout << "Moyennes armures : " << nbMidShield << endl;
    cout << "Grandes armures : " << nbBigShield << endl;
    cout << "-------------------------------------------------------------------" << endl;
}

void shop::Selection()
{
    // Vérifier si le joeur a assez d'argent
    if (choice == 0)
    {
        nbRoquettes++;
        money = money - 100;
        OnDisable();
    }
    else if (choice == 1)
    {
        nbGrenades++;
        money = money - 150;
        OnDisable();
    }
    else if (choice > 1)
    {
        int cost = 0;

        if (choice == 2)
        {
            nbLittleShield++;
            cost = 100;
        }
        else if (choice == 3)
        {
            nbMidShield++;
            cost = 250;
        }
        else if (choice == 4)
        {
            nbBigShield++;
            cost = 500;
        }

        money = money - cost;
    }
}