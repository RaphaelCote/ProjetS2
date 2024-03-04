#include "canonball.h"
using namespace std;
int Canonball::damageReceived(Character& character){
    
    float dy=bulletEndPosition.y-character.getPosition().y;
    float Vf= sqrt( pow(V0*cos(rad),2) + pow(V0*sin(rad),2) +2*g*dy);
    int D=0;
    //je vérifie avec ma première condition si je touche directement l'ennemie
    if(bulletEndPosition.x==character.getPosition().x ||bulletEndPosition.y==character.getPosition().y +character.getHitboxHeight())
    {
        //je touche donc l'ennemie directement
        //je vérifie a quelle endroit je touche l'ennemie 
        if (bulletEndPosition.y >= character.getPosition().y && bulletEndPosition.y < character.getPosition().y + character.getHitboxHeight() / 3.0) 
        {
            D=30;  
            cout<<"Cible touche aux pieds!"<<endl;
        } 
        else if (bulletEndPosition.y  >= character.getPosition().y + character.getHitboxHeight() / 3.0 && bulletEndPosition.y < character.getPosition().y + character.getHitboxHeight()*2.0 / 3.0) 
        {
            D=50;  
            cout<<"Cible touche au corps!"<<endl;
        } 
        else if(bulletEndPosition.y >= character.getPosition().y + (character.getHitboxHeight()*2.0 / 3.0) && bulletEndPosition.y <= character.getPosition().y +character.getHitboxHeight())
        {
            D=80;  
            cout<<"Cible touche a la tete!"<<endl;
        }
    }
    
    int directDamage= round(Vf/canonballMaxSpeed*D);
    
    character.setHealthPoint(character.getHealthPoint()-directDamage);
    if(character.getHealthPoint()<=0)
    {
        character.setHealthPoint(0);
    }
    cout << "La cible a actuellement " <<character.getHealthPoint() << " points de vie. Il a ete frappe a une vitesse de " << Vf << " pixels/s a la position:";
    return directDamage;
}


int Canonball:: getProjectileMaxSpeed() 
{
    return canonballMaxSpeed;
}
