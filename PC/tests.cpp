#include "tests.h"
#include "Game/niveau.h"
#include "Game/game.h"
#include "raftWars.h"

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
   testControls = new Controls(eventManager);

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
   cout << ptrlevls->hight << endl;
   cout << ptrlevls->wight << endl;
   delete ptrlevls;
}
void Tests::test_unitaire_games()
{
   Game *ptrgame;
   ptrgame = new Game;
   cout << "debut test game" << endl;
   cout << "test sur le niveau 1 hauteur (1080) et largeur (3000) " << endl;
   cout << ptrgame->levels[0]->hight << endl;
   cout << ptrgame->levels[0]->wight << endl;
   cout << "test sur le niveau 2 hauteur (1080) et largeur (3000) " << endl;
   cout << ptrgame->levels[1]->hight << endl;
   cout << ptrgame->levels[1]->wight << endl;
   cout << "test sur le niveau 3 hauteur (1080) et largeur (3000) " << endl;
   cout << ptrgame->levels[2]->hight << endl;
   cout << ptrgame->levels[2]->wight << endl;
   delete ptrgame;
}
void Tests::test_unitaire_characterAndprojectile(){
   std::cout << "-------------RAFT WARS-------------\n";
    

    
 
    EnemyCharacter enemy(2000,100);
    PlayerCharacter player(0,100);
    cout << fixed << setprecision(2);
    int choix = 0;

    Projectile* p;
    cout << "Entrez la valeur 1 pour lancer une balle et 2 pour lancer une roquette." << endl;
    cin >> choix;
    while (choix != 1 && choix != 2)
      {
        cout << "Choix invalide. Entrez la valeur 1 pour lancer une balle et 2 pour lancer une roquette." << endl;
        cin>>choix;
      }
    if (choix == 1)
    {
        //p = new Canonball(player); //avec l'ancien constructeur 
        p= new Canonball(player.getWeaponPosition());
    }
  
    if(choix==2)
    {
        //p = new Rocket(player); //avec l'ancien constructeur
         p= new Rocket(player.getWeaponPosition());
    }

  
  
    cout<<"Entrez une puissance (entre 0 et 1)"<<endl;
    float puissance;
    cin>>puissance;
    while (puissance < 0 || puissance > 1)
    {
      cout << "Choix invalide. Entrez une puissance (entre 0 et 1)." << endl;
      cin>>puissance;
    }
    p->setPuissance(puissance);
    cout<<"Entrez un angle (en degrés)."<<endl;
    float angle;
    cin>>angle;
    while (angle < 0 || angle > 90)
    {
      cout << "Choix invalide. Entrez un angle (en degrés)." << endl;
      cin>>angle;
    }
    p->setAngleDegre(angle);

     cout << "\n" "-------FORMULE DE LA PARABOLE-------" << endl;
     cout << "y = g"<<"x^2 / (2("<<puissance<<"Vmax)^2 · cos^2("<< angle*PI/180<<") ) + xtan("<<angle*PI/180<<")" << "\n" << endl;
         
    if(p->checkIfCharacterHit(enemy))
    {
        
        cout<<" ("<<p->getBulletEndPosition().x<<", "<<p->getBulletEndPosition().y<<")"<<endl;
    }
    else
    {
        
        cout<<"Le projectile n'a pas atteint l'adversaire. Il a atteri a la position: ("<<p->getBulletEndPosition().x<<", "<<p->getBulletEndPosition().y<<")"<<endl;
    }
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   cout << "Début des tests unitaires" << endl;
   test_unitaire_Controls();
   test_unitaire_games();
   test_unitaire_characterAndprojectile();
   test_unitaire_levels();

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
