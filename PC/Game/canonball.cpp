#include "canonball.h"
using namespace std;
int Canonball::damageReceived(Character& character){
    
    float dy=bulletEndPosition.y-character.getPosition().y;
    float Vf= sqrt( pow(V0*cos(rad),2) + pow(V0*sin(rad),2) +2*g*dy);
    int D=0;

    
    if (bulletEndPosition.y < character.getPosition().y + character.getHitboxHeight() / 3.0) 
    {
        D=30;  
        cout<<"Ennemi touché aux pieds!"<<endl;
    } 
    else if (bulletEndPosition.y  >= character.getPosition().y + character.getHitboxHeight() / 3.0 && bulletEndPosition.y < character.getPosition().y + character.getHitboxHeight()*2.0 / 3.0) 
    {
        D=50;  
        cout<<"Ennemi touché au corps!"<<endl;
    } 
    else if(bulletEndPosition.y >= character.getPosition().y + (character.getHitboxHeight()*2.0 / 3.0) && bulletEndPosition.y <= character.getPosition().y +character.getHitboxHeight())
    {
        D=80;  
        cout<<"Ennemi touché à la tête!"<<endl;
    }
    int directDamage= round(Vf/canonballMaxSpeed*D);
    
    character.setHealthPoint(character.getHealthPoint()-directDamage);
    if(character.getHealthPoint()<=0)
    {
        character.setHealthPoint(0);
    }
    cout << "L'ennemi a actuellement " <<character.getHealthPoint() << " points de vie. Il a été frappé à une vitesse de " << Vf << " pixels/s à la position:";
    return directDamage;
}