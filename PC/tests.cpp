#include "tests.h"
#include "Game/niveau.h"
#include "Game/game.h"

void Tests::test_unitaire_Controls()
{
   // Tests unitraires de la classe Controls
}

void Tests::test_unitaire_levels(){
   Niveau* ptrlevls;
   ptrlevls=new Niveau;
   cout <<ptrlevls->hight << endl;
   cout <<ptrlevls->wight << endl;
}
void Tests::test_unitaire_games(){

}
void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   test_unitaire_Controls();
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
