#include "level.h"
#include "Boat.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"
#include "projectile.h"

Level::Level()
{
}

Level::Level(int width, int height, int image)
{
    this->height = height;
    this->width = width;
    this->backimge = image;
}

Level::~Level()
{
}

void Level::ShowLevelInfo(ostream &s)
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

void Level::MatRaft()
{

    for (int i = 0; i < playerBoats.getSize(); i++)
    {
        // Pixels couleur[(playerBoats[i]->getHeight())/10][(playerBoats[i]->getWidth())/10];
        Pixels **couleur = new Pixels *[(playerBoats[i]->getHeight()) / 10];
        for (int i = 0; i < (playerBoats[i]->getHeight()) / 10; ++i)
        {
            couleur[i] = new Pixels[playerBoats[i]->getWidth() / 10];
        }

        for (int i = 0; i < (playerBoats[i]->getHeight()) / 10; i++)
        {
            for (int n = 0; n < (playerBoats[i]->getWidth()) / 10; n++)
            {
                couleur[i][n].FrontColour = 6; // gold
                couleur[i][n].BackColour = 8;  // grey
                couleur[i][n].texture = '\xB1';
            }
        }

        cons->AjouterObjet(couleur, playerBoats[i], 0, "boat player " + i);

        for (int i = 0; i < (playerBoats[i]->getHeight()) / 10; ++i)
        {
            delete[] couleur[i];
        }
        delete[] couleur;
    }

    for (int i = 0; i < enemyBoats.getSize(); i++)
    {
        // Pixels couleur[(enemyBoats[i]->getHeight())/10][(enemyBoats[i]->getWidth())/10];
        Pixels **couleur = new Pixels *[(enemyBoats[i]->getHeight()) / 10];
        for (int i = 0; i < (enemyBoats[i]->getHeight()) / 10; ++i)
        {
            couleur[i] = new Pixels[enemyBoats[i]->getWidth() / 10];
        }

        for (int i = 0; i < (enemyBoats[i]->getHeight()) / 10; i++)
        {
            for (int n = 0; n < (enemyBoats[i]->getWidth()) / 10; n++)
            {
                couleur[i][n].FrontColour = 6; // gold
                couleur[i][n].BackColour = 8;  // grey
                couleur[i][n].texture = '\xB1';
            }
        }

        cons->AjouterObjet(couleur, enemyBoats[i], 0, "boat enemy " + i);

        for (int i = 0; i < (enemyBoats[i]->getHeight()) / 10; ++i)
        {
            delete[] couleur[i];
        }
        delete[] couleur;
    }
}

void Level::MatPlayer()
{
    for (int v = 0; v < playerBoats.getSize(); v++)
    {
        for (int f = 0; f < playerBoats[v]->characters.getSize(); f++)
        {
            // Pixels MatCharacter[10][10];
            Pixels **MatCharacter = new Pixels *[10];
            for (int i = 0; i < 10; ++i)
            {
                MatCharacter[i] = new Pixels[10];
            }
            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {
                    MatCharacter[m][n].FrontColour = 16;
                    MatCharacter[m][n].BackColour = 16; // on remplie tt de transparent
                    MatCharacter[m][n].texture = ' ';
                }
            }

            for (int m = 0; m < 3; m++)
            {
                for (int n = 5; n < 8; n++)
                {
                    MatCharacter[m][n].FrontColour = 10;
                    MatCharacter[m][n].BackColour = 10; // green
                    MatCharacter[m][n].texture = ' ';
                }
            }
            MatCharacter[3][6].FrontColour = 10;
            MatCharacter[3][6].BackColour = 10; // green
            MatCharacter[3][6].texture = ' ';

            for (int i = 4; i < 6; i++)
            {
                for (int t = 5; t < 10; t++)
                {
                    MatCharacter[i][t].FrontColour = 0;
                    MatCharacter[i][t].BackColour = 4; // gun
                    MatCharacter[i][t].texture = '\xB1';
                }
            }

            MatCharacter[6][6].FrontColour = 10;
            MatCharacter[6][6].BackColour = 10;
            MatCharacter[6][6].texture = ' ';

            for (int i = 5; i < 8; i++)
            {
                MatCharacter[7][i].FrontColour = 10;
                MatCharacter[7][i].BackColour = 10;
                MatCharacter[7][i].texture = ' ';
            }
            for (int i = 8; i < 10; i++)
            {
                MatCharacter[i][4].FrontColour = 10;
                MatCharacter[i][4].BackColour = 10;
                MatCharacter[i][4].texture = ' ';
            }
            for (int i = 8; i < 10; i++)
            {
                MatCharacter[i][8].FrontColour = 10;
                MatCharacter[i][8].BackColour = 10;
                MatCharacter[i][8].texture = ' ';
            }

            cons->AjouterObjet(MatCharacter, playerBoats[v], 0, "player " + v);

            for (int i = 0; i < 10; ++i)
            {
                delete[] MatCharacter[i];
            }
            delete[] MatCharacter;
        }
    }
}

void Level::MatEnemy()
{
    for (int v = 0; v < enemyBoats.getSize(); v++)
    {
        for (int f = 0; f < enemyBoats[v]->characters.getSize(); f++)
        {
            // Pixels MatCharacter[10][10];
            Pixels **MatCharacter = new Pixels *[10];
            for (int i = 0; i < 10; ++i)
            {
                MatCharacter[i] = new Pixels[10];
            }

            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {
                    MatCharacter[m][n].FrontColour = 16;
                    MatCharacter[m][n].BackColour = 16; // on remplie tt de transparent
                    MatCharacter[m][n].texture = ' ';
                }
            }

            for (int m = 0; m < 3; m++)
            {
                for (int n = 2; n < 5; n++)
                {
                    MatCharacter[m][n].FrontColour = 10;
                    MatCharacter[m][n].BackColour = 10; // green
                    MatCharacter[m][n].texture = ' ';
                }
            }
            MatCharacter[3][3].FrontColour = 10;
            MatCharacter[3][3].BackColour = 10; // green
            MatCharacter[3][3].texture = ' ';

            for (int i = 4; i < 6; i++)
            {
                for (int t = 0; t < 5; t++)
                {
                    MatCharacter[i][t].FrontColour = 0;
                    MatCharacter[i][t].BackColour = 4; // gun
                    MatCharacter[i][t].texture = '\xB1';
                }
            }

            MatCharacter[6][3].FrontColour = 10;
            MatCharacter[6][3].BackColour = 10;
            MatCharacter[6][3].texture = ' ';

            for (int i = 2; i < 5; i++)
            {
                MatCharacter[7][i].FrontColour = 10;
                MatCharacter[7][i].BackColour = 10;
                MatCharacter[7][i].texture = ' ';
            }
            for (int i = 8; i < 10; i++)
            {
                MatCharacter[i][1].FrontColour = 10;
                MatCharacter[i][1].BackColour = 10;
                MatCharacter[i][1].texture = ' ';
            }
            for (int i = 8; i < 10; i++)
            {
                MatCharacter[i][5].FrontColour = 10;
                MatCharacter[i][5].BackColour = 10;
                MatCharacter[i][5].texture = ' ';
            }

            cons->AjouterObjet(MatCharacter, enemyBoats[v], 0, "enemy " + v);

            for (int i = 0; i < 10; ++i)
            {
                delete[] MatCharacter[i];
            }
            delete[] MatCharacter;
        }
    }
}

void Level::MatWater()
{
    // Pixels water[height/10][width/10];
    Pixels **water = new Pixels *[height / 10];
    for (int i = 0; i < (height / 10); ++i)
    {
        water[i] = new Pixels[width / 10];
    }
    for (int i = 0; i < (height / 10); i++)
    {
        for (int n = 0; n < (width / 10); n++)
        {
            water[i][n].FrontColour = 11;
            water[i][n].BackColour = 9;
            water[i][n].texture = '\xB0';
        }
    }

    cons->AjouterObjet(water, 0, 0, 250, 30000, 0, "water");

    for (int i = 0; i < height / 10; ++i)
    {
        delete[] water[i];
    }
    delete[] water;
}

void Level::MatBalle()
{
    // Pixels balle;
    Pixels **balle = new Pixels *[1];
    for (int i = 0; i < 1; ++i)
    {
        balle[i] = new Pixels[1];
    }
    balle[0][0].FrontColour = 15; // white
    balle[0][0].BackColour = 15;
    balle[0][0].texture = ' ';

    for (int i = 0; i < 1; ++i)
    {
        delete[] balle[i];
    }
    delete[] balle;
}

void Level::MatGrenade()
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

    for (int i = 0; i < 1; ++i)
    {
        delete[] grenade[i];
    }
    delete[] grenade;
}

void Level::MatRocket()
{
    Pixels **rocket = new Pixels *[4];
    for (int i = 0; i < 4; ++i)
    {
        rocket[i] = new Pixels[7];
    }
    for (int m = 0; m < 3; m++)
    {
        for (int n = 0; n < 6; n++)
        {
            rocket[m][n].FrontColour = 16;
            rocket[m][n].BackColour = 16; // transparent
            rocket[m][n].texture = ' ';
        }
    }
    rocket[1][0].FrontColour = 12;
    rocket[1][0].BackColour = 12; // lightred
    rocket[1][0].texture = ' ';

    rocket[0][1].FrontColour = 4;
    rocket[0][1].BackColour = 4; // red
    rocket[0][1].texture = ' ';

    rocket[2][1].FrontColour = 4;
    rocket[2][1].BackColour = 4; // red
    rocket[2][1].texture = ' ';

    rocket[1][5].FrontColour = 4;
    rocket[1][5].BackColour = 4; // red
    rocket[1][5].texture = ' ';

    for (int i = 1; i < 5; i++)
    {
        rocket[1][i].FrontColour = 7;
        rocket[1][i].BackColour = 7; // lightgrey
        rocket[1][i].texture = ' ';
    }

    for (int i = 0; i < 4; ++i)
    {
        delete[] rocket[i];
    }
    delete[] rocket;
}

void Level::MatNuage()
{
    // Pixels nuage[4][9];
    Pixels **nuage = new Pixels *[4];
    for (int i = 0; i < 4; ++i)
    {
        nuage[i] = new Pixels[9];
    }
    for (int m = 0; m < 4; m++)
    {
        for (int n = 0; n < 9; n++)
        {
            nuage[m][n].FrontColour = 16;
            nuage[m][n].BackColour = 16; // transparent
            nuage[m][n].texture = ' ';
        }
    }
    for (int i = 2; i < 4; i++)
    {
        for (int n = 0; n < 9; n++)
        {
            nuage[i][n].FrontColour = 15;
            nuage[i][n].BackColour = 15; // white
            nuage[i][n].texture = ' ';
        }
    }
    for (int i = 1; i < 9; i++)
    {
        nuage[1][i].FrontColour = 15;
        nuage[1][i].BackColour = 15;
        nuage[1][i].texture = ' ';
    }
    for (int i = 3; i < 7; i++)
    {
        nuage[0][i].FrontColour = 15;
        nuage[0][i].BackColour = 15;
        nuage[0][i].texture = ' ';
    }

    // cons->AjouterObjet(nuage,1500,300,4,9,0,"nuage1");

    for (int i = 0; i < 4; ++i)
    {
        delete[] nuage[i];
    }
    delete[] nuage;
}

/*
Pixels *couleur = new Pixels[10];
    for (int i = 0; i < 10; ++i) {
        couleur[i] = new Pixels[30];
    }

        for (int i = 0; i < 10; i++)
        {
            for (int n = 0; n < 30; n++)
            {
                couleur[i][n].FrontColour = 6;      //gold
                couleur[i][n].BackColour = 8;       //grey
                couleur[i][n].texture = '\xB1';
            }

        }
    cons->AfficherEnBasGauche(couleur, 10, 10, 10, 30);



    // Don't forget to deallocate memory
    for (int i = 0; i < rows; ++i) {
        delete[] myArray[i];
    }
    delete[] myArray;




    */
void Level::ShowLevelinfo()
{
    cout << "hauteur niveau " << height << endl;
    cout << "largeur niveau " << width << endl;
}

void Level::addRaftPlayer(int width, int height, Coordonnee position, int image, int capacite)
{
    playerBoats.add(new Boat(capacite, position, height, width, image));
}

void Level::addRaftenemy(int width, int height, Coordonnee position, int image, int capacite)
{
    enemyBoats.add(new Boat(capacite, position, height, width, image));
}
