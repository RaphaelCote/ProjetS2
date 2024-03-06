#include "shopMenu.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "../Game/inventory.h"

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

void ShopMenu::OnEnable()
{
    eventManager->on("MainAction", OnShopMainActionCall);
    eventManager->on("Joystick", OnShopJoystickCall);
}

void ShopMenu::OnDisable()
{
    eventManager->off("MainAction", OnShopMainActionCall);
    eventManager->off("Joystick", OnShopJoystickCall);
}

ShopMenu::ShopMenu()
{
}

void ShopMenu::changeSelection(EventParameters ep)
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
        if (choice < 5)
        {
            choice++;
        }
    }
}

void ShopMenu::Update()
{
    OnEnable();
    ShowMenu();
    controls->ListenForControls();
}

void ShopMenu::ShowMenu()
{
    system("cls");
    // récupérer les qté et les prix dans inventaire, afficher l'argent
    cout << "-------------------------------------------------------------------" << endl;
    cout << "BOUTIQUE" << endl;
    cout << "-" << (choice == 0 ? "O" : "-") << "- Acheter une roquette : " << PRIXKROCKET << "$" << endl;
    cout << "-" << (choice == 1 ? "O" : "-") << "- Acheter une grenade : " << PRIXGRENADE << "$" << endl;
    cout << "-" << (choice == 2 ? "O" : "-") << "- Acheter 25 bouclier (max 50) : " << PRIXPETITSHIELD << "$" << endl;
    cout << "-" << (choice == 3 ? "O" : "-") << "- Acheter 50 bouclier (max 100) : " << PRIXMOYENSHIELD << "$" << endl;
    cout << "-" << (choice == 4 ? "O" : "-") << "- Acheter 100 bouclier (max 100) : " << PRIXGROSSHIELD << "$" << endl;
    cout << "-" << (choice == 5 ? "O" : "-") << "- Retour" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "INVENTAIRE" << endl;
    cout << "Argent : " << inventory->getGold() << endl;
    cout << "Roquettes : " << inventory->getRockets() << endl;
    cout << "Grenades : " << inventory->getGrenade() << endl;
    cout << "Bouclier : " << inventory->getShield() << endl;
    cout << "-------------------------------------------------------------------" << endl;
}

void ShopMenu::Selection()
{
    // Vérifier si le joueur a assez d'argent
    if (choice == 0)
    {
        inventory->addRockets();
        OnDisable();
    }
    else if (choice == 1)
    {
        inventory->addGrenade();
        OnDisable();
    }

    else if (choice == 2)
    {
        inventory->addShield(1);
    }

    else if (choice == 3)
    {
        inventory->addShield(2);
    }

    else if (choice == 4)
    {
        inventory->addShield(3);
    }

    else if (choice == 5)
    {
        OnDisable();
        Back();
    }
}

void ShopMenu::Back()
{
    choice = 0;
    activeScene = lastMenu;
}