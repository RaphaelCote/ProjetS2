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
    }
    else if (ep.parameter2 < -0.5)
    {
        if (choice < 5)
        {
            choice++;
        }
    }

    ShowMenu();
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

    Sleep(50);

    // récupérer les qté et les prix dans inventaire, afficher l'argent
    string s0 = "------------------------------------------------------------------- ";
    string s1 = "BOUTIQUE ";
    string s2 = "-";
    s2 += (choice == 0 ? "O" : "-");
    s2 += "- Acheter une roquette : " + PRIXKROCKET;
    s2 += "$ ";
    string s3 = "-";
    s3 += (choice == 1 ? "O" : "-");
    s3 += "- Acheter une grenade : " + PRIXGRENADE;
    s3 += "$ ";
    string s4 = "-";
    s4 += (choice == 2 ? "O" : "-");
    s4 += "- Acheter 25 bouclier (max 50) : " + PRIXPETITSHIELD;
    s4 += "$ ";
    string s5 = "-";
    s5 += (choice == 3 ? "O" : "-");
    s5 += "- Acheter 50 bouclier (max 100) " + PRIXMOYENSHIELD;
    s5 += "$ ";
    string s6 = "-";
    s6 += (choice == 4 ? "O" : "-");
    s6 += "- Acheter 100 bouclier (max 100) : " + PRIXGROSSHIELD;
    s6 += "$ ";
    string s7 = "-";
    s7 += (choice == 5 ? "O" : "-");
    s7 += "- Retour ";
    string s8 = "------------------------------------------------------------------- ";
    string s9 = "INVENTAIRE";
    string s10 = "Argent : " + inventory->getGold();
    string s11 = "Roquettes : " + inventory->getRockets();
    string s12 = "Grenades : " + inventory->getGrenade();
    string s13 = "Bouclier : " + inventory->getShield();
    string s14 = "------------------------------------------------------------------- ";

    int y0 = ((cons->MaxRows) * 10) - 30;
    int y1 = ((cons->MaxRows) * 10) - 40;
    int y2 = ((cons->MaxRows) * 10) - 50;
    int y3 = ((cons->MaxRows) * 10) - 60;
    int y4 = ((cons->MaxRows) * 10) - 70;
    int y5 = ((cons->MaxRows) * 10) - 80;
    int y6 = ((cons->MaxRows) * 10) - 90;
    int y7 = ((cons->MaxRows) * 10) - 100;
    int y8 = ((cons->MaxRows) * 10) - 110;
    int y9 = ((cons->MaxRows) * 10) - 120;
    int y10 = ((cons->MaxRows) * 10) - 130;
    int y11 = ((cons->MaxRows) * 10) - 140;
    int y12 = ((cons->MaxRows) * 10) - 150;
    int y13 = ((cons->MaxRows) * 10) - 160;
    int y14 = ((cons->MaxRows) * 10) - 170;
    int x = 20;

    cons->AfficherTexte(std::cout, s0, x, y0, "s0");
    cons->AfficherTexte(std::cout, s1, x, y1, "s1");
    cons->AfficherTexte(std::cout, s2, x, y2, "s2");
    cons->AfficherTexte(std::cout, s3, x, y3, "s3");
    cons->AfficherTexte(std::cout, s4, x, y4, "s4");
    cons->AfficherTexte(std::cout, s5, x, y5, "s5");
    cons->AfficherTexte(std::cout, s6, x, y6, "s6");
    cons->AfficherTexte(std::cout, s6, x, y7, "s7");
    cons->AfficherTexte(std::cout, s6, x, y8, "s8");
    cons->AfficherTexte(std::cout, s6, x, y9, "s9");
    cons->AfficherTexte(std::cout, s6, x, y10, "s10");
    cons->AfficherTexte(std::cout, s6, x, y11, "s11");
    cons->AfficherTexte(std::cout, s6, x, y12, "s12");
    cons->AfficherTexte(std::cout, s6, x, y13, "s13");
    cons->AfficherTexte(std::cout, s6, x, y14, "s14");
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
        OnDisable();
        ClearMenu();
    }
    else if (choice == 1)
    {
        inventory->addGrenade();
        OnDisable();
        ClearMenu();
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