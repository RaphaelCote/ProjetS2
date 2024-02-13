#include "Boat.h"
#include "charachters.h"

Boat::Boat(int n){
    nbCharacters = 0;
    capacite = n;
}

int Boat::getNbCharacters()  // pour vérifier s'il reste des adversaires ou non
{
    return nbCharacters;
}

int Boat::getCapacite(){
    return capacite;
}

bool Boat::addCharacter(charachters* characterAdded) // pour initialiser le jeu: créer les personnages
{
    if (characterAdded == NULL){
        return false;
    }

    else{
        characters[nbCharacters] = characterAdded;
        nbCharacters++;
        return true;
    }
}

charachters* Boat::removeCharacters(int index) // retirer les personnages lorsqu'ils sont morts
{
	if (index >= nbCharacters || index < 0){
		return nullptr;
	}

    else{
        charachters* characterRemoved = characters[index];
        if (index == (nbCharacters-1)){
            characters[nbCharacters-1] = NULL;
        }

        else{
            for (int i = index; i < (nbCharacters-1); i++){
                characters[i] = characters[i + 1];
            }
            characters[nbCharacters-1] = nullptr;
        }
        nbCharacters--;
        return characterRemoved;
    }
}

bool Boat::removePosition(int index){
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
    nbCharacters = 0;
}