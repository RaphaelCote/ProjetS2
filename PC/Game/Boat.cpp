#include "Boat.h"
#include "charachters.h"

Boat::Boat(int n)
{
    nbCharacters = 0;
    capacite = n;
}

int Boat::getNbCharacters()  // pour vérifier s'il reste des adversaires ou non
{
    return characters.getSize();
}

int Boat::getCapacite()
{
    return characters.getCapacity();
}

bool Boat::addCharacter(character* characterAdded) // pour initialiser le jeu: créer les personnages
{
    return characters.add(characterAdded);
}

bool Boat::addPosition(Coordonnee* positionAdded)
{
    return characterPositions.add(positionAdded);
}

bool Boat::removeCharacters(int index) // retirer les personnages lorsqu'ils sont morts
{
    return characters.remove(index);
}

bool Boat::removePosition(int index)
{
    return characterPositions.remove(index);
}

void Boat::affichageJoueur(ostream & s) // affichage pour les joueurs 
{
	s << "Il vous reste " << nbCharacters << " joueurs." << endl;
    
    if (nbCharacters == 0){
        s << "GAME OVER" << endl;
    }

    else{
        for (int i = 0; i < nbCharacters; i++){
            s << "La position du joueur " << i << " est " << characterPositions[i] << "." << endl;
        }
    }  
}

void Boat::affichageAdversaire(ostream & s) // affichage pour les joueurs
{
    s << "Il vous reste " << nbCharacters << "adversaires" << endl;
    
    if (nbCharacters == 0){
        s << "Bravo!!!" << endl;
    }

    else{
        s << "Essayer de nouveau" << endl;
    }
}

Boat::~Boat()
{
    nbCharacters = 0;
}