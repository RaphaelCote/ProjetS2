#include "niveau.h"
#include "Boat.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"

Niveau::Niveau()
{
}
Niveau::Niveau(int width, int height, int image)
{
    backimge = image;
    this->height = height;
    this->width = width;
}

Niveau::~Niveau()
{
}

void Niveau::ShowLevelInfo(ostream &s)
{
    s << "Bateaux joueurs : " << endl;

    for (int i = 0; i < playerBoats.getSize(); i++)
    {
        s << "Bateau  " << i + 1 << " :" << endl;

        playerBoats[i]->ShowInfo(s);
    }

    s << "Bateaux enemies : " << endl;

    for (int i = 0; i < enemyBoats.getSize(); i++)
    {
        s << "Bateau  " << i + 1 << " :" << endl;

        enemyBoats[i]->ShowInfo(s);
    }
}
void Niveau::ShowNiveauinfo()
{
    cout << "hauteur niveau " << heightlevels << endl;
    cout << "largeur niveau " << widthlevels << endl;
}
void Niveau::addRaftPlayer(int width, int height, Coordonnee position, int image, int capacite, int i)
{
    playerBoats[i] = new Boat(capacite, position, height, width, image);
}
void Niveau::addRaftenemy(int width, int height, Coordonnee position, int image, int capacite, int i)
{
    enemyBoats[i] = new Boat(capacite, position, height, width, image);
}