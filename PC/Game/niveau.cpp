#include "niveau.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"

Niveau::Niveau()
{
    nbraft = 2;
    creerListeRaft();
}
Niveau::Niveau(int t)
{
    nbraft = t;
    creerListeRaft();
}

Niveau::~Niveau()
{
}

void Niveau::creerListeRaft()
{
    characters.add(new PlayerCharacter(0, 100));

    characters.add(new EnemyCharacter(2000, 100));
}
