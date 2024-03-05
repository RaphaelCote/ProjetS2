#include "niveau.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"


Niveau::Niveau(int width,int height,int image)
{
    creerListeRaft();
    widthlevels=width;
    heightlevels=height;
    backimage=image; 

}

Niveau::~Niveau()
{
}


void Niveau::addRaft(int raftwidth, int raftheight,int corodoneeX,int corodoneeY,int imageraft, int capacite, int i){

boat[i] = new Boat(capacite, corodoneeX, corodoneeY, raftwidth, raftheight, imageraft);

}

/*void Niveau::ShowCharacterInfo()
{
    for (int i = 0; i < characters.getSize(); i++)
    {
        if (i == 0)
        {
            cout << "Joueur :" << endl;
        }
        else
        {
            cout << "Ennemi " << i << " :" << endl;
        }
        characters[i]->ShowInfo();
    }
}*/
