#include "rocket.h"
using namespace std;
int Rocket::damageReceived(Character& character){
    float dy=bulletEndPosition.y-character.getPosition().y;
    float Vf= sqrt( pow(V0*cos(rad),2) + pow(V0*sin(rad),2) +2*g*dy);
    int D=0;


    if (bulletEndPosition.y < 100 + character.getHitboxHeight() / 3.0) 
    {
        D=70;  
        cout<<"L'ennemi a été frappé au pied!"<<endl;
    } 
    else if (bulletEndPosition.y  >= character.getPosition().y + character.getHitboxHeight() / 3.0 && bulletEndPosition.y < character.getPosition().y + character.getHitboxHeight()*2.0 / 3.0) 
    {
        D=100;  
        cout<<"L'ennemi a été touché au corps!"<<endl;
    } 
    else if(bulletEndPosition.y >= character.getPosition().y + (character.getHitboxHeight()*2.0 / 3.0) && bulletEndPosition.y <= character.getPosition().y +character.getHitboxHeight())
    {
        D=120;  
        cout<<"L'ennemi a été touché à la tête!"<<endl;
    }
    int directDamage= round(Vf/rocketMaxSpeed*D);
    //if(character)
    character.setHealthPoint(character.getHealthPoint()-directDamage);
    if(character.getHealthPoint()<=0)
    {
        character.setHealthPoint(0);
    }
    cout << "L'ennemi a actuellement " <<character.getHealthPoint() << " points de vie. Il a été frappé à une vitesse de " << Vf << " pixels/s à la position:";
    return directDamage;
}