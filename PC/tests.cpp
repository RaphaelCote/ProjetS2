#include <chrono>

#include "tests.h"
#include "Game/niveau.h"
#include "Scenes/game.h"
#include "raftWars.h"
#include "Game/enemyCharacter.h"
#include "Game/gameloader.h"
#include "Game/character.h"


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
   cout << "Assigning some controls" << endl;
   OnEnable();

   // Call events
   testControls->MainAction();
   testControls->Joystick(0.85, 0.15);
   testControls->Angle(2.4);

   OnDisable();
   cout << "Unassigning some controls" << endl;
}

void Tests::OnMainAction(EventParameters ep)
{
   std::cout << "Main action called" << endl;
}

void Tests::OnJoystick(EventParameters ep)
{
   std::cout << "Joystick X : " << ep.parameter1 << " | Y : " << ep.parameter2 << endl;
}

void Tests::OnAngle(EventParameters ep)
{
   std::cout << "Angle : " << ep.parameter1 << endl;
}

//==== FIN Controls ====

void Tests::test_unitaire_levels()
{
   Niveau *ptrlevls;
   ptrlevls = new Niveau;
   cout << "debut test niveau hauteur (1080) et largeur (3000)" << endl;
   ptrlevls->ShowNiveauinfo();
   delete ptrlevls;
}

void Tests::test_unitaire_characterAndprojectile()
{
   std::cout << "-------------RAFT WARS-------------\n";

   // EnemyCharacter enemy(2000, 100);
   // PlayerCharacter player(0, 100);
   // enemy.createEnemyProjectile();

   // cout << fixed << setprecision(2);
   // int choix = 0;

   // Projectile *p; // projectile player
   // Projectile *e; // projectile ennemi
   // cout << "Entrez la valeur 1 pour lancer une balle, 2 pour lancer une roquette et 3 pour la grenade." << endl;
   // cin >> choix;
   // while (choix != 1 && choix != 2 && choix != 3)
   // {
   //    cout << "Choix invalide. Entrez la valeur 1 pour lancer une balle, 2 pour lancer une roquette et 3 pour la grenade." << endl;
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

   // cout << "Entrez une puissance (entre 0 et 1)" << endl;
   // float puissance;
   // cin >> puissance;
   // while (puissance < 0 || puissance > 1)
   // {
   //    cout << "Choix invalide. Entrez une puissance (entre 0 et 1)." << endl;
   //    cin >> puissance;
   // }
   // p->setPuissance(puissance);
   // cout << "Entrez un angle (en degrés)." << endl;
   // float angle;
   // cin >> angle;
   // while (angle < 0 || angle > 90)
   // {
   //    cout << "Choix invalide. Entrez un angle (en degrés)." << endl;
   //    cin >> angle;
   // }
   // p->setAngleDegre(angle);

   // cout << "\n"
   //         "-------FORMULE DE LA PARABOLE-------"
   //      << endl;
   // cout << "y = g"
   //      << "x^2 / (2(" << puissance << "Vmax)^2 · cos^2(" << angle * PI / 180 << ") ) + xtan(" << angle * PI / 180 << ")"
   //      << "\n"
   //      << endl;

   // if (p->checkIfCharacterHit(enemy))
   // {
   //    cout << "Le projectile a atteint directement l'adversaire. Il a atteri a la position: (" << p->getBulletEndPosition().x << ", " << p->getBulletEndPosition().y << ")" << endl;
   // }
   // else
   // {
   //    cout << "Le projectile n'a pas atteint directement l'adversaire. Il a atteri a la position: (" << p->getBulletEndPosition().x << ", " << p->getBulletEndPosition().y << ")" << endl;
   // }
   // cout << "le personnage vise a actuellement : " << enemy.getHealthPoint() << " point de vie" << endl;
   Gameloader gameloader;

   Niveau *niveau = gameloader.getLevelFromJson(levelGetter->levels[0]);

   
}

void Tests::test_unitaire_Boat()
{
   // cout << "TESTS UNITAIRES BOAT" << endl
   //      << endl;
   // // création des personnages et du bateau
   // cout << "créer les personnages et les bateaux" << endl;
   // Character *pers1 = new PlayerCharacter(1, 0);
   // Character *pers2 = new PlayerCharacter(3, 0);
   // Character *adv1 = new EnemyCharacter(10, 0);
   // Boat joueur(3, 0, 0);
   // Boat adversaire(3, 10, 0);
   // cout << "position j: (" << joueur.getPositionBoat().x << "," << joueur.getPositionBoat().y << ")" << endl;
   // cout << "position a:(" << adversaire.getPositionBoat().x << "," << adversaire.getPositionBoat().y << ")" << endl;

   // // ajouter adversaire
   // cout << "ajouter les ennemis" << endl;
   // adversaire.addCharacter(adv1);
   // cout << "size a :" << adversaire.getNbCharacters() << endl;
   // adversaire.ShowInfo(cout);

   // // ajouter les personnages
   // cout << "ajouter les deux personnages" << endl;
   // joueur.addCharacter(pers1);
   // joueur.addCharacter(pers2);

   // // retourner les informations des bateaux
   // joueur.ShowInfo(cout);
   // cout << "size j: " << joueur.getNbCharacters() << endl;
   // cout << "capacité j: " << joueur.getCapacite() << endl;

   // // retirer le personnage 0
   // cout << "retirer index 0 de joueur" << endl;
   // joueur.removeCharacters(0);

   // // retourner les informations du bateau
   // joueur.ShowInfo(cout);
   // cout << "size j: " << joueur.getNbCharacters() << endl;
   // cout << "capacité j: " << joueur.getCapacite() << endl;

   // // delete
   // delete pers1;
   // delete pers2;
   // delete adv1;
}

void Tests::tests_unitaires_levelGetter()
{
   cout << endl
        << "TESTS UNITAIRES levelGetter" << endl
        << "-----------------------------------------------------"
        << endl;
   LevelGetter *listlevels = new LevelGetter();
   string a = listlevels->levels[0];
   cout << "Level 0 : " << a << endl;
   cout << "Level 1" << listlevels->levels[1] << endl;
   cout << "nb level: " << listlevels->nbLevel << endl;
}

void Tests::test_unitaires_affichage()
{
   
   //reset UI
   cons->ResetUI();

   /////////////////////////////////////////////////////////////////////////////////////////////////////////
   //Creation bateau
   int heigth = 3;
   int width = 20;
   Pixels **couleur = new Pixels*[heigth];
   for (int i = 0; i < heigth; ++i) {
      couleur[i] = new Pixels[width];
   }

   for (int i = 0; i < heigth; i++)
   {
      for (int n = 0; n < width; n++)
      {
         couleur[i][n].FrontColour = 6;      //gold
         couleur[i][n].BackColour = 8;       //grey
         couleur[i][n].texture = '\xB1';
      }

   }

   int coor_X1 = 1;
   int coor_Y1 = cons->MaxRows-4;
   int coor_X2 = width+3;
   int coor_Y2 = cons->MaxRows-4;

   cons->AjouterObjet(couleur, &coor_X1, &coor_Y1, width, heigth, 0, "Bateau1");
   cons->AjouterObjet(couleur, &coor_X2, &coor_Y2, width, heigth, 0, "Bateau2");

   int _coor_X1 = 250;
   int _coor_Y1 = cons->MaxRows-4;
   int _coor_X2 = 250+width+3;
   int _coor_Y2 = cons->MaxRows-4;

   cons->AjouterObjet(couleur, &_coor_X1, &_coor_Y1, width, heigth, 0, "Bateau3");
   cons->AjouterObjet(couleur, &_coor_X2, &_coor_Y2, width, heigth, 0, "Bateau4");

   /////////////////////////////////////////////////////////////////////////////////////////////////////////

   /////////////////////////////////////////////////////////////////////////////////////////////////////////
   //Creation eau
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

   int coor_X3 = 0;
   int coor_Y3 = cons->MaxRows;
   cons->AjouterObjet(eau, &coor_X3, &coor_Y3, 300, 4, 0, "eau");
   /////////////////////////////////////////////////////////////////////////////////////////////////////////

   /////////////////////////////////////////////////////////////////////////////////////////////////////////
   //creation character
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
         char val = tab_test[c_heigth - i-1][n];      //j'ai du mettre ca(c_heigth - i-1) sinon le bonhomme affiche en l'envers
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

   int coor_X4 = 6;
   int coor_Y4 = cons->MaxRows-5;
   int coor_X5 = 27;
   int coor_Y5 = cons->MaxRows-5;

   PlayerCharacter c = PlayerCharacter(coor_X5, coor_Y5);

   cons->AjouterObjet(_character, &coor_X4, &coor_Y4, c_width, c_heigth,0, "Char1");
   cons->AjouterObjet(_character, &c, 0, "Char2");

   

   int _coor_X4 = 250+6;
   int _coor_Y4 = cons->MaxRows-5;
   int _coor_X5 = 250+27;
   int _coor_Y5 = cons->MaxRows-5;

   cons->AjouterObjet(_character, &_coor_X4, &_coor_Y4, c_width, c_heigth,0, "Char3");
   cons->AjouterObjet(_character, &_coor_X5, &_coor_Y5,  c_width, c_heigth,0, "Char4");
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
   int _coor_Y8 = 0;
   int _coor_X9 = 50;
   int _coor_Y9 = 15;

   cons->AfficherTexte(std::cout, "Allo, voici du texte que tu peux ecrire", &_coor_X8,&_coor_Y8, "texte1");
   cons->AfficherTexte(std::cout, "Je sais pas voici d'autre texte", &_coor_X9,&_coor_Y9,colors::green,colors::black, "texte2");
   // system("pause");

   // cons->AfficherTexte(std::cout, "Allo, voici du texte que tu peux ecrire", 3,cons->MaxRows-2,colors::darkpurple,colors::gold);
   // cons->AfficherTexte(std::cout, "Je sais pas voici d'autre texte", 12,44,colors::green,colors::black);
   // system("pause");
   /////////////////////////////////////////////////////////////////////////////////////////////////////////

   /////////////////////////////////////////////////////////////////////////////////////////////////////////
   //Creation projectile
   int ball_X = 27+8;
   int ball_Y = cons->MaxRows-10;

   Canonball proj({ball_X,ball_Y});

   Pixels **ball = new Pixels*[1];
   for (int i = 0; i < 1; ++i) {
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
   //cons->AjouterObjet(ball, &proj, 0, "Ball1");
   //Lancement ball vers enemy
   for (int i = 0; i < 220; i++)                                  //Lancement ball vers enemy
   {
      Sleep(10);
      ball_X++;
      cons->Mincolums++;
      //cons->MinRows--;
      // coor_Y4++;
      // coor_Y5++;
      (i%para) ? ((i<100) ? ball_Y-- : ball_Y++) : ball_Y;
   }

   ball_X = 250+6;
   ball_Y = cons->MaxRows-10;

   //Lancement ball vers nous
   for (int i = 0; i < 240; i++)                                  //Lancement ball vers nous
   {
      Sleep(10);
      ball_X--;
      cons->Mincolums--;
      (i%2) ? ((i<115) ? ball_Y-- : ball_Y++) : ball_Y;
   }

   // Player going down
   for (int i = 0; i < 20; i++)                                   // Player going down
   {
      Sleep(10);
      Coordonnee coor;
      coor.x = coor_X5;
      coor.y = coor_Y5++;
      c.setPosition(coor);
   }

   //findBulletPositionY

   //suppression des objet qu'on veut se debarasser
   cons->SupprimerObjet("texte2");
   cons->SupprimerObjet("Ball1");
   cons->SupprimerObjet("char2");

   system("pause");
   /////////////////////////////////////////////////////////////////////////////////////////////////////////
}



void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   test_unitaire_Controls();
   test_unitaire_Boat();
   cout << "Début des tests unitaires" << endl;
   // test_unitaire_Controls();
   // test_unitaire_levels();
   // test_unitaire_games();
   test_unitaire_characterAndprojectile();

   system("pause"); // Wait for user input
   system("cls");   // Clear terminal
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   cout << "TESTS APPLICATION (CAS 01)" << endl;
   // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;
   // Il faut ajouter les operations realisant ce scenario de test.
}
void Tests::testjson()
{
   Gameloader *gameloader = new Gameloader();
   Niveau *niveau = gameloader->getLevelFromJson("./levels/levelTemplate.txt");
   niveau->ShowNiveauinfo();
   cout << "Bateau joueur" << endl;
   niveau->playerBoats[0]->ShowInfo(cout);
   cout << "Bateau enemy" << endl;
   niveau->enemyBoats[0]->ShowInfo(cout);
   cout<<"hauteur enemy"<<endl;
   cout<<niveau->enemyBoats[0]->characters[0]->getHitboxHeight()<<endl;
   cout<<"largeur player"<<endl;
   cout<<niveau->playerBoats[0]->characters[0]->getHitboxWidth()<<endl;
   cout<<"image joueur"<<endl;
   cout<<niveau->playerBoats[0]->characters[0]->getimage()<<endl;
   cout<<"image enemy"<<endl;
   cout<<niveau->enemyBoats[0]->characters[0]->getimage()<<endl;
   cout<<"playerboat largeur"<<endl;
   cout<<niveau->playerBoats[0]->getWidth()<<endl;
   cout<<"enemyboat hauteur"<<endl;
   cout<<niveau->enemyBoats[0]->getHeight()<<endl;
}
