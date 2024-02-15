#include "tests.h"
#include "raftWars.cpp"

void Tests::OnEnable()
{
}

void Tests::OnDisable()
{
}

void test_unitaire_Controls_OnEventCall(EventParameters ep)
{
   tests->OnEvent1(ep);
}

void Tests::test_unitaire_Controls()
{
   // Tests unitraires de la classe Controls

   // Add eventListener
   eventManager->on("event", test_unitaire_Controls_OnEventCall);

   // Call events
   controls->MainAction();
}

void Tests::OnEvent1(EventParameters ep)
{
   std::cout << ep.parameter1;
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
