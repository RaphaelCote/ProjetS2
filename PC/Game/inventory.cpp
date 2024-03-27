#include "inventory.h"

Inventory::Inventory()
{
    nbRockets = 0;
    nbGrenades = 0;
    shield = 0;
    gold = 0;
}

int Inventory::GetPrixRocket()
{
    return PRIXROCKET;
}

int Inventory::GetPrixGrenade()
{
    return PRIXGRENADE;
}

int Inventory::GetPrixShieldSmall()
{
    return PRIXPETITSHIELD;
}

int Inventory::GetPrixShieldMedium()
{
    return PRIXMOYENSHIELD;
}

int Inventory::GetPrixShieldBig()
{
    return PRIXGROSSHIELD;
}

int Inventory::getGold()
{
    return gold;
}
void Inventory::addGold(int Gold)
{
    this->gold += Gold;
}
void Inventory::removeGold(int Gold)
{
    this->gold -= Gold;
}

int Inventory::getRockets()
{
    return nbRockets;
}
void Inventory::addRockets()
{
    if (getGold() >= PRIXROCKET)
    {
        if (getRockets() < 2)
        {
            nbRockets++;
            removeGold(PRIXROCKET);
        }
        else
        {
            // cout << "-------------------------------------------------------------------" << endl;
            // cout << "Limite de rockets atteinte" << endl;
            // cout << "-------------------------------------------------------------------" << endl;
            // system("pause");
        }
    }
    else
    {
        // cout << "-------------------------------------------------------------------" << endl;
        // cout << "Fonds insuffisants" << endl;
        // cout << "-------------------------------------------------------------------" << endl;
        // system("pause");
    }
}
void Inventory::removeRockets()
{
    if (nbRockets > 0)
    {
        nbRockets--;
    }
}

int Inventory::getShield()
{
    return shield;
}
void Inventory::setShield(int Shield)
{
    this->shield = Shield;
}
void Inventory::addShield(int level)
{

    if (level == 1)
    {
        if (getGold() >= PRIXPETITSHIELD)
        {
            if (getShield() < 50)
            {
                removeGold(PRIXPETITSHIELD);
                shield += 25;
                if (getShield() > 50)
                {
                    shield = 50;
                }
            }
            else
            {
                // cout << "-------------------------------------------------------------------" << endl;
                // cout << "Limite de bouclier atteinte" << endl;
                // cout << "-------------------------------------------------------------------" << endl;
                // system("pause");
            }
        }
        else
        {
            // cout << "-------------------------------------------------------------------" << endl;
            // cout << "Fonds insuffisants" << endl;
            // cout << "-------------------------------------------------------------------" << endl;
            // system("pause");
        }
    }
    if (level == 2)
    {
        if (getGold() >= PRIXMOYENSHIELD)
        {
            if (getShield() < 100)
            {
                removeGold(PRIXMOYENSHIELD);
                shield += 50;
                if (getShield() > 100)
                {
                    shield = 100;
                }
            }
            else
            {
                // cout << "-------------------------------------------------------------------" << endl;
                // cout << "Limite de bouclier atteinte" << endl;
                // cout << "-------------------------------------------------------------------" << endl;
                // system("pause");
            }
        }
        else
        {
            // cout << "-------------------------------------------------------------------" << endl;
            // cout << "Fonds insuffisants" << endl;
            // cout << "-------------------------------------------------------------------" << endl;
            // system("pause");
        }
    }
    if (level == 3)
    {
        if (getShield() < 100)
        {
            if (getGold() >= PRIXGROSSHIELD)
            {
                removeGold(PRIXGROSSHIELD);
                shield = 100;
            }
            else
            {
                // cout << "-------------------------------------------------------------------" << endl;
                // cout << "Fonds insuffisants" << endl;
                // cout << "-------------------------------------------------------------------" << endl;
                // system("pause");
            }
        }
        else
        {
            // cout << "-------------------------------------------------------------------" << endl;
            // cout << "Limite de bouclier atteinte" << endl;
            // cout << "-------------------------------------------------------------------" << endl;
            // system("pause");
        }
    }
}

int Inventory::getGrenade()
{
    return nbGrenades;
}
void Inventory::addGrenade()
{
    if (getGold() >= PRIXGRENADE)
    {
        if (getGrenade() < 2)
        {
            nbGrenades++;
            removeGold(PRIXGRENADE);
        }
        else
        {
            // cout << "-------------------------------------------------------------------" << endl;
            // cout << "Limite de grenades atteinte" << endl;
            // cout << "-------------------------------------------------------------------" << endl;
            // system("pause");
        }
    }
    else
    {
        // cout << "-------------------------------------------------------------------" << endl;
        // cout << "Fonds insuffisants" << endl;
        // cout << "-------------------------------------------------------------------" << endl;
        // system("pause");
    }
}
void Inventory::removeGrenade()
{
    if (nbGrenades > 0)
    {
        nbGrenades--;
    }
}
