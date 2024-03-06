#include "inventory.h"

Inventory::Inventory()
{
    nbRockets=0;
    nbGrenades=0;
    shield=0;
    gold=0;
}

int Inventory::getGold()
{
    return gold;
}
void Inventory::addGold(int Gold)
{
    this->gold+=Gold;
}
void Inventory::removeGold(int Gold)
{
    this->gold-=Gold;
}

int Inventory::getRockets()
{
    return nbRockets;
}
void Inventory::addRockets()
{
    if(getGold()>=PrixRocket)
    {
        if (getRockets() < 2)
        {
            nbRockets++;
            removeGold(PrixRocket);
        }
        else
        {
            cout << "-------------------------------------------------------------------" << endl;
            cout<<"Limite de rockets atteinte"<<endl;
            cout << "-------------------------------------------------------------------" << endl;
            system("pause");
        }
    }
    else
    {
        cout << "-------------------------------------------------------------------" << endl;
        cout<<"Fonds insuffisants"<<endl;
        cout << "-------------------------------------------------------------------" << endl;
        system("pause");
    }
    
}
void Inventory::removeRockets()
{
    nbRockets--;
}

int Inventory::getShield()
{
    return shield;
}
void Inventory::setShield(int Shield)
{
    this->shield=Shield;
}
void Inventory::addShield(int level)
{
    
    if(level==1)
    {
        if(getGold()>=PrixPetitShield)
        {
            if(getShield()<50)
            {
                removeGold(PrixPetitShield);
                shield += 25;
                if (getShield()>50)
                {
                    shield=50;
                }
            }
            else
            {
                cout << "-------------------------------------------------------------------" << endl;
                cout<<"Limite de petits shields atteinte"<<endl;  
                cout << "-------------------------------------------------------------------" << endl;
                system("pause");
            }
        }
        else{
            cout << "-------------------------------------------------------------------" << endl;
            cout<<"Fonds insuffisants"<<endl;
            cout << "-------------------------------------------------------------------" << endl;
            system("pause");
        }
        
       
    }
    if(level==2)
    {
        if(getGold()>=PrixMoyenShield)
        {
            if(getShield()<100)
            {
                removeGold(PrixMoyenShield);
                shield+=50;
                if (getShield()>100)
                {
                    shield=100;
                }
            }
            else
            {
                cout << "-------------------------------------------------------------------" << endl;
                cout<<"Limite de moyens shields atteinte"<<endl;  
                cout << "-------------------------------------------------------------------" << endl;
                system("pause");
            }
        }
        else
        {
            cout << "-------------------------------------------------------------------" << endl;
            cout<<"Fonds insuffisants"<<endl;
            cout << "-------------------------------------------------------------------" << endl;
            system("pause");
        }
        
        
    }
    if(level==3)
    {
        if(getShield()<100)
        {
            if(getGold()>=PrixGrosShield)
            {
                removeGold(500);
                shield=100;
            }
            else{
                cout << "-------------------------------------------------------------------" << endl;
                cout<<"Fonds insuffisants"<<endl;
                cout << "-------------------------------------------------------------------" << endl;
                system("pause");
            }
        }
        else{
            cout << "-------------------------------------------------------------------" << endl;
            cout<<"Limite de gros shields atteinte"<<endl;  
            cout << "-------------------------------------------------------------------" << endl;
            system("pause");
        }
        
    }
}

int Inventory::getGrenade()
{
   return nbGrenades; 
}
void Inventory::addGrenade()
{
    if(getGold()>=PrixGrenade)
    {
        if (getGrenade() < 2)
        {
            nbGrenades++;
            removeGold(PrixGrenade);
        }
        else
        {
            cout << "-------------------------------------------------------------------" << endl;
            cout<<"Limite de grenades atteinte"<<endl;
            cout << "-------------------------------------------------------------------" << endl;
            system("pause");
        }
    }
    else{
        cout << "-------------------------------------------------------------------" << endl;
        cout<<"Fonds insuffisants"<<endl;
        cout << "-------------------------------------------------------------------" << endl;
        system("pause");
    }
}
void Inventory::removeGrenade()
{
    nbGrenades--;
}
        
