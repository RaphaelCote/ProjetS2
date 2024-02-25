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

   // Add eventListener
   cout << "Assigning some controls" << endl;
   OnEnable();

   // Call events
   controls->MainAction();
   controls->Joystick(0.85, 0.15);
   controls->Angle(2.4);

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

void Tests::test_unitaire_levels(){
   Niveau* ptrlevls;
   ptrlevls=new Niveau;
   cout << "debut test niveau hauteur (1080) et largeur (3000)" << endl;
   cout <<ptrlevls->hight << endl;
   cout <<ptrlevls->wight << endl;
   delete ptrlevls;

}
void Tests::test_unitaire_games(){
   Game* ptrgame;
   ptrgame=new Game;
   cout << "debut test game" << endl;
   cout << "test sur le niveau 1 hauteur (1080) et largeur (3000) " << endl;
   cout <<ptrgame->levels[0]->hight << endl;
   cout << ptrgame->levels[0]->wight << endl;
   cout << "test sur le niveau 2 hauteur (1080) et largeur (3000) " << endl;
   cout <<ptrgame->levels[1]->hight << endl;
   cout << ptrgame->levels[1]->wight << endl;
   cout << "test sur le niveau 3 hauteur (1080) et largeur (3000) " << endl;
   cout <<ptrgame->levels[2]->hight << endl;
   cout << ptrgame->levels[2]->wight << endl;
   delete ptrgame;
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   cout << "Début des tests unitaires" << endl;
   test_unitaire_Controls();
   test_unitaire_games();
   test_unitaire_levels();
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
