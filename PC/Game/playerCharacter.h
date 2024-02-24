//playerCharacter.h
#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include "character.h"
//#include "enemyCharacter.h"
#include "projectile.h"

#include <cmath>
#include <iostream> 
//const double g=-1000;
 #define VITESSEMAX 2000 
// la vitesse max dépend du projectile et non de la classe PlayerCharacter, il va falloir changer cela
#define PI 3.14159265358979323846
class PlayerCharacter : public Character{
    public:
        // int healtpoint;
        // Coordonnee position;   
        // Hitbox hitbox;
         //les mettre privée faire un getFunction idéalement et les initialiser dans le cons

        PlayerCharacter(int posx,int posy);
        
        
        ~PlayerCharacter();
       // bool didPlayerHit(float puissance,float angle, EnemyCharacter& enemy); 
        
        
        int findBulletPositionY(float puissance,float angledeg,int deltax);
        int findBulletPositionX(float puissance,float angledeg,int deltay);
        void playerShoot(Projectile* projectile);
        
        Coordonnee getWeaponPosition() override{
            return WeaponPosition;
        }
        void setWeaponPosition(Coordonnee WeaponPosition) override
        {
            this->WeaponPosition=WeaponPosition;
        }
        
        
        //peut-être a changer en "int" si raph le veux, forceX =  et force Y = velocité y
        float Aim(float angle) override;
    private:
        Coordonnee WeaponPosition;
        //float damageReceived(ProjectileType& projectile, int impactX, int impactY);
        float damageMultiplier(int impactY);
        Coordonnee hitEnemy;//les coordonnées ou l'ennmie est touché si il y a lieu
        //Coordonnee bulletPositionAt0;
        Coordonnee bulletPosition;//mettre "Coordonnee bulletEndPosition" dans projectile.h 
       
}; 
#endif