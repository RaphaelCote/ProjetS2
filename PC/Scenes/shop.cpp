#include "shop.h"

shop::shop()
{
}

void shop::changeSelection(EventParameters ep)
{
}

void shop::menuController(int menu)
{
}

void shop::afficherShop()
{
     system("cls");
        //lastActiveMenu = 1;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "BOUTIQUE" << endl;
        cout << "-" << (choix == 0 ? "O" : "-") << "- Acheter une roquette : 100$" << endl;
        cout << "-" << (choix == 1 ? "O" : "-") << "- Acheter une grenade : 150$" << endl;
        cout << "-" << (choix == 2 ? "O" : "-") << "- Acheter une petite armure : 100$" << endl;
        cout << "-" << (choix == 3 ? "O" : "-") << "- Acheter une moyenne armure : 250$" << endl;
        cout << "-" << (choix == 4 ? "O" : "-") << "- Acheter une grande armure : 500$" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "INVENTAIRE" << endl;
        cout << "Roquettes :" << nbRoquettes << endl;
        cout << "Grenades :" << nbGrenades << endl;
        cout << "Petites armures : " << nbLittleShield << endl;
        cout << "Moyennes armures : " << nbMidShield << endl;
        cout << "Grandes armures : " << nbBigShield << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Veuillez entrer votre selection :";
        cin >> choix;
}

void shop::selectionShop()
{
    if (choix == 0)
    {
        nbRoquettes++;
        money = money - 100;
        OnDisable();
    }
    else if (choix == 1)
    {
        nbGrenades++;
        money = money - 150;
        OnDisable();
    }
    else if (choix > 1)
    {
        int cost = 0;

        
        if (choix == 2)
        {
            nbLittleShield++;
            cost = 100;
        }
        else if (choix == 3)
        {
            nbMidShield++;
            cost = 250;
        }
        else if (choix == 4)
        {
            nbBigShield++;
            cost = 500;
        }

        money = money - cost;
    }
}

void shop::afficherInventaire()
{
}

void OnShopActionCall(EventParameters)
{
}

void OnShopJoystickCall(EventParameters)
{
}
