#include "rocket.h"
int Rocket::damageReceived(Character& character){
    float dy=bulletEndPosition.y-character.getPosition().y;
    float Vf= std::sqrt( std::pow(V0*std::cos(rad),2) + std::pow(V0*std::sin(rad),2) +2*g*dy);
    int D=0;

    //je vérifie avec ma première condition si je touche directement l'ennemie
    if(bulletEndPosition.x==character.getPosition().x ||bulletEndPosition.y==character.getPosition().y +character.getHitboxHeight())
    {
        //je touche donc l'ennemie directement
        //je vérifie a quelle endroit je touche l'ennemie 
        if (bulletEndPosition.y >= character.getPosition().y && bulletEndPosition.y < character.getPosition().y + character.getHitboxHeight() / 3.0) 
        {
            D=70;  
            //cout<<"Cible touche aux pieds!Elle a ete frappe a une vitesse de "<<V0<<"pixels/s à la position ("<<bulletEndPosition.x<<", "<<bulletEndPosition.y<<")"<<endl;
        } 
        else if (bulletEndPosition.y  >= character.getPosition().y + character.getHitboxHeight() / 3.0 && bulletEndPosition.y < character.getPosition().y + character.getHitboxHeight()*2.0 / 3.0) 
        {
            D=100;  
            //cout<<"Cible touche au corps! Elle a ete frappe a une vitesse de "<<V0<<"pixels/s à la position ("<<bulletEndPosition.x<<", "<<bulletEndPosition.y<<")"<<endl;
        } 
        else if(bulletEndPosition.y >= character.getPosition().y + (character.getHitboxHeight()*2.0 / 3.0) && bulletEndPosition.y <= character.getPosition().y +character.getHitboxHeight())
        {
            D=120;  
            //cout<<"Cible touche a la tete!. Elle a ete frappe a une vitesse de "<<V0<<"pixels/s à la position ("<<bulletEndPosition.x<<", "<<bulletEndPosition.y<<")"<<endl;
        }
    }
    
    int directDamage= std::round(Vf/rocketMaxSpeed*D);
    
    character.setHealthPoint(character.getHealthPoint()-directDamage);
    if(character.getHealthPoint()<=0)
    {
        character.setHealthPoint(0);
    }
    //cout<<"La cible a actuellement : "<<character.getHealthPoint()<<"Point de vie"<<endl;
    return directDamage;
}
int Rocket::getProjectileMaxSpeed()
{
    return rocketMaxSpeed;
}