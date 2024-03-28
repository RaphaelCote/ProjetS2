#include "maping.h"
Maping::Maping(){}
Maping::~Maping(){}
Niveau* activeLevel;
void Maping::ScanHitboxes(Niveau *niveau)
{
   
    
    //si erreur avec crochet appeler get dans vecteur.cpp
    cout<<"rentrer dans ScanHitboxes"<<endl;
    //-------------------bateaux ennemis----------------------//
   
    for(int i=0;i<activeLevel->enemyBoats.getSize();i++)
    {
        Coordonnee bateau = activeLevel->enemyBoats[i]->getPositionBoat();
        cout<<"Coordonees du bateau ennemi "<<i<< " :(" <<bateau.x<<","<<bateau.y<<")"<<endl;
        cout<<"for pour les elements dans le bateau ennemi"<<endl;
        // for(int j=0;j<activeLevel->enemyBoats[i]->characters.getSize();j++)
        // { 
        //     //CONFIRMATION QU'IL STOCK BELLE ET BIEN LES INFOS QUI SONT DANS CETTE BOUCLE, SOIT LES HITBOX DES PERSONNAGES
        //     //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
        //     cout<<"for pour les personnages dans le bateau ennemi"<<endl;
        //     allHitboxObject.add(activeLevel->enemyBoats[i]->characters[j]->getHitbox());
        // }
        int a = activeLevel->enemyBoats[i]->hitboxes.getSize();
        cout<<"Voici la valeur de a : "<<a<<endl;
        for(int j=0;j<activeLevel->enemyBoats[i]->hitboxes.getSize();j++)
        { 
            cout<<"for pour chaque hitbox du bateau ennemi"<<endl;  
            allHitboxObject.add(activeLevel->enemyBoats[i]->hitboxes[j]);
            //ça ne fonctionne pas, RIEN n'est ajouté au vecteur 
        }
    }
    
    // for(int j=0;j<activeLevel->enemyBoats[0]->characters.getSize();j++)
    // { 
    //     //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
    //     cout<<"for pour chaque hitbox du bateau ennemi"<<endl;
    //     allHitboxObject.add(activeLevel->enemyBoats[0]->characters[j]->getHitbox());
    // }
    // for(int j=0;j<activeLevel->enemyBoats[0]->hitboxes.getSize();j++)
    // { 
    //     cout<<"for pour les personnages dans le bateau ennemi"<<endl;  
    //     allHitboxObject.add(*activeLevel->enemyBoats[0]->hitboxes[j]);
    // }
    //-------------------bateaux alliés----------------------//
    for(int i=0;i<activeLevel->playerBoats.getSize();i++)
    {
        cout<<"for pour les elements dans le bateau allies"<<endl;
        Coordonnee bateau = activeLevel->playerBoats[i]->getPositionBoat();
        cout<<"Coordonees du bateau alliee "<<i<< " :(" <<bateau.x<<","<<bateau.y<<")"<<endl;
        // for(int j=0;j<activeLevel->playerBoats[i]->characters.getSize();j++)
        // { 
        //     //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
        //     //CONFIRMATION QU'IL STOCK BELLE ET BIEN LES INFOS QUI SONT DANS CETTE BOUCLE, SOIT LES HITBOX DES PERSONNAGES
        //     cout<<"for pour les personnages dans le bateau allies"<<endl; 
        //     allHitboxObject.add(activeLevel->playerBoats[i]->characters[j]->getHitbox());
        // }
        //for pour les hitboxs du bateau aliée
        for(int j=0;j<activeLevel->playerBoats[i]->hitboxes.getSize();j++)
        { 
            
            //ça ne fonctionne pas, RIEN n'est ajouté au vecteur 
            allHitboxObject.add(activeLevel->playerBoats[i]->hitboxes[j]);
            cout<<"for pour chaque hitbox du bateau allies"<<endl;
        }
        
    }

    // int size = activeLevel->playerBoats[0]->characters.getSize();
    // for(int j=0;j<activeLevel->playerBoats[0]->characters.getSize();j++)
    // { 
    //     //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
    //     cout<<"for pour chaque hitbox du bateau alliés"<<endl;
    //     allHitboxObject.add(activeLevel->playerBoats[0]->characters[j]->getHitbox());
    // }
    // //for pour les hitboxs du bateau aliée
    // for(int j=0;j<activeLevel->playerBoats[0]->hitboxes.getSize();j++)
    // { 
    //     //on vérifie si la balle se retrouve entre les extremum en y de chaque surface verticale gauche de chaque hitbox du niveau
    //     //si oui, la vitesse en x est inversée (vers le gauche plutot que vers la droite) et réduite de 20
    //     allHitboxObject.add(*activeLevel->playerBoats[0]->hitboxes[j]);
    //     cout<<"for pour les personnages dans le bateau alliés"<<endl; 
    // }
    
    //------------Sorted croissant de la position des hitbox (bubble sort)----------//

    for(int i =0; i<allHitboxObject.getSize()-1; i++)
    {
        cout<<"premiere for bubble"<<endl;
        for(int j=0; j< allHitboxObject.getSize()-i-1;j++)
        {
            cout<<"deuxieme for bubble"<<endl;
            if(allHitboxObject[j]->coordonnees.x >allHitboxObject[j+1]->coordonnees.x)
            {
                cout<<"if bubble"<<endl;
                //Coordonnee coordEnemy = niv->enemyBoats[i]->characters[j]->getPosition();
                Hitbox* temporaire = allHitboxObject[j];
                allHitboxObject[j] = allHitboxObject[j+1];
                allHitboxObject[j+1] = temporaire; 
            }
        }
    }
    for(int i=0;i<allHitboxObject.getSize();i++)
    {
        cout<<"voici les coordonnees du "<< i<< "élément de allHitboxObject : ("<<allHitboxObject[i]->coordonnees.x<<", "<<allHitboxObject[i]->coordonnees.y<<")"<<endl;
        cout<<"voici les dimensions du "<< i<< "élément de allHitboxObject (largeur, longeur) : ("<<allHitboxObject[i]->width<<", "<<allHitboxObject[i]->height<<")"<<endl;
    }
        
}