#include "niveau.h"
#include "Boat.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"

Niveau::Niveau()
{
    initializeBoats();
}
Niveau::Niveau(int width, int height, int image)
{

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
void Niveau::addRaftPlayer(int width, int height, int posX, int posY, int image, int capacite, int i){
    playerBoats[i]=new Boat(capacite, posX, posY, height, width, image);

}
void Niveau::addRaftenemy(int width, int height, int posX, int posY, int image, int capacite, int i){
    enemyBoats[i]=new Boat(capacite, posX, posY, height, width, image);
}

void Niveau::MatRaft()
{
    
    for (int i = 0; playerBoats[i]!= NULL; i++)
    {
        Couleur couleur[(playerBoats[i]->getHeight())/10][(playerBoats[i]->getWidth())/10];


        for (int i = 0; i < (playerBoats[i]->getHeight())/10; i++)
        {
            for (int n = 0; i < (playerBoats[i]->getWidth())/10; n++)
            {
                couleur[i][n].FrontColour = 6;      //gold
                couleur[i][n].BackColour = 8;       //grey
                couleur[i][n].texture = '\xB1';
            }
            
        }
     //AfficherEnBasGauche(couleur[][], x, y, width, hauteur)
    }
    
    for (int i = 0; enemyBoats[i]!= NULL; i++)
    {
        Couleur couleur[(enemyBoats[i]->getHeight())/10][(enemyBoats[i]->getWidth())/10];


        for (int i = 0; i < (enemyBoats[i]->getHeight())/10; i++)
        {
            for (int n = 0; i < (enemyBoats[i]->getWidth())/10; n++)
            {
                couleur[i][n].FrontColour = 6;      //gold
                couleur[i][n].BackColour = 8;       //grey
                couleur[i][n].texture = '\xB1';
            }
            
        }
     //AfficherEnBasGauche(couleur[][], x, y, width, hauteur)
    }
   
}

void Niveau::MatPlayer()
{
    for (int v=0 ; playerBoats[v] != NULL ; v++)
    {
        for (int i = 0;  playerBoats[v]->characters[i] != NULL; i++)
        {
            Couleur MatCharacter[10][10];
            for (int m = 0; i < 10; m++)
            {
                for (int n = 0; i < 10; n++)
                {
                    MatCharacter[m][n].FrontColour = 16;      
                    MatCharacter[m][n].BackColour = 16;       //on remplie tt de transparent          
                    MatCharacter[m][n].texture = ' ';
                } 
            }

            for (int m = 0; i < 3; m++)
            {
                for (int n = 5; i < 8; n++)
                {
                    MatCharacter[m][n].FrontColour = 10;      
                    MatCharacter[m][n].BackColour = 10;       //green       
                    MatCharacter[m][n].texture = ' ';
                } 
            }
            MatCharacter[3][6].FrontColour = 10;      
            MatCharacter[3][6].BackColour = 10;       //green       
            MatCharacter[3][6].texture = ' ';

            
            for (int i = 4; i < 6; i++)
            {
                for (int t = 5; i < 10; i++)
                {
                MatCharacter[4][i].FrontColour = 0;
                MatCharacter[4][i].BackColour = 4; //gun          
                MatCharacter[4][i].texture = '\xB1';
                }
            }


            MatCharacter[6][6].FrontColour = 10;
            MatCharacter[6][6].BackColour = 10;          
            MatCharacter[6][6].texture = ' ';

            for (int i =5; i < 8; i++)
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

        }
    }
    

}

void Niveau::MatEnemy()
{
    for (int v=0 ; enemyBoats[v] != NULL ; v++)
    {
        for (int i = 0;  enemyBoats[v]->characters[i] != NULL; i++)
        {
            Couleur MatCharacter[10][10];
            for (int m = 0; i < 10; m++)
            {
                for (int n = 0; i < 10; n++)
                {
                    MatCharacter[m][n].FrontColour = 16;      
                    MatCharacter[m][n].BackColour = 16;       //on remplie tt de transparent          
                    MatCharacter[m][n].texture = ' ';
                } 
            }

            for (int m = 0; i < 3; m++)
            {
                for (int n = 2; i < 5; n++)
                {
                    MatCharacter[m][n].FrontColour = 10;      
                    MatCharacter[m][n].BackColour = 10;       //green       
                    MatCharacter[m][n].texture = ' ';
                } 
            }
            MatCharacter[3][3].FrontColour = 10;      
            MatCharacter[3][3].BackColour = 10;       //green       
            MatCharacter[3][3].texture = ' ';

            
            for (int i = 4; i < 6; i++)
            {
                for (int t = 0; i < 5; i++)
                {
                MatCharacter[4][i].FrontColour = 0;
                MatCharacter[4][i].BackColour = 4; //gun          
                MatCharacter[4][i].texture = '\xB1';
                }
            }


            MatCharacter[6][3].FrontColour = 10;
            MatCharacter[6][3].BackColour = 10;          
            MatCharacter[6][3].texture = ' ';

            for (int i =2; i < 5; i++)
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

        }
    }
    
}

void Niveau::MatWater()
{
    Couleur water[height/10][width/10];
    for (int i = 0; i < (height/10); i++)
    {
        for (int n = 0; n < (width/10); n++)
        {
            water[i][n].FrontColour = 11;
            water[i][n].BackColour = 9;
            water[i][n].texture = '\xB0';
        }
    }
    
}

void Niveau::MatBalle()
{
}

void Niveau::MatGrenade()
{
}

void Niveau::MatRocket()
{
}
