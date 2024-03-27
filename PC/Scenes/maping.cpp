#include "maping.h"

Maping::Maping(){}
Maping::~Maping(){}
void Maping::ScanHitboxes()
{
   
    
    //si erreur avec crochet appeler get dans vecteur.cpp
    cout<<"rentrer dans ScanHitboxes"<<endl;
    //-------------------bateaux ennemis----------------------//
    // for(int i=0;i<activelevel.enemyBoats.getSize();i++)
    // {
    //     cout<<"for pour les éléments dans le bateau ennemi"<<endl;
    //     for(int j=0;j<activelevel.enemyBoats[i]->characters.getSize();j++)
    //     { 
    //         //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
    //         cout<<"for pour chaque hitbox du bateau ennemi"<<endl;
    //         allHitboxObject.add(activelevel.enemyBoats[i]->characters[j]->getHitbox());
    //     }
    //     for(int j=0;j<activelevel.enemyBoats[i]->hitboxes.getSize();j++)
    //     { 
    //         cout<<"for pour les personnages dans le bateau ennemi"<<endl;  
    //         allHitboxObject.add(*activelevel.enemyBoats[i]->hitboxes[j]);
    //     }
    // }
    for(int j=0;j<activelevel.enemyBoats[0]->characters.getSize();j++)
    { 
        //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
        cout<<"for pour chaque hitbox du bateau ennemi"<<endl;
        allHitboxObject.add(activelevel.enemyBoats[0]->characters[j]->getHitbox());
    }
    for(int j=0;j<activelevel.enemyBoats[0]->hitboxes.getSize();j++)
    { 
        cout<<"for pour les personnages dans le bateau ennemi"<<endl;  
        allHitboxObject.add(*activelevel.enemyBoats[0]->hitboxes[j]);
    }
    //-------------------bateaux alliés----------------------//
    // for(int i=0;i<activelevel.playerBoats.getSize();i++)
    // {
    //     cout<<"for pour les éléments dans le bateau alliés"<<endl;
    //     for(int j=0;j<activelevel.playerBoats[i]->characters.getSize();j++)
    //     { 
    //         //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
    //         cout<<"for pour chaque hitbox du bateau alliés"<<endl;
    //         allHitboxObject.add(activelevel.playerBoats[i]->characters[j]->getHitbox());
    //     }
    //     //for pour les hitboxs du bateau aliée
    //     for(int j=0;j<activelevel.playerBoats[i]->hitboxes.getSize();j++)
    //     { 
    //         //on vérifie si la balle se retrouve entre les extremum en y de chaque surface verticale gauche de chaque hitbox du niveau
    //         //si oui, la vitesse en x est inversée (vers le gauche plutot que vers la droite) et réduite de 20
    //         allHitboxObject.add(*activelevel.playerBoats[i]->hitboxes[j]);
    //         cout<<"for pour les personnages dans le bateau alliés"<<endl; 
    //     }
        
    // }
    for(int j=0;j<activelevel.playerBoats[0]->characters.getSize();j++)
    { 
        //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
        cout<<"for pour chaque hitbox du bateau alliés"<<endl;
        allHitboxObject.add(activelevel.playerBoats[0]->characters[j]->getHitbox());
    }
    //for pour les hitboxs du bateau aliée
    for(int j=0;j<activelevel.playerBoats[0]->hitboxes.getSize();j++)
    { 
        //on vérifie si la balle se retrouve entre les extremum en y de chaque surface verticale gauche de chaque hitbox du niveau
        //si oui, la vitesse en x est inversée (vers le gauche plutot que vers la droite) et réduite de 20
        allHitboxObject.add(*activelevel.playerBoats[0]->hitboxes[j]);
        cout<<"for pour les personnages dans le bateau alliés"<<endl; 
    }
    
    //------------Sorted croissant de la position des hitbox (bubble sort)----------//

    for(int i =0; i<allHitboxObject.getSize()-1; i++)
    {
        cout<<"premiere for bubble"<<endl;
        for(int j=0; i< allHitboxObject.getSize()-i-1;j++)
        {
            cout<<"deuxieme for bubble"<<endl;
            if(allHitboxObject[j].coordonnees.x>allHitboxObject[j+1].coordonnees.x)
            {
                cout<<"if bubble"<<endl;
                //Coordonnee coordEnemy = niv->enemyBoats[i]->characters[j]->getPosition();
                Hitbox temporaire = allHitboxObject[j];
                allHitboxObject[j] = allHitboxObject[j+1];
                allHitboxObject[j+1] = temporaire; 
            }
        }
    }
        
}