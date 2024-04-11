#include "niveau.h"
#include "Boat.h"
#include "playerCharacter.h"
#include "enemyCharacter.h"
#include "../Affichage/AffichageConsole.h"
#include "../raftWars.h"
#include "../Affichage/Pixmaps.h"
#include "../Affichage/Global.h"
#include "../Affichage/GlobalTwo.h"

Niveau::Niveau()
{
}

Niveau::Niveau(int width, int height, std::string image)
{
    backimge = image;
    this->height = height;
    this->width = width;

    healtBarsBackground.clear();
    healtBarsForeground.clear();
}

Niveau::~Niveau()
{
}

void Niveau::ShowLevelInfo(std::ostream &s)
{
    s << "Bateaux joueurs : " << std::endl;

    for (int i = 0; i < playerBoats.size(); i++)
    {
        s << "Bateau  " << i + 1 << " :" << std::endl;

        playerBoats[i]->ShowInfo(s);
    }

    s << "Bateaux enemies : " << std::endl;

    for (int i = 0; i < enemyBoats.size(); i++)
    {
        s << "Bateau  " << i + 1 << " :" << std::endl;

        enemyBoats[i]->ShowInfo(s);
    }
}

void Niveau::ShowNiveauinfo()
{
    // cout << "hauteur niveau " << height << std::endl;
    // cout << "largeur niveau " << width << std::endl;
}

void Niveau::addRaftPlayer(int width, int height, Coordonnee position, std::string image, int capacite)
{
    playerBoats.push_back(new Boat(capacite, position, height, width, image));
}

void Niveau::addRaftenemy(int width, int height, Coordonnee position, std::string image, int capacite)
{
    enemyBoats.push_back(new Boat(capacite, position, height, width, image));
}

void Niveau::MatRaft()
{
    for (int i = 0; i < playerBoats.size(); ++i)
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

    for (int i = 0; i < enemyBoats.size(); i++)
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

void Niveau::RaftQt()
{
    for (int i = 0; i < playerBoats.size(); ++i)
    {
        Frank_PixMap* pixmap = new Frank_PixMap;

        QString str = QString::fromUtf8(playerBoats[i]->imageboat.c_str());//fuck you that why
        pixmap->pix = QPixmap(str);
        pixmap->box = { pixmap->pix.height(), pixmap->pix.width() };
        pixmap->x = playerBoats[i]->getPointerPositionBoat_X();
        pixmap->y = playerBoats[i]->getPointerPositionBoat_Y();
        pixmap->couche = 1;
        pixmap->name = "Boat" + std::to_string(i);
        pixmap->rotation = 0;

        gameWindow->GetGameWidget()->addImage(pixmap);

    }

    for (int i = 0; i < enemyBoats.size(); i++)
    {
        Frank_PixMap* pixmap = new Frank_PixMap;

        QString str = QString::fromUtf8(enemyBoats[i]->imageboat.c_str());//fuck you that why
        pixmap->pix = QPixmap(str);
        pixmap->box = { pixmap->pix.height(), pixmap->pix.width() };
        pixmap->x = enemyBoats[i]->getPointerPositionBoat_X();
        pixmap->y = enemyBoats[i]->getPointerPositionBoat_Y();
        pixmap->couche = 1;
        pixmap->name = "EnemyBoat" + std::to_string(i);
        pixmap->rotation = 0;

        gameWindow->GetGameWidget()->addImage(pixmap);
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

    for (int b = 0; b < enemyBoats.size(); b++)
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

void Niveau::BalleQt(Projectile* pro)
{
    Frank_PixMap_Rotation* pixmap = new Frank_PixMap_Rotation;

    QString str("Images/Projectile/Ball.png");
    pixmap->pix = QPixmap(str);
    pixmap->box = { pixmap->pix.height(), pixmap->pix.width() };
    pixmap->x = &pro->bulletCurrentPosition.x;
    pixmap->y = &pro->bulletCurrentPosition.y;
    pixmap->couche = 3;
    pixmap->name = "projectile";
    pixmap->rotation = &pro->angleRotationProjectile;

    gameWindow->GetGameWidget()->addImage(pixmap);
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

void Niveau::GrenadeQt(Projectile* pro)
{
    Frank_PixMap_Rotation* pixmap = new Frank_PixMap_Rotation;

    QString str("Images/Projectile/GrenadeGame.png");
    pixmap->pix = QPixmap(str);
    pixmap->box = { pixmap->pix.height(), pixmap->pix.width() };
    pixmap->x = &pro->bulletCurrentPosition.x;
    pixmap->y = &pro->bulletCurrentPosition.y;
    pixmap->couche = 3;
    pixmap->name = "projectile";
    pixmap->rotation = &pro->angleRotationProjectile;

    gameWindow->GetGameWidget()->addImage(pixmap);
}

void Niveau::ExplosionQt(Projectile* pro)
{
    Frank_PixMap_Rotation* pixmap = new Frank_PixMap_Rotation;

    QString str("Images/Projectile/Explosion.png");
    pixmap->pix = QPixmap(str);
    //pixmap->pix.scaled(0.1, 0.1);
    pixmap->box = { pixmap->pix.height(), pixmap->pix.width() };
    pixmap->x = &pro->bulletCurrentPosition.x;//- (pixmap->pix.width()/2);
    pixmap->y = &pro->bulletCurrentPosition.y;// -(pixmap->pix.height() / 2);
    pixmap->couche = 3;
    pixmap->name = "explosion";
    pixmap->rotation = &pro->angleRotationProjectile;

    gameWindow->GetGameWidget()->addImage(pixmap);
}

void Niveau::AxeQt(Projectile* pro)
{
    Frank_PixMap_Rotation* pixmap = new Frank_PixMap_Rotation;

    QString str("Images/Projectile/AxeGame.png");
    pixmap->pix = QPixmap(str);
    pixmap->box = { pixmap->pix.height(), pixmap->pix.width() };
    pixmap->x = &pro->bulletCurrentPosition.x;
    pixmap->y = &pro->bulletCurrentPosition.y;
    pixmap->couche = 3;
    pixmap->name = "projectile";
    pixmap->rotation = &pro->angleRotationProjectile;

    gameWindow->GetGameWidget()->addImage(pixmap);
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

    for (int b = 0; b < playerBoats.size(); b++)
    {
        for (int v = 0; v < playerBoats[b]->getNbCharacters(); v++)
        {
            cons->AjouterObjet(_character, playerBoats[b]->characters[v], 0, "Char" + b + ',' + v);
        }
    }
}


void Niveau::CharacterQt()
{
    for (int b = 0; b < playerBoats.size(); b++)
    {
        for (int v = 0; v < playerBoats[b]->getNbCharacters(); v++)
        {
            Frank_PixMap* pixmap = new Frank_PixMap;
            
            QString str = QString::fromUtf8(playerBoats[b]->characters[v]->imagecharacter.c_str());//fuck you that why
            pixmap->pix = QPixmap(str);
            pixmap->box = { pixmap->pix.height(), pixmap->pix.width() };
            pixmap->x = playerBoats[b]->characters[v]->GetPointeurX();
            pixmap->y = playerBoats[b]->characters[v]->GetPointeurY();
            pixmap->couche = 1;
            pixmap->name = "Character" + std::to_string(b) + ',' + std::to_string(v);
            pixmap->rotation = 0;

            gameWindow->GetGameWidget()->addImage(pixmap);

            Raph_PixMap* healtBackground = new Raph_PixMap;

            healtBackground->pix = QPixmap("Images/healthBackground.png");
            healtBackground->box = { healtBackground->pix.height(), healtBackground->pix.width() };
            healtBackground->x = playerBoats[b]->characters[v]->getPosition().x + (playerBoats[b]->characters[v]->getHitboxWidth() / 2) - 77;
            healtBackground->y =playerBoats[b]->characters[v]->getPosition().y + playerBoats[b]->characters[v]->getHitboxHeight() + 50;
            healtBackground->couche = 2;
            healtBackground->name = "CharacterHealthBackground" + std::to_string(healtBarsBackground.size());
            healtBackground->rotation = 0;

            healtBarsBackground.push_back(healtBackground);

            gameWindow->GetGameWidget()->addImage(healtBackground);

            Raph_PixMap* healtForeground = new Raph_PixMap;

            healtForeground->pix = QPixmap("Images/healthForeground.png");
            healtForeground->box = { healtForeground->pix.height(), healtForeground->pix.width() };
            healtForeground->x = playerBoats[b]->characters[v]->getPosition().x + (playerBoats[b]->characters[v]->getHitboxWidth() / 2) - 75;
            healtForeground->y = playerBoats[b]->characters[v]->getPosition().y + playerBoats[b]->characters[v]->getHitboxHeight() + 52;
            healtForeground->couche = 3;
            healtForeground->name = "CharacterHealthForeground" + std::to_string(healtBarsForeground.size());
            healtForeground->rotation = 0;

            healtBarsForeground.push_back(healtForeground);

            gameWindow->GetGameWidget()->addImage(healtForeground);
        }
    }


    for (int b = 0; b < enemyBoats.size(); b++)
    {
        for (int v = 0; v < enemyBoats[b]->getNbCharacters(); v++)
        {
            Frank_PixMap* pixmap = new Frank_PixMap;

            QString str = QString::fromUtf8(enemyBoats[b]->characters[v]->imagecharacter.c_str());//fuck you that why
            pixmap->pix = QPixmap(str);
            pixmap->box = { pixmap->pix.height(), pixmap->pix.width() };
            pixmap->x = enemyBoats[b]->characters[v]->GetPointeurX();
            pixmap->y = enemyBoats[b]->characters[v]->GetPointeurY();
            pixmap->couche = 1;
            pixmap->name = "EnemyCharacter" + std::to_string(b) + ',' + std::to_string(v);
            pixmap->rotation = 0;

            gameWindow->GetGameWidget()->addImage(pixmap);

            Raph_PixMap* healtBackground = new Raph_PixMap;

            healtBackground->pix = QPixmap("Images/healthBackground.png");
            healtBackground->box = { healtBackground->pix.height(), healtBackground->pix.width() };
            healtBackground->x = enemyBoats[b]->characters[v]->getPosition().x + (enemyBoats[b]->characters[v]->getHitboxHeight() / 2) - 77;
            healtBackground->y = enemyBoats[b]->characters[v]->getPosition().y + (enemyBoats[b]->characters[v]->getHitboxHeight() * 2);
            healtBackground->couche = 2;
            healtBackground->name = "CharacterHealthBackground" + std::to_string(healtBarsBackground.size());
            healtBackground->rotation = 0;

            healtBarsBackground.push_back(healtBackground);

            gameWindow->GetGameWidget()->addImage(healtBackground);

            Raph_PixMap* healtForeground = new Raph_PixMap;

            healtForeground->pix = QPixmap("Images/healthForeground.png");
            healtForeground->box = { healtForeground->pix.height(), healtForeground->pix.width() };
            healtForeground->x = enemyBoats[b]->characters[v]->getPosition().x + 2 + (enemyBoats[b]->characters[v]->getHitboxHeight() / 2) - 77;
            healtForeground->y = enemyBoats[b]->characters[v]->getPosition().y + (enemyBoats[b]->characters[v]->getHitboxHeight() * 2) + 2;
            healtForeground->couche = 3;
            healtForeground->name = "CharacterHealthForeground" + std::to_string(healtBarsForeground.size());
            healtForeground->rotation = 0;

            healtBarsForeground.push_back(healtForeground);

            gameWindow->GetGameWidget()->addImage(healtForeground);
        }
    }
}

void Niveau::UpdateHealthQt() {
    std::vector<Character*> characters;

    for (int i = 0; i < playerBoats.size(); i++)
    {
        for (int j = 0; j < playerBoats[i]->characters.size(); j++)
        {
            if (playerBoats[i]->characters[j]->getHealthPoint() > 0)
            {
                characters.push_back(playerBoats[i]->characters[j]);
            }
        }
    }
    for (int i = 0; i < enemyBoats.size(); i++)
    {
        for (int j = 0; j < enemyBoats[i]->characters.size(); j++)
        {
            if (enemyBoats[i]->characters[j]->getHealthPoint() > 0)
            {
                characters.push_back(enemyBoats[i]->characters[j]);
            }
        }
    }

    for (int i = 0; i < characters.size(); i++) {
        if (characters[i]->getHealthPoint() > 0) {
            float currentHealth = characters[i]->getHealthPoint();
            float healthPercentage = currentHealth / 100;

            //if (currentHealth < 25) {
                healtBarsForeground[i]->pix = QPixmap("Images/healthForeground.png").scaled(healthPercentage*150, 20, Qt::IgnoreAspectRatio);
                healtBarsForeground[i]->box = { healtBarsForeground[i]->pix.height(), healtBarsForeground[i]->pix.width() };
            //}
        }
        else {
            RemoveItemQt(healtBarsBackground[i]->name);
            RemoveItemQt(healtBarsForeground[i]->name);
        }
    }
}

void Niveau::RemoveItemQt(std::string name) {
    
    gameWindow->GetGameWidget()->removeImage(name);
    gameWindow->GetGameWidget()->refresh();
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


void Niveau::RocketQt(Projectile* pro)
{
    Frank_PixMap_Rotation* pixmap = new Frank_PixMap_Rotation;

    QString str("Images/Projectile/MissileGame.png");
    pixmap->pix = QPixmap(str);
    pixmap->box = { pixmap->pix.height(), pixmap->pix.width() };
    pixmap->x = &pro->bulletCurrentPosition.x;
    pixmap->y = &pro->bulletCurrentPosition.y;
    pixmap->couche = 3;
    pixmap->name = "projectile";
    pixmap->rotation = &pro->angleRotationProjectile;

    gameWindow->GetGameWidget()->addImage(pixmap);
}

void Niveau::Delete()
{
    // Delete de l'eau
    cons->SupprimerObjet("eau");

    // Delete du nuage
    cons->SupprimerObjet("nuage");

    // Delete des bateaux
    for (int i = 0; i < playerBoats.size(); i++)
    {
        cons->SupprimerObjet("boat player " + i);
    }

    for (int i = 0; i < enemyBoats.size(); i++)
    {
        cons->SupprimerObjet("boat enemy " + i);
    }

    // Delete des joueurs
    for (int b = 0; b < playerBoats.size(); b++)
    {
        for (int v = 0; v < playerBoats[b]->getNbCharacters(); v++)
        {
            cons->SupprimerObjet("Char" + b + ',' + v);
        }
    }

    // Delete des Enemies
    for (int b = 0; b < enemyBoats.size(); b++)
    {
        for (int v = 0; v < enemyBoats[b]->getNbCharacters(); v++)
        {
            cons->SupprimerObjet("enemy" + b + ',' + v);
        }
    }
}



void Niveau::BackgroundQt()
{
    QString str = QString::fromUtf8(this->backimge.c_str());//fuck you that why
    QPixmap map3(str);
    //map3=map3.scaledToWidth(2000);
    //map3 = map3.scaled(gameWindow->width(), gameWindow->height());    
    gameWindow->GetGameWidget()->backgroundWidth = map3.width();
    Raph_PixMap* image4 = new Raph_PixMap;
    image4->pix = map3;
    image4->x = -100;
    image4->y = 0;
    //image4->coor = { 0,0 };
    image4->box = { map3.height(),50 };
    image4->name = "Background";
    image4->couche = 0;
    image4->rotation = 0;
    gameWindow->GetGameWidget()->addImage(image4);
}
