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
        cout << "-" << (choix > 1 ? "O" : "-") << "- Acheter une protetion : 100$" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "INVENTAIRE" << endl;
        cout << "Roquettes :" << nbRoquettes << endl;
        cout << "Grenades :" << nbGrenades << endl;
        cout << "Armures :" << nbShield << endl;
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
            nbShield++;
            money = money-100;
       
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
