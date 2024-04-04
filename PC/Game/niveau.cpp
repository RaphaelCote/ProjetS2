#include "niveau.h"
#include "Boat.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"
#include "../Affichage/AffichageConsole.h"
#include "../raftWars.h"

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
    // cout << "hauteur niveau " << height << endl;
    // cout << "largeur niveau " << width << endl;
}

void Niveau::addRaftPlayer(int width, int height, Coordonnee position, int image, int capacite)
{
    playerBoats.add(new Boat(capacite, position, height, width, image));
}

void Niveau::addRaftenemy(int width, int height, Coordonnee position, int image, int capacite)
{
    enemyBoats.add(new Boat(capacite, position, height, width, image));
}

void Niveau::MatRaft()
{
    for (int i = 0; i < playerBoats.getSize(); ++i)
    {
        // Pixels couleur[(playerBoats[i]->getHeight())/10][(playerBoats[i]->getWidth())/10];
        Pixels **couleur = new Pixels *[(playerBoats[i]->getHeight()) / 10];
        for (int j = 0; j < (playerBoats[i]->getHeight()) / 10; ++j)
        {
            couleur[j] = new Pixels[playerBoats[i]->getWidth() / 10];
        }

        for (int j = 0; j < (playerBoats[i]->getHeight()) / 10; j++)
        {
            for (int n = 0; n < (playerBoats[i]->getWidth()) / 10; n++)
            {
                couleur[j][n].FrontColour = 6; // gold
                couleur[j][n].BackColour = 8;  // grey
                couleur[j][n].texture = '\xB1';
            }
        }

        cons->AjouterObjet(couleur, playerBoats[i], 0, "boat player " + i);
        //  for (int j = 0; j < (playerBoats[i]->getHeight())/10; ++j)
        //     {
        //         delete[] couleur[j];
        //     }
        //      delete[] couleur;
    }

    for (int i = 0; i < enemyBoats.getSize(); i++)
    {
        // Pixels couleur[(enemyBoats[i]->getHeight())/10][(enemyBoats[i]->getWidth())/10];
        Pixels **couleur = new Pixels *[(enemyBoats[i]->getHeight()) / 10];
        for (int j = 0; j < (enemyBoats[i]->getHeight()) / 10; ++j)
        {
            couleur[j] = new Pixels[enemyBoats[i]->getWidth() / 10];
        }

        for (int j = 0; j < (enemyBoats[i]->getHeight()) / 10; j++)
        {
            for (int n = 0; n < (enemyBoats[i]->getWidth()) / 10; n++)
            {
                couleur[j][n].FrontColour = 6; // gold
                couleur[j][n].BackColour = 8;  // grey
                couleur[j][n].texture = '\xB1';
            }
        }

        cons->AjouterObjet(couleur, enemyBoats[i], 0, "boat enemy " + i);

        // for (int j = 0; j < (enemyBoats[i]->getHeight()) / 10; ++j)
        // {
        //     delete[] couleur[j];
        // }
        // delete[] couleur;
    }
}

void Niveau::MatEnemy()
{
    // int c_heigth = playerBoats[v]->characters[v]->getHitboxHeight();
    // int c_width = playerBoats[v]->characters[v]->getHitboxWidth();
    int c_heigth = 10;
    int c_width = 10;

    char tab_test[10][10] = {{' ', ' ', ' ', '+', '+', '+', ' ', ' ', ' ', ' '},
                             {' ', ' ', '+', '+', '+', '+', '+', ' ', ' ', ' '},
                             {' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' '},
                             {' ', '<', '<', '<', '<', '<', '<', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' '},
                             {' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' '},
                             {' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' '}};

    Pixels **_enemy = new Pixels *[c_heigth];
    for (int i = 0; i < c_heigth; ++i)
    {
        _enemy[i] = new Pixels[c_width];
    }

    // passe a travers tout le tableau pour faire le personnage
    for (int i = 0; i < c_heigth; i++)
    {
        for (int n = 0; n < c_width; n++)
        {
            char val = tab_test[i][n]; // j'ai du mettre ca(c_heigth - i-1) sinon le bonhomme affiche en l'envers
            if (val == ' ')
            {
                _enemy[i][n].FrontColour = colors::transparant;
                _enemy[i][n].BackColour = colors::transparant;
                _enemy[i][n].texture = ' ';
            }
            else if (val == '*')
            {
                _enemy[i][n].FrontColour = colors::green;
                _enemy[i][n].BackColour = colors::leaf;
                _enemy[i][n].texture = ' ';
            }
            else if (val == '+')
            {
                _enemy[i][n].FrontColour = colors::black;
                _enemy[i][n].BackColour = colors::lightred;
                _enemy[i][n].texture = CHAR_CONTRAST_LOW;
            }
            else if (val == '<')
            {
                _enemy[i][n].FrontColour = colors::black;
                _enemy[i][n].BackColour = colors::red;
                _enemy[i][n].texture = CHAR_CONTRAST_MED;
            }
        }
    }

    for (int b = 0; b < enemyBoats.getSize(); b++)
    {
        for (int v = 0; v < enemyBoats[b]->getNbCharacters(); v++)
        {
            cons->AjouterObjet(_enemy, enemyBoats[b]->characters[v], 0, "enemy" + b + ',' + v);
        }
    }
}

void Niveau::MatWater()
{
    // Pixels **water = new Pixels*[10];
    // for (int i = 0; i < (10); ++i)
    // {
    //     water[i] = new Pixels[350];
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int n = 0; n < 350; n++)
    //     {
    //         water[i][n].FrontColour = colors::blue;
    //         water[i][n].BackColour = colors::aqua;
    //         water[i][n].texture = '\xB1';
    //     }
    // }
    // int coor_X_eau = 0;
    // int coor_Y_eau = 0;
    // cons->AjouterObjet(water, &coor_X_eau, &coor_Y_eau, 300, 4, 0, "eau");

    // for (int i = 0; i < height/10 ; ++i)
    //         {
    //             delete[]water[i];
    //         }
    //         delete[] water;

    Pixels **eau = new Pixels *[10];
    for (int i = 0; i < 10; ++i)
    {
        eau[i] = new Pixels[350];
    }

    for (int i = 0; i < 10; i++)
    {
        for (int n = 0; n < 350; n++)
        {
            eau[i][n].FrontColour = colors::aqua;
            eau[i][n].BackColour = colors::blue;
            eau[i][n].texture = '\xAB';
        }
    }

    int *coor_X3 = new int;
    *coor_X3 = 0;
    int *coor_Y3 = new int;
    *coor_Y3 = 0;
    cons->AjouterObjet(eau, coor_X3, coor_Y3, 300, 10, 0, "eau");
}

void Niveau::MatBalle(Projectile *Balle)
{
    // Pixels balle;
    Pixels **balle = new Pixels *[1];
    for (int i = 0; i < 1; ++i)
    {
        balle[i] = new Pixels[1];
    }
    balle[0][0].FrontColour = colors::aqua; // blue
    balle[0][0].BackColour = colors::aqua;
    balle[0][0].texture = ' ';

    cons->AjouterObjet(balle, Balle, 0, "projectile");
}

void Niveau::MatGrenade(Projectile *Grenade)
{
    // Pixels grenade;
    Pixels **grenade = new Pixels *[1];
    for (int i = 0; i < 1; ++i)
    {
        grenade[i] = new Pixels[1];
    }
    grenade[0][0].FrontColour = 14; // yellow
    grenade[0][0].BackColour = 14;
    grenade[0][0].texture = ' ';

    cons->AjouterObjet(grenade, Grenade, 0, "projectile");
}

void Niveau::MatNuage()
{
    int n_heigth = 4;
    int n_width = 9;

    int *coor_X = new int;
    int *coor_Y = new int;
    *coor_X = 550;
    *coor_Y = 550;

    char tab_test[4][9] = {{' ', ' ', ' ', '+', '+', '+', ' ', ' ', ' '},
                           {' ', '+', '+', '+', '+', '+', '+', '+', ' '},
                           {'+', '+', '+', '+', '+', '+', '+', '+', '+'},
                           {'+', '+', '+', '+', '+', '+', '+', '+', '+'}};

    Pixels **_nuage = new Pixels *[n_heigth];
    for (int i = 0; i < n_heigth; ++i)
    {
        _nuage[i] = new Pixels[n_width];
    }

    // passe a travers tout le tableau pour faire le personnage
    for (int i = 0; i < n_heigth; i++)
    {
        for (int n = 0; n < n_width; n++)
        {
            char val = tab_test[i][n]; // j'ai du mettre ca(c_heigth - i-1) sinon le bonhomme affiche en l'envers
            if (val == ' ')
            {
                _nuage[i][n].FrontColour = colors::transparant;
                _nuage[i][n].BackColour = colors::transparant;
                _nuage[i][n].texture = ' ';
            }
            else if (val == '+')
            {
                _nuage[i][n].FrontColour = colors::white;
                _nuage[i][n].BackColour = colors::white;
                _nuage[i][n].texture = CHAR_CONTRAST_LOW;
            }
        }
    }

    cons->AjouterObjet(_nuage, coor_X, coor_Y, n_width, n_heigth, 0, "nuage");

    return;
}

void Niveau::MatCharacter()
{
    // int c_heigth = playerBoats[v]->characters[v]->getHitboxHeight();
    // int c_width = playerBoats[v]->characters[v]->getHitboxWidth();
    int c_heigth = 10;
    int c_width = 10;

    char tab_test[10][10] = {{' ', ' ', ' ', '+', '+', '+', ' ', ' ', ' ', ' '},
                             {' ', ' ', '+', '+', '+', '+', '+', ' ', ' ', ' '},
                             {' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', '<', '<', '<', '<', '<', '<', ' ', ' '},
                             {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' '},
                             {' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' '},
                             {' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' '}};

    Pixels **_character = new Pixels *[c_heigth];
    for (int i = 0; i < c_heigth; ++i)
    {
        _character[i] = new Pixels[c_width];
    }

    // passe a travers tout le tableau pour faire le personnage
    for (int i = 0; i < c_heigth; i++)
    {
        for (int n = 0; n < c_width; n++)
        {
            char val = tab_test[i][n]; // j'ai du mettre ca(c_heigth - i-1) sinon le bonhomme affiche en l'envers
            if (val == ' ')
            {
                _character[i][n].FrontColour = colors::transparant;
                _character[i][n].BackColour = colors::transparant;
                _character[i][n].texture = ' ';
            }
            else if (val == '*')
            {
                _character[i][n].FrontColour = colors::green;
                _character[i][n].BackColour = colors::leaf;
                _character[i][n].texture = ' ';
            }
            else if (val == '+')
            {
                _character[i][n].FrontColour = colors::black;
                _character[i][n].BackColour = colors::lightblue;
                _character[i][n].texture = CHAR_CONTRAST_LOW;
            }
            else if (val == '<')
            {
                _character[i][n].FrontColour = colors::black;
                _character[i][n].BackColour = colors::red;
                _character[i][n].texture = CHAR_CONTRAST_MED;
            }
        }
    }

    for (int b = 0; b < playerBoats.getSize(); b++)
    {
        for (int v = 0; v < playerBoats[b]->getNbCharacters(); v++)
        {
            cons->AjouterObjet(_character, playerBoats[b]->characters[v], 0, "Char" + b + ',' + v);
        }
    }
}

void Niveau::MatRocket(Projectile *pro)
{
    int n_heigth = 3;
    int n_width = 7;

    char tab_test[4][9] = {{' ', '-', ' ', ' ', ' ', ' ', ' '},
                           {'?', '+', '+', '+', '+', '+', '*'},
                           {' ', '-', ' ', ' ', ' ', ' ', ' '}};

    Pixels **rocket = new Pixels *[n_heigth];
    for (int i = 0; i < n_heigth; ++i)
    {
        rocket[i] = new Pixels[n_width];
    }

    for (int i = 0; i < n_heigth; i++)
    {
        for (int n = 0; n < n_width; n++)
        {
            char val = tab_test[i][n];
            if (val == ' ')
            {
                rocket[i][n].FrontColour = colors::transparant;
                rocket[i][n].BackColour = colors::transparant;
                rocket[i][n].texture = ' ';
            }
            else if (val == '+')
            {
                rocket[i][n].FrontColour = colors::grey;
                rocket[i][n].BackColour = colors::grey;
                rocket[i][n].texture = ' ';
            }
            else if (val == '-')
            {
                rocket[i][n].FrontColour = colors::lightred;
                rocket[i][n].BackColour = colors::lightred;
                rocket[i][n].texture = ' ';
            }
            else if (val == '*')
            {
                rocket[i][n].FrontColour = colors::red;
                rocket[i][n].BackColour = colors::red;
                rocket[i][n].texture = ' ';
            }
            else if (val == '?')
            {
                rocket[i][n].FrontColour = colors::yellow;
                rocket[i][n].BackColour = colors::red;
                rocket[i][n].texture = ' ';
            }
        }
    }

    cons->AjouterObjet(rocket, pro, 0, "projectile");

    return;
}

void Niveau::Delete()
{
    // Delete de l'eau
    cons->SupprimerObjet("eau");

    // Delete du nuage
    cons->SupprimerObjet("nuage");

    // Delete des bateaux
    for (int i = 0; i < playerBoats.getSize(); i++)
    {
        cons->SupprimerObjet("boat player " + i);
    }

    for (int i = 0; i < enemyBoats.getSize(); i++)
    {
        cons->SupprimerObjet("boat enemy " + i);
    }

    // Delete des joueurs
    for (int b = 0; b < playerBoats.getSize(); b++)
    {
        for (int v = 0; v < playerBoats[b]->getNbCharacters(); v++)
        {
            cons->SupprimerObjet("Char" + b + ',' + v);
        }
    }

    // Delete des Enemies
    for (int b = 0; b < enemyBoats.getSize(); b++)
    {
        for (int v = 0; v < enemyBoats[b]->getNbCharacters(); v++)
        {
            cons->SupprimerObjet("enemy" + b + ',' + v);
        }
    }
}
void Niveau::ScanHitboxes(Projectile* projectile,bool player)
{
    if(player==true)//si c'est un joueur, on va seulement verifier les hitbox ennemie (bateau ennemi et ennemi)
    {
        for(int i=0;i<enemyBoats.getSize();i++)
        {
        
            for(int j=0;j<enemyBoats[i]->characters.getSize();j++)
            { 
                //CONFIRMATION QU'IL STOCK BELLE ET BIEN LES INFOS QUI SONT DANS CETTE BOUCLE, SOIT LES HITBOX DES PERSONNAGES
                //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
                cout<<"for pour les personnages dans le bateau ennemi"<<endl;
                //allHitboxObject.add(enemyBoats[i]->characters[j]->getHitbox());
                
                infoHitbox infotempPersonnage;
                infotempPersonnage.type =HitboxCharacter;
                infotempPersonnage.coordonnees = enemyBoats[i]->characters[j]->getPosition();
                infotempPersonnage.hitbox = enemyBoats[i]->characters[j]->getHitbox();
                
                
                projectile->AjouterInfoHitbox(infotempPersonnage);
            }
            //cout<<"je stock en theorie la hitbox du bateau ennemi"<<endl;
            infoHitbox infotempBateau;
            infotempBateau.type = HitboxBoat;
            infotempBateau.hitbox = enemyBoats[i]->getHitboxBoat();
            infotempBateau.coordonnees = enemyBoats[i]->getPositionBoat();
            projectile->AjouterInfoHitbox(infotempBateau);
        }
    }  
    else
    {
        for(int i=0;i<playerBoats.getSize();i++)
        {
        
            for(int j=0;j<playerBoats[i]->characters.getSize();j++)
            { 
                //CONFIRMATION QU'IL STOCK BELLE ET BIEN LES INFOS QUI SONT DANS CETTE BOUCLE, SOIT LES HITBOX DES PERSONNAGES
                //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
                cout<<"for pour les personnages dans le bateau player"<<endl;
                //allHitboxObject.add(playerBoats[i]->characters[j]->getHitbox());
                infoHitbox infotempPersonnage;
                infotempPersonnage.type = HitboxCharacter;
                infotempPersonnage.coordonnees = playerBoats[i]->characters[j]->getPosition();
                infotempPersonnage.hitbox = playerBoats[i]->characters[j]->getHitbox();
                
                projectile->AjouterInfoHitbox(infotempPersonnage);
            }
            cout<<"je stock en theorie la hitbox du bateau joueur"<<endl;
            infoHitbox infotempBateau;
            infotempBateau.type = HitboxBoat;
            infotempBateau.hitbox = playerBoats[i]->getHitboxBoat();
            infotempBateau.coordonnees = playerBoats[i]->getPositionBoat();
            projectile->AjouterInfoHitbox(infotempBateau);
        }
    }
    
}
