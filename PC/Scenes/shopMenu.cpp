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

void OnShopBackCall(EventParameters)
{
    ShopMenu *menu = (ShopMenu *)scenes->get(activeScene);
    menu->Back();
    menu->OnDisable();
}

void ShopMenu::OnEnable()
{
    eventManager->on("MainAction", OnShopMainActionCall);
    eventManager->on("Joystick", OnShopJoystickCall);
    eventManager->on("Back", OnShopBackCall);
}

void ShopMenu::OnDisable()
{
    eventManager->off("MainAction", OnShopMainActionCall);
    eventManager->off("Joystick", OnShopJoystickCall);
    eventManager->off("Back", OnShopBackCall);
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
        ShowMenu();
    }
    else if (ep.parameter2 < -0.5)
    {
        if (choice < 5)
        {
            choice++;
        }
        ShowMenu();
    }
}

void ShopMenu::Update()
{
    if (doOnce)
    {
        OnEnable();
        ShowMenu();
        doOnce = false;
    }
}

void ShopMenu::ShowMenu()
{
    // ClearMenu();
    cons->SupprimerObjet("s0");
    cons->SupprimerObjet("s1");
    cons->SupprimerObjet("s2");
    cons->SupprimerObjet("s3");
    cons->SupprimerObjet("s4");
    cons->SupprimerObjet("s5");
    cons->SupprimerObjet("s6");
    cons->SupprimerObjet("s7");
    cons->SupprimerObjet("s8");
    cons->SupprimerObjet("s9");
    cons->SupprimerObjet("s10");
    cons->SupprimerObjet("s11");
    cons->SupprimerObjet("s12");
    cons->SupprimerObjet("s13");
    cons->SupprimerObjet("s14");

    Sleep(10);

    // récupérer les qté et les prix dans inventaire, afficher l'argent
    string s0 = "------------------------------------------------------------------- ";
    string s1 = "BOUTIQUE ";
    string s2 = "-";
    s2 += (choice == 0 ? "O" : "-");
    s2 += "- Acheter une roquette : ";
    s2 += to_string(inventory->GetPrixRocket());
    s2 += "$ ";
    string s3 = "-";
    s3 += (choice == 1 ? "O" : "-");
    s3 += "- Acheter une grenade : ";
    s3 += to_string(inventory->GetPrixGrenade());
    s3 += "$ ";
    string s4 = "-";
    s4 += (choice == 2 ? "O" : "-");
    s4 += "- Acheter 25 bouclier (max 50) : ";
    s4 += to_string(inventory->GetPrixShieldSmall());
    s4 += "$ ";
    string s5 = "-";
    s5 += (choice == 3 ? "O" : "-");
    s5 += "- Acheter 50 bouclier (max 100) ";
    s5 += to_string(inventory->GetPrixShieldMedium());
    s5 += "$ ";
    string s6 = "-";
    s6 += (choice == 4 ? "O" : "-");
    s6 += "- Acheter 100 bouclier (max 100) : ";
    s6 += to_string(inventory->GetPrixShieldBig());
    s6 += "$ ";
    string s7 = "-";
    s7 += (choice == 5 ? "O" : "-");
    s7 += "- Retour ";
    string s8 = "------------------------------------------------------------------- ";
    string s9 = "INVENTAIRE";
    string s10 = "Argent : ";
    s10 += to_string(inventory->getGold());
    string s11 = "Roquettes : ";
    s11 += to_string(inventory->getRockets());
    string s12 = "Grenades : ";
    s12 += to_string(inventory->getGrenade());
    string s13 = "Bouclier : ";
    s13 += to_string(inventory->getShield());
    string s14 = "------------------------------------------------------------------- ";

    cons->AfficherTexte(std::cout, s0, 20, ((cons->MaxRows) * 10) - 30, "s0");
    cons->AfficherTexte(std::cout, s1, 20, ((cons->MaxRows) * 10) - 40, "s1");
    cons->AfficherTexte(std::cout, s2, 20, ((cons->MaxRows) * 10) - 50, "s2");
    cons->AfficherTexte(std::cout, s3, 20, ((cons->MaxRows) * 10) - 60, "s3");
    cons->AfficherTexte(std::cout, s4, 20, ((cons->MaxRows) * 10) - 70, "s4");
    cons->AfficherTexte(std::cout, s5, 20, ((cons->MaxRows) * 10) - 80, "s5");
    cons->AfficherTexte(std::cout, s6, 20, ((cons->MaxRows) * 10) - 90, "s6");
    cons->AfficherTexte(std::cout, s7, 20, ((cons->MaxRows) * 10) - 100, "s7");
    cons->AfficherTexte(std::cout, s8, 20, ((cons->MaxRows) * 10) - 110, "s8");
    cons->AfficherTexte(std::cout, s9, 20, ((cons->MaxRows) * 10) - 120, "s9");
    cons->AfficherTexte(std::cout, s10, 20, ((cons->MaxRows) * 10) - 130, "s10");
    cons->AfficherTexte(std::cout, s11, 20, ((cons->MaxRows) * 10) - 140, "s11");
    cons->AfficherTexte(std::cout, s12, 20, ((cons->MaxRows) * 10) - 150, "s12");
    cons->AfficherTexte(std::cout, s13, 20, ((cons->MaxRows) * 10) - 160, "s13");
    cons->AfficherTexte(std::cout, s14, 20, ((cons->MaxRows) * 10) - 170, "s14");
}

void ShopMenu::ClearMenu()
{
    cons->SupprimerObjet("s0");
    cons->SupprimerObjet("s1");
    cons->SupprimerObjet("s2");
    cons->SupprimerObjet("s3");
    cons->SupprimerObjet("s4");
    cons->SupprimerObjet("s5");
    cons->SupprimerObjet("s6");
    cons->SupprimerObjet("s7");
    cons->SupprimerObjet("s8");
    cons->SupprimerObjet("s9");
    cons->SupprimerObjet("s10");
    cons->SupprimerObjet("s11");
    cons->SupprimerObjet("s12");
    cons->SupprimerObjet("s13");
    cons->SupprimerObjet("s14");
}

void ShopMenu::Selection()
{
    // Vérifier si le joueur a assez d'argent
    if (choice == 0)
    {
        inventory->addRockets();
        ShowMenu();
    }
    else if (choice == 1)
    {
        inventory->addGrenade();
        ShowMenu();
    }
    else if (choice == 2)
    {
        inventory->addShield(1);
        ShowMenu();
    }
    else if (choice == 3)
    {
        inventory->addShield(2);
        ShowMenu();
    }
    else if (choice == 4)
    {
        inventory->addShield(3);
        ShowMenu();
    }
    else if (choice == 5)
    {
        doOnce = true;
        OnDisable();
        ClearMenu();
        Back();
    }
}

void ShopMenu::Back()
{
    choice = 0;
    activeScene = lastMenu;
}