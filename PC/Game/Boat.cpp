#include "Boat.h"

Boat::Boat(int n){
    nbCharacters = 0;
    capacite = n;
    boat = new character* [capacite];
}

int Boat::getNbCharacters()  // pour vérifier s'il reste des adversaires ou non
{
    return nbCharacters;
}

int Boat::getCapacite(){
    return capacite;
}

bool Boat::addCharacter(Characters* characterAdded) // pour initialiser le jeu: créer les personnages
{
    if (characterAdded == NULL){
        return false;
    }

    else{
        boat[nbCharacters] = characterAdded;
        nbCharacters++;
        return true;
    }
}

Characters* Boat::removeCharacter(int index) // retirer les personnages lorsqu'ils sont morts
{
	if (index >= nbCharacters || index < 0){
		return nullptr;
	}

    else{
        Characters* characterRemoved = boat[index];
        if (index == (nbCharacters-1)){
            boat[nbCharacters-1] = NULL;
        }

        else{
            for (int i = index; i < (nbCharacters-1); i++){
                boat[i] = bat[i + 1];
            }
            boat[nbCharacters-1] = nullptr;
        }
        nbCharacters--;
        return characterRemoved;
    }
}

/*POINTEUR DU PERSONNAGE RETIRÉ*/ Boat::removePosition(int index){
    /*list<Vector*> characterPositions;
    list<Characters*> characters;
    removePosition(int index);
    */
}

void Boat::affichageJoueur(ostream & s) // affichage pour les joueurs 
{
	s << "Il vous reste " << nbCharacters << " joueurs." << endl;
    
    if (nbCharacters == 0){
        s << "GAME OVER" << endl;
    }

    else{
        for (int i = 0; i < nbCharacters; i++){
            s << "La position du joueur " << i << " est " << POSITION[i] << "." << endl;
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

Boat::~Boat(){
    taille = 0;
    delete [] boat;
}