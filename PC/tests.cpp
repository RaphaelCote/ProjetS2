#include <chrono>

#include "tests.h"
#include "Game/niveau.h"
#include "Game/utility.h"
#include "Scenes/game.h"
#include "raftWars.h"
#include "Game/enemyCharacter.h"
#include "Game/gameloader.h"
#include "Game/character.h"

#include <QTimer>

//==== DEBUT Controls ====
void test_unitaire_Controls_OnMainActionCall(EventParameters ep)
{
   tests->OnMainAction(ep);
}

void test_unitaire_Controls_OnJoystickCall(EventParameters ep)
{
   tests->OnJoystick(ep);
}

void test_unitaire_Controls_OnAngleCall(EventParameters ep)
{
   tests->OnAngle(ep);
}

void Tests::OnEnable()
{
   eventManager->on("MainAction", test_unitaire_Controls_OnMainActionCall);
   eventManager->on("Joystick", test_unitaire_Controls_OnJoystickCall);
   eventManager->on("Angle", test_unitaire_Controls_OnAngleCall);
}

void Tests::OnDisable()
{
}

void Tests::test_unitaire_Controls()
{
   // Tests unitraires de la classe Controls
   testControls = new KeyboardControls(eventManager);

   // Add eventListener
   // std::cout << "Assigning some controls" << std::cout;
   // OnEnable();

   // Call events
   testControls->MainAction();
   testControls->Joystick(0.85, 0.15);
   testControls->Angle(2.4);

   // OnDisable();
   // std::cout << "Unassigning some controls" << std::endl;
}

void Tests::OnMainAction(EventParameters ep)
{
   std::cout << "Main action called" << std::endl;
}

void Tests::OnJoystick(EventParameters ep)
{
   std::cout << "Joystick X : " << ep.parameter1 << " | Y : " << ep.parameter2 << std::endl;
}

void Tests::OnAngle(EventParameters ep)
{
   std::cout << "Angle : " << ep.parameter1 << std::endl;
}

//==== FIN Controls ====

void Tests::test_unitaire_levels()
{
   Niveau *ptrlevls;
   ptrlevls = new Niveau;
   std::cout << "debut test niveau hauteur (1080) et largeur (3000)" << std::endl;
   ptrlevls->ShowNiveauinfo();
   delete ptrlevls;
}

void Tests::test_unitaire_characterAndprojectile()
{
   std::cout << "-------------RAFT WARS-------------\n";

   // EnemyCharacter enemy(2000, 100);
   // PlayerCharacter player(0, 100);
   // enemy.createEnemyProjectile();

   // std::cout << fixed << setprecision(2);
   // int choix = 0;

   // Projectile *p; // projectile player
   // Projectile *e; // projectile ennemi
   // std::cout << "Entrez la valeur 1 pour lancer une balle, 2 pour lancer une roquette et 3 pour la grenade." << std::endl;
   // cin >> choix;
   // while (choix != 1 && choix != 2 && choix != 3)
   // {
   //    std::cout << "Choix invalide. Entrez la valeur 1 pour lancer une balle, 2 pour lancer une roquette et 3 pour la grenade." << std::endl;
   //    cin >> choix;
   // }
   // if (choix == 1)
   // {
   //    // p = new Canonball(player); //avec l'ancien constructeur
   //    p = new Canonball(player.getWeaponPosition());
   // }

   // if (choix == 2)
   // {
   //    // p = new Rocket(player); //avec l'ancien constructeur
   //    p = new Rocket(player.getWeaponPosition());
   // }
   // if (choix == 3)
   // {
   //    p = new Grenade(player.getWeaponPosition());
   // }
   // e = new Rocket(enemy.getWeaponPosition());

   // std::cout << "Entrez une puissance (entre 0 et 1)" << std::endl;
   // float puissance;
   // cin >> puissance;
   // while (puissance < 0 || puissance > 1)
   // {
   //    std::cout << "Choix invalide. Entrez une puissance (entre 0 et 1)." << std::endl;
   //    cin >> puissance;
   // }
   // p->setPuissance(puissance);
   // std::cout << "Entrez un angle (en degrés)." << std::endl;
   // float angle;
   // cin >> angle;
   // while (angle < 0 || angle > 90)
   // {
   //    std::cout << "Choix invalide. Entrez un angle (en degrés)." << std::endl;
   //    cin >> angle;
   // }
   // p->setAngleDegre(angle);

   // std::cout << "\n"
   //         "-------FORMULE DE LA PARABOLE-------"
   //      << std::endl;
   // std::cout << "y = g"
   //      << "x^2 / (2(" << puissance << "Vmax)^2 · cos^2(" << angle * PI / 180 << ") ) + xtan(" << angle * PI / 180 << ")"
   //      << "\n"
   //      << std::endl;

   // if (p->checkIfCharacterHit(enemy))
   // {
   //    std::cout << "Le projectile a atteint directement l'adversaire. Il a atteri a la position: (" << p->getBulletEndPosition().x << ", " << p->getBulletEndPosition().y << ")" << std::endl;
   // }
   // else
   // {
   //    std::cout << "Le projectile n'a pas atteint directement l'adversaire. Il a atteri a la position: (" << p->getBulletEndPosition().x << ", " << p->getBulletEndPosition().y << ")" << std::endl;
   // }
   // std::cout << "le personnage vise a actuellement : " << enemy.getHealthPoint() << " point de vie" << std::endl;
   Gameloader gameloader;

   Niveau *niveau = gameloader.getLevelFromJson(levelGetter->levels[0]);
}

void Tests::test_unitaire_Boat()
{
   // std::cout << "TESTS UNITAIRES BOAT" << std::endl
   //      << std::endl;
   // // création des personnages et du bateau
   // std::cout << "créer les personnages et les bateaux" << std::endl;
   // Character *pers1 = new PlayerCharacter(1, 0);
   // Character *pers2 = new PlayerCharacter(3, 0);
   // Character *adv1 = new EnemyCharacter(10, 0);
   // Boat joueur(3, 0, 0);
   // Boat adversaire(3, 10, 0);
   // std::cout << "position j: (" << joueur.getPositionBoat().x << "," << joueur.getPositionBoat().y << ")" << std::endl;
   // std::cout << "position a:(" << adversaire.getPositionBoat().x << "," << adversaire.getPositionBoat().y << ")" << std::endl;

   // // ajouter adversaire
   // std::cout << "ajouter les ennemis" << std::endl;
   // adversaire.addCharacter(adv1);
   // std::cout << "size a :" << adversaire.getNbCharacters() << std::endl;
   // adversaire.ShowInfo(std::cout);

   // // ajouter les personnages
   // std::cout << "ajouter les deux personnages" << std::endl;
   // joueur.addCharacter(pers1);
   // joueur.addCharacter(pers2);

   // // retourner les informations des bateaux
   // joueur.ShowInfo(std::cout);
   // std::cout << "size j: " << joueur.getNbCharacters() << std::endl;
   // std::cout << "capacité j: " << joueur.getCapacite() << std::endl;

   // // retirer le personnage 0
   // std::cout << "retirer index 0 de joueur" << std::endl;
   // joueur.removeCharacters(0);

   // // retourner les informations du bateau
   // joueur.ShowInfo(std::cout);
   // std::cout << "size j: " << joueur.getNbCharacters() << std::endl;
   // std::cout << "capacité j: " << joueur.getCapacite() << std::endl;

   // // delete
   // delete pers1;
   // delete pers2;
   // delete adv1;
}

void Tests::tests_unitaires_levelGetter()
{
   std::cout << std::endl
        << "TESTS UNITAIRES levelGetter" << std::endl
        << "-----------------------------------------------------"
        << std::endl;
   LevelGetter *listlevels = new LevelGetter();
   std::string a = listlevels->levels[0];
   std::cout << "Level 0 : " << a << std::endl;
   std::cout << "Level 1" << listlevels->levels[1] << std::endl;
   std::cout << "nb level: " << listlevels->nbLevel << std::endl;
}

void Tests::test_unitaires_affichage()
{

   // reset UI
   cons->ResetUI();

   /////////////////////////////////////////////////////////////////////////////////////////////////////////
   // Creation bateau
   int heigth = 3;
   int width = 20;
   Pixels **couleur = new Pixels *[heigth];
   for (int i = 0; i < heigth; ++i)
   {
      couleur[i] = new Pixels[width];
   }

   for (int i = 0; i < heigth; i++)
   {
      for (int n = 0; n < width; n++)
      {
         couleur[i][n].FrontColour = 6; // gold
         couleur[i][n].BackColour = 8;  // grey
         couleur[i][n].texture = '\xB1';
      }
   }

   int coor_X1 = 1;
   int coor_Y1 = 4;
   int coor_X2 = width + 3;
   int coor_Y2 = 4;

   cons->AjouterObjet(couleur, &coor_X1, &coor_Y1, width, heigth, 0, "Bateau1");
   cons->AjouterObjet(couleur, &coor_X2, &coor_Y2, width, heigth, 0, "Bateau2");

   int _coor_X1 = 250;
   int _coor_Y1 = 4;
   int _coor_X2 = 250 + width + 3;
   int _coor_Y2 = 4;

   cons->AjouterObjet(couleur, &_coor_X1, &_coor_Y1, width, heigth, 0, "Bateau3");
   cons->AjouterObjet(couleur, &_coor_X2, &_coor_Y2, width, heigth, 0, "Bateau4");

   /////////////////////////////////////////////////////////////////////////////////////////////////////////

   /////////////////////////////////////////////////////////////////////////////////////////////////////////
   // Creation eau
   Pixels **eau = new Pixels *[10];
   for (int i = 0; i < 10; ++i)
   {
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

   int coor_X3 = 0;
   int coor_Y3 = 0;
   cons->AjouterObjet(eau, &coor_X3, &coor_Y3, 300, 4, 0, "eau");
   /////////////////////////////////////////////////////////////////////////////////////////////////////////

   /////////////////////////////////////////////////////////////////////////////////////////////////////////
   // creation character
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

   int coor_X4 = 6;
   int coor_Y4 = 6;
   int coor_X5 = 27;
   int coor_Y5 = 6;

   PlayerCharacter c = PlayerCharacter(coor_X5, coor_Y5);

   cons->AjouterObjet(_character, &coor_X4, &coor_Y4, c_width, c_heigth, 0, "Char1");
   cons->AjouterObjet(_character, &c, 0, "Char2");

   int _coor_X4 = 250 + 6;
   int _coor_Y4 = 6;
   int _coor_X5 = 250 + 27;
   int _coor_Y5 = 6;

   cons->AjouterObjet(_character, &_coor_X4, &_coor_Y4, c_width, c_heigth, 0, "Char3");
   cons->AjouterObjet(_character, &_coor_X5, &_coor_Y5, c_width, c_heigth, 0, "Char4");
   /////////////////////////////////////////////////////////////////////////////////////////////////////////

   Sleep(4000);

   // cons->AfficherEnBasGauche(_character, 27, 10, c_width, c_heigth);
   // cons->AfficherEnBasGauche(_character, 50, 10, c_width, c_heigth);

   // system("pause");
   // cons->AfficherEnBasGauche(_character, 70, 10, c_width, c_heigth);
   // system("pause");

   // cons->AfficherEnBasGauche(eau, 0, 40, 300, 10);
   // system("pause");

   int _coor_X8 = 0;
   int _coor_Y8 = cons->MaxRows - 2;
   int _coor_X9 = 50;
   int _coor_Y9 = cons->MaxRows - 5;

   cons->AfficherTexte(std::cout, "Allo, voici du texte que tu peux ecrire", &_coor_X8, &_coor_Y8, "texte1");
   cons->AfficherTexte(std::cout, "Je sais pas voici d'autre texte", &_coor_X9, &_coor_Y9, colors::green, colors::black, "texte2");
   // system("pause");

   // cons->AfficherTexte(std::cout, "Allo, voici du texte que tu peux ecrire", 3,cons->MaxRows-2,colors::darkpurple,colors::gold);
   // cons->AfficherTexte(std::cout, "Je sais pas voici d'autre texte", 12,44,colors::green,colors::black);
   // system("pause");
   /////////////////////////////////////////////////////////////////////////////////////////////////////////

   /////////////////////////////////////////////////////////////////////////////////////////////////////////
   // Creation projectile
   int ball_X = 27 + 8;
   int ball_Y = 11;

   Pixels **ball = new Pixels *[1];
   for (int i = 0; i < 1; ++i)
   {
      ball[i] = new Pixels[1];
   }

   for (int i = 0; i < 1; i++)
   {
      for (int n = 0; n < 1; n++)
      {
         ball[i][n].FrontColour = colors::blue;
         ball[i][n].BackColour = colors::electric;
         ball[i][n].texture = ' ';
      }
   }

   int para = 2;
   cons->AjouterObjet(ball, &ball_X, &ball_Y, 1, 1, 0, "Ball1");
   // cons->AjouterObjet(ball, &proj, 0, "Ball1");
   // Lancement ball vers enemy
   for (int i = 0; i < 220; i++) // Lancement ball vers enemy
   {
      Sleep(10);
      ball_X++;
      _coor_X9++;
      cons->Mincolums++;

      // cons->MinRows--;
      //  coor_Y4++;
      //  coor_Y5++;
      (i % para) ? ((i < 100) ? (ball_Y++, cons->MinRows--) : (ball_Y--, cons->MinRows++)) : ball_Y;
   }

   ball_X = 250 + 6;
   ball_Y = 11;

   // Lancement ball vers nous
   for (int i = 0; i < 240; i++) // Lancement ball vers nous
   {
      Sleep(10);
      ball_X--;
      cons->Mincolums--;
      (i % 2) ? ((i < 115) ? ball_Y++ : ball_Y--) : ball_Y;
   }

   // Player going down
   for (int i = 0; i < 20; i++) // Player going down
   {
      Sleep(10);
      Coordonnee coor;
      coor.x = coor_X5;
      coor.y = coor_Y5--;
      c.setPosition(coor);
   }

   // findBulletPositionY

   // suppression des objet qu'on veut se debarasser
   cons->SupprimerObjet("texte2");
   cons->SupprimerObjet("Ball1");
   cons->SupprimerObjet("Char2");

   // system("pause");
   /////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   test_unitaire_Controls();
   test_unitaire_Boat();
   std::cout << "Début des tests unitaires" << std::endl;
   // test_unitaire_Controls();
   // test_unitaire_levels();
   // test_unitaire_games();
   test_unitaire_characterAndprojectile();

   // system("pause"); // Wait for user input
   // system("cls"); // Clear terminal
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   std::cout << "TESTS APPLICATION (CAS 01)" << std::endl;
   // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
   std::cout << "TESTS APPLICATION (CAS 02)" << std::endl;
   // Il faut ajouter les operations realisant ce scenario de test.
}
void Tests::testjson()
{
   Gameloader *gameloader = new Gameloader();
   Niveau *niveau = gameloader->getLevelFromJson("./levels/levelTemplate.txt");
   niveau->ShowNiveauinfo();
   std::cout << "Bateau joueur" << std::endl;
   niveau->playerBoats[0]->ShowInfo(std::cout);
   std::cout << "Bateau enemy" << std::endl;
   niveau->enemyBoats[0]->ShowInfo(std::cout);
   std::cout << "hauteur enemy" << std::endl;
   std::cout << niveau->enemyBoats[0]->characters[0]->getHitboxHeight() << std::endl;
   std::cout << "largeur player" << std::endl;
   std::cout << niveau->playerBoats[0]->characters[0]->getHitboxWidth() << std::endl;
   std::cout << "image joueur" << std::endl;
   std::cout << niveau->playerBoats[0]->characters[0]->getimage() << std::endl;
   std::cout << "image enemy" << std::endl;
   std::cout << niveau->enemyBoats[0]->characters[0]->getimage() << std::endl;
   std::cout << "playerboat largeur" << std::endl;
   std::cout << niveau->playerBoats[0]->getWidth() << std::endl;
   std::cout << "enemyboat hauteur" << std::endl;
   std::cout << niveau->enemyBoats[0]->getHeight() << std::endl;
}

void Tests::testAffichage()
{
   cons->ResetUI();
   Niveau niveau;
   Coordonnee positionEnemy;
   positionEnemy.x = 600;
   positionEnemy.y = 100;
   Hitbox enemy;
   enemy.height = 20;
   enemy.width = 15;
   Hitbox hitRocket;
   hitRocket.height = 3; // à multiplier par 10 si frank change l'affichage
   hitRocket.width = 7;

   // création des personnages et du bateau
   Character *pers1 = new PlayerCharacter(10, 60);
   Character *pers2 = new PlayerCharacter(250, 60);
   PlayerCharacter c = PlayerCharacter(150, 60);
   Character *adv1 = new EnemyCharacter(positionEnemy, enemy, "Met un path");
   Coordonnee positionBoat;
   positionBoat.x = 30;
   positionBoat.y = 20;
   Coordonnee positionEnemyBoat;
   positionEnemyBoat.x = 160;
   positionEnemyBoat.y = 20;

   Boat joueur(2, positionBoat, 40, 100, "Images/Character/Enemy1.png");
   Boat adversaire(2, positionEnemyBoat, 40, 100, "Images/Character/Enemy1.png");

   Projectile *pro = new Canonball({300, 200});
   Projectile *rocket = new Rocket({650, 300}, hitRocket);
   Projectile *grenade = new Grenade({200, 100});

   // ajouter adversaire

   adversaire.addCharacter(adv1);

   joueur.addCharacter(pers1);
   joueur.addCharacter(pers2);

   niveau.playerBoats.push_back(&joueur);
   niveau.enemyBoats.push_back(&adversaire);

   niveau.MatBalle(pro);
   // erreur ici dans la fonction
   // niveau.MatPlayer();/////////////////////////////////////////////////////////////////////////////
   // Sleep(5000);

   niveau.MatWater();
   niveau.MatRaft();
   niveau.MatGrenade(grenade);
   niveau.MatNuage();
   // Sleep(5000);

   niveau.MatRocket(rocket);
   // Sleep(5000);
   niveau.MatCharacter();
   niveau.MatEnemy();

   int _coor_X8 = 0;
   int _coor_Y8 = cons->MaxRows - 10;
   int _coor_X9 = 500;
   int _coor_Y9 = cons->MaxRows - 50;

   // cons->AfficherTexte(std::cout, "Allo, voici du texte que tu peux ecrire", &_coor_X8,&_coor_Y8, "texte1");
   // cons->AfficherTexte(std::cout, "Je sais pas voici d'autre texte", &_coor_X9,&_coor_Y9,colors::green,colors::black, "texte2");

   Sleep(5000);
}

void Tests::testOuvertureJsonAffiche()
{
   Gameloader *gameloader = new Gameloader();
   Niveau *niveau = gameloader->getLevelFromJson("./levels/level1.json");

   cons->ResetUI();

   // niveau->MatBalle(pro);
   // erreur ici dans la fonction
   // niveau.MatPlayer();/////////////////////////////////////////////////////////////////////////////
   // Sleep(5000);
   // niveau.MatEnemy();
   niveau->MatWater();
   niveau->MatRaft();

   niveau->MatNuage();
   // Sleep(5000);
   // niveau.MatRocket();

   niveau->MatCharacter();
   Sleep(5000);
}



void Tests::testAffichageQt()
{
    window->setWindowState(Qt::WindowMaximized);

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();


    QPixmap map3("Images/Background/LevelBackground.png");
    map3 = map3.scaled(screenWidth, screenHeight);

    int* x1 = new int;
    int* y1 = new int;
    float* r1 = new float;

    *x1 = 0;
    *y1 = 0;
    *r1 = 0;

    Frank_PixMap* image4 = new Frank_PixMap;
    image4->pix = map3;
    image4->x = x1;
    image4->y = y1;
    //image4->coor = { 0,0 };
    image4->box = { screenHeight,50 };
    image4->name = "allo2";
    image4->couche = -1;
    image4->rotation = 0;
    window->addImage(image4);

    int* x2 = new int;
    int* y2 = new int;
    float* r2 = new float;

    *x2 = 200;
    *y2 = 175;
    *r2 = 0;


    QPixmap map2("Images/Character/Enemy1.png");
    // Load the first image
    Frank_PixMap* image3 = new Frank_PixMap;
    image3->pix = map2;
    image3->x = x2;
    image3->y = y2;
    //image3->coor = { 200, 175 };
    image3->box = { 125,50 };
    image3->name = "allo4";
    image3->couche = 1;
    image3->rotation = 0;

    window->addImage(image3);

    window->show();
}

Projectile* rocket;
Projectile* ball;
void fonctionBatard(Projectile* proj, Projectile* ball)
{
    window->minX -= 3;
    window->refresh();
    proj->bulletCurrentPosition.x += 3;
    proj->angleRotationProjectile += 1;
    ball->bulletCurrentPosition.x += 3;
    ball->angleRotationProjectile += 1;

    if (window->minX < -2900)
    {
        window->minX = 2200;
        proj->bulletCurrentPosition.x = -2000;
        ball->bulletCurrentPosition.x = -1700;
    }
        
}

void Tests::LoadJsonAffichageQt()
{
    Gameloader* gameloader = new Gameloader();
    Niveau* niveau = gameloader->getLevelFromJson("PC/levels/level1.json");

    window->setWindowState(Qt::WindowMaximized);

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();

    QString str = QString::fromUtf8(niveau->backimge.c_str());//fuck you that why
    QPixmap map3(str);
    map3 = map3.scaled(screenWidth, screenHeight);

    int* x1 = new int;
    int* y1 = new int;
    float* r1 = new float;

    *x1 = 0;
    *y1 = 0;
    *r1 = 0;

    Frank_PixMap* image4 = new Frank_PixMap;
    image4->pix = map3;
    image4->x = x1;
    image4->y = y1;
    //image4->coor = { 0,0 };
    image4->box = { screenHeight,50 };
    image4->name = "allo2";
    image4->couche = -1;
    image4->rotation = 0;
    window->addImage(image4);

    niveau->RaftQt();
    niveau->CharacterQt();


    
    
    Hitbox hitRocket;
    hitRocket.height = 3; // à multiplier par 10 si frank change l'affichage
    hitRocket.width = 7;
    rocket = new Rocket({ 200, 300 }, hitRocket);

    
    Hitbox hitBall;
    hitBall.height = 3; // à multiplier par 10 si frank change l'affichage
    hitBall.width = 7;
    ball = new Canonball({ 500, 400 }, hitBall);

    niveau->RocketQt(rocket);
    niveau->BalleQt(ball);


    window->show();


    QTimer *timer = new QTimer;
    timer->setInterval(1); // Interval in milliseconds
    QObject::connect(timer, &QTimer::timeout, [&]() {
        
        fonctionBatard(rocket, ball);
        });
    timer->start();

    

    // niveau->MatBalle(pro);
    // erreur ici dans la fonction
    // niveau.MatPlayer();/////////////////////////////////////////////////////////////////////////////
    // Sleep(5000);
    // niveau.MatEnemy();
    //niveau->MatWater();
    

    //niveau->MatNuage();
    //// Sleep(5000);
    //// niveau.MatRocket();

    //niveau->MatCharacter();
}