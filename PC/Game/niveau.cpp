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
    cout << "hauteur niveau " << height << endl;
    cout << "largeur niveau " << width << endl;
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

void Niveau::MatPlayer()
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

            int PosX = playerBoats[v]->characters[f]->getPosition().x;
            int PosY = playerBoats[v]->characters[f]->getPosition().y;

        //  cons->AjouterObjet(MatCharacter, playerBoats[v], 0, "player " + v);
            cons->AjouterObjet(MatCharacter, &PosX, &PosY , playerBoats[v]->characters[f]->getHitboxWidth(), playerBoats[v]->characters[f]->getHitboxHeight(), 0, "player " + v);
//    cons->AjouterObjet(_character, &coor_X4, &coor_Y4, c_width, c_heigth,0, "Char1");
//    cons->AjouterObjet(_character, &c, 0, "Char2");


            // for (int i = 0; i < 10; ++i)
            // {
            //     delete[] MatCharacter[i];
            // }
            // delete[] MatCharacter;
        }
    }
}

void Niveau::MatEnemy()
{
    // int c_heigth = playerBoats[v]->characters[v]->getHitboxHeight();
    // int c_width = playerBoats[v]->characters[v]->getHitboxWidth();
    int c_heigth = 10;
    int c_width = 10;

    char tab_test[10][10] = {{' ',' ',' ','+','+','+',' ',' ',' ',' '},
                                {' ',' ','+','+','+','+','+',' ',' ',' '},
                                {' ',' ',' ','*','*','*',' ',' ',' ',' '},
                                {' ',' ',' ',' ','*',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ','*',' ',' ',' ',' ',' '},
                                {' ',' ','<','<','<','<','<','<',' ',' '},
                                {' ',' ',' ',' ','*',' ',' ',' ',' ',' '},
                                {' ',' ',' ','*',' ','*',' ',' ',' ',' '},
                                {' ',' ','*',' ',' ',' ','*',' ',' ',' '},
                                {' ','*',' ',' ',' ',' ',' ','*',' ',' '}} ;


    Pixels **_enemy = new Pixels*[c_heigth];
    for (int i = 0; i < c_heigth; ++i) {
        _enemy[i] = new Pixels[c_width];
    }

    //passe a travers tout le tableau pour faire le personnage
    for (int i = 0; i < c_heigth; i++)
    {
        for (int n = 0; n < c_width; n++)
        {
            char val = tab_test[i][n];      //j'ai du mettre ca(c_heigth - i-1) sinon le bonhomme affiche en l'envers
            if(val == ' ')
            {
                _enemy[i][n].FrontColour = colors::transparant;      
                _enemy[i][n].BackColour = colors::transparant;       
                _enemy[i][n].texture = ' ';
            }
            else if(val == '*')
            {
                _enemy[i][n].FrontColour = colors::green;      
                _enemy[i][n].BackColour = colors::leaf;       
                _enemy[i][n].texture = ' ';
            }
            else if(val == '+')
            {
                _enemy[i][n].FrontColour = colors::black;      
                _enemy[i][n].BackColour = colors::lightblue;       
                _enemy[i][n].texture = CHAR_CONTRAST_LOW;
            }
            else if(val == '<')
            {
                _enemy[i][n].FrontColour = colors::black;      
                _enemy[i][n].BackColour = colors::red;       
                _enemy[i][n].texture = CHAR_CONTRAST_MED;
            }   
        }
    }

    for ( int b = 0; b < enemyBoats.getSize(); b++)
    {
        for (int v = 0; v < enemyBoats[b]->getNbCharacters(); v++)
        {
            cons->AjouterObjet(_enemy, enemyBoats[b]->characters[v], 0, "enemy"+b + ','+v);
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



     Pixels **eau = new Pixels*[10];
   for (int i = 0; i < 10; ++i) {
      eau[i] = new Pixels[350];
   }

   for (int i = 0; i < 10; i++)
   {
      for (int n = 0; n < 350; n++)
      {
         eau[i][n].FrontColour = colors::blue;     
         eau[i][n].BackColour = colors::aqua;      
         eau[i][n].texture = '\xB1';
      }
   }

   int *coor_X3 = new int;
   *coor_X3 = 0;
   int *coor_Y3 = new int;
   *coor_Y3 = 0;
   cons->AjouterObjet(eau, coor_X3, coor_Y3, 300, 4, 0, "eau");

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

    cons->AjouterObjet(balle, Balle, 0, "balle");
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

    cons->AjouterObjet(grenade, Grenade, 0, "grenade");
}


void Niveau::MatNuage()
{
    int n_heigth = 4;
    int n_width = 9;

    int *coor_X = new int;
    int *coor_Y = new int;
    *coor_X = 450;
    *coor_Y = 250;

    char tab_test[4][9] = { {' ',' ',' ','+','+','+',' ',' ',' '},
                            {' ','+','+','+','+','+','+','+',' '},
                            {'+','+','+','+','+','+','+','+','+'},
                            {'+','+','+','+','+','+','+','+','+'}};


    Pixels **_nuage = new Pixels*[n_heigth];
    for (int i = 0; i < n_heigth; ++i) {
        _nuage[i] = new Pixels[n_width];
    }

    //passe a travers tout le tableau pour faire le personnage
    for (int i = 0; i < n_heigth; i++)
    {
        for (int n = 0; n < n_width; n++)
        {
            char val = tab_test[i][n];      //j'ai du mettre ca(c_heigth - i-1) sinon le bonhomme affiche en l'envers
            if(val == ' ')
            {
                _nuage[i][n].FrontColour = colors::transparant;      
                _nuage[i][n].BackColour = colors::transparant;       
                _nuage[i][n].texture = ' ';
            }
            else if(val == '+')
            {
                _nuage[i][n].FrontColour = colors::white;      
                _nuage[i][n].BackColour = colors::white;       
                _nuage[i][n].texture = CHAR_CONTRAST_LOW;
            }
        }
    }
    
    cons->AjouterObjet(_nuage, coor_X,coor_Y, n_width, n_heigth,0, "nuage");
      
    return;
    //////////////////////////////////////////////////
    // // Pixels nuage[4][9];
    // Pixels **nuage = new Pixels *[4];
    // for (int i = 0; i < 4; ++i)
    // {
    //     nuage[i] = new Pixels[9];
    // }
    // for (int m = 0; m < 4; m++)
    // {
    //     for (int n = 0; n < 9; n++)
    //     {
    //         nuage[m][n].FrontColour = 16;
    //         nuage[m][n].BackColour = 16; // transparent
    //         nuage[m][n].texture = ' ';
    //     }
    // }
    // for (int i = 2; i < 4; i++)
    // {
    //     for (int n = 0; n < 9; n++)
    //     {
    //         nuage[i][n].FrontColour = 15;
    //         nuage[i][n].BackColour = 15; // white
    //         nuage[i][n].texture = ' ';
    //     }
    // }
    // for (int i = 1; i < 9; i++)
    // {
    //     nuage[1][i].FrontColour = 15;
    //     nuage[1][i].BackColour = 15;
    //     nuage[1][i].texture = ' ';
    // }
    // for (int i = 3; i < 7; i++)
    // {
    //     nuage[0][i].FrontColour = 15;
    //     nuage[0][i].BackColour = 15;
    //     nuage[0][i].texture = ' ';
    // }
    // int coor_X = 100;
    // int coor_Y = 300;

    // cons->AjouterObjet(nuage,&coor_X,&coor_Y,3,9,0,"nuage1");

    // for (int i = 0; i < 4; ++i)
    // {
    //     delete[] nuage[i];
    // }
    // delete[] nuage;
}

void Niveau::MatCharacter()
{
     // int c_heigth = playerBoats[v]->characters[v]->getHitboxHeight();
    // int c_width = playerBoats[v]->characters[v]->getHitboxWidth();
    int c_heigth = 10;
    int c_width = 10;

    char tab_test[10][10] = {{' ',' ',' ','+','+','+',' ',' ',' ',' '},
                                {' ',' ','+','+','+','+','+',' ',' ',' '},
                                {' ',' ',' ','*','*','*',' ',' ',' ',' '},
                                {' ',' ',' ',' ','*',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ','*',' ',' ',' ',' ',' '},
                                {' ',' ','<','<','<','<','<','<',' ',' '},
                                {' ',' ',' ',' ','*',' ',' ',' ',' ',' '},
                                {' ',' ',' ','*',' ','*',' ',' ',' ',' '},
                                {' ',' ','*',' ',' ',' ','*',' ',' ',' '},
                                {' ','*',' ',' ',' ',' ',' ','*',' ',' '}} ;


    Pixels **_character = new Pixels*[c_heigth];
    for (int i = 0; i < c_heigth; ++i) {
        _character[i] = new Pixels[c_width];
    }

    //passe a travers tout le tableau pour faire le personnage
    for (int i = 0; i < c_heigth; i++)
    {
        for (int n = 0; n < c_width; n++)
        {
            char val = tab_test[i][n];      //j'ai du mettre ca(c_heigth - i-1) sinon le bonhomme affiche en l'envers
            if(val == ' ')
            {
                _character[i][n].FrontColour = colors::transparant;      
                _character[i][n].BackColour = colors::transparant;       
                _character[i][n].texture = ' ';
            }
            else if(val == '*')
            {
                _character[i][n].FrontColour = colors::green;      
                _character[i][n].BackColour = colors::leaf;       
                _character[i][n].texture = ' ';
            }
            else if(val == '+')
            {
                _character[i][n].FrontColour = colors::black;      
                _character[i][n].BackColour = colors::lightblue;       
                _character[i][n].texture = CHAR_CONTRAST_LOW;
            }
            else if(val == '<')
            {
                _character[i][n].FrontColour = colors::black;      
                _character[i][n].BackColour = colors::red;       
                _character[i][n].texture = CHAR_CONTRAST_MED;
            }
            
        }
    }

    for ( int b = 0; b < playerBoats.getSize(); b++)
    {
        for (int v = 0; v < playerBoats[b]->getNbCharacters(); v++)
        {
            cons->AjouterObjet(_character, playerBoats[b]->characters[v], 0, "Char"+b + ','+v);
        }
    }   
}

void Niveau::MatRocket(Projectile *pro)
{
    int n_heigth = 3;
    int n_width = 7;

    int *coor_X = new int;
    int *coor_Y = new int;
    *coor_X = 950;
    *coor_Y = 250;

    char tab_test[4][9] = { {' ','-',' ',' ',' ',' ',' '},
                            {'?','+','+','+','+','+','*'},
                            {' ','-',' ',' ',' ',' ',' '}};


    Pixels **_nuage = new Pixels*[n_heigth];
    for (int i = 0; i < n_heigth; ++i) {
        _nuage[i] = new Pixels[n_width];
    }
    
    for (int i = 0; i < n_heigth; i++)
    {
        for (int n = 0; n < n_width; n++)
        {
            char val = tab_test[i][n];
            if(val == ' ')
            {
                _nuage[i][n].FrontColour = colors::transparant;      
                _nuage[i][n].BackColour = colors::transparant;       
                _nuage[i][n].texture = ' ';
            }
            else if(val == '+')
            {
                _nuage[i][n].FrontColour = colors::grey;      
                _nuage[i][n].BackColour = colors::grey;       
                _nuage[i][n].texture = ' ';
            }
            else if(val == '-')
            {
                _nuage[i][n].FrontColour = colors::lightred;      
                _nuage[i][n].BackColour = colors::lightred;       
                _nuage[i][n].texture = ' ';
            }
            else if(val == '*')
            {
                _nuage[i][n].FrontColour = colors::red;      
                _nuage[i][n].BackColour = colors::red;       
                _nuage[i][n].texture = ' ';
            }
             else if(val == '?')
            {
                _nuage[i][n].FrontColour = colors::yellow;      
                _nuage[i][n].BackColour = colors::red;       
                _nuage[i][n].texture = ' ';
            }
        }
    }
    
    cons->AjouterObjet(_nuage, pro, 0, "projectile");
      
    return;
}
