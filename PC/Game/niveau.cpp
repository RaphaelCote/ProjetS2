#include "niveau.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"

Niveau::Niveau()
{
    initializeBoats();
}

Niveau::~Niveau()
{
}

void Niveau::initializeBoats()
{
    characters.add(new PlayerCharacter(0, 100, 100, 100, 1));

    characters.add(new EnemyCharacter(2000, 100, 100, 100, 1));

    // playerBoats.add(new Boat());

    // enemyBoats.add(new Boat());
}

void Niveau::ShowCharacterInfo(ostream &s)
{
    for (int i = 0; i < characters.getSize(); i++)
    {
        if (i == 0)
        {
            s << "Joueur :" << endl;
        }
        else
        {
            s << "Ennemi " << i << " :" << endl;
        }
        characters[i]->ShowInfo();
    }

    // s << "Bateaux joueurs : " << endl;

    // for (int i = 0; i < playerBoats.getSize(); i++)
    // {
    //     s << "Bateau  " << i + 1 << " :" << endl;

    //     playerBoats[i]->ShowInfo(s);
    // }

    // s << "Bateaux enemies : " << endl;

    // for (int i = 0; i < enemyBoats.getSize(); i++)
    // {
    //     s << "Bateau  " << i + 1 << " :" << endl;

    //     enemyBoats[i]->ShowInfo(s);
    // }
}
