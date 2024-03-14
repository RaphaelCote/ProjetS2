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

void Tests::test_unitaire_games()
{
   Game *ptrgame;
   ptrgame = new Game;
   cout << "debut test game" << endl;
   cout << "test sur le niveau 1 hauteur (1080) et largeur (3000) " << endl;
   ptrgame->levels[0]->ShowNiveauinfo();
   cout << "test sur le niveau 2 hauteur (1080) et largeur (3000) " << endl;
   ptrgame->levels[1]->ShowNiveauinfo();
   cout << "test sur le niveau 3 hauteur (1080) et largeur (3000) " << endl;
   ptrgame->levels[2]->ShowNiveauinfo();
   delete ptrgame;
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
   Niveau *niveau = gameloader->getLevelsFromJson("./levels/levelTemplate.json");
   niveau->playerBoats[0]->ShowInfo(cout);
   niveau->playerBoats[1]->characters[0]->ShowInfo();
   niveau->enemyBoats[0]->characters[1]->ShowInfo();
   niveau->enemyBoats[0]->ShowInfo(cout);
   niveau->ShowCharacterInfo(cout);
   niveau->ShowNiveauinfo();
}
