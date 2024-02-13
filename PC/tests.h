#ifndef TESTS_H
#define TESTS_H

#include <iostream>

using namespace std;

class Tests : public EventListener
{
public:
   // Methodes pour EventListener
   void OnEnable();
   void OnDisable();

   // Methodes pour les tests unitaires des classes
   void test_unitaire_Controls();
   friend void test_unitaire_Controls_OnEventCall(Tests caller, int num);
   void test_unitaire_Controls_OnEvent(int num);
   void tests_unitaires(); // Appel de tous les tests unitaires

   // Methodes pour les tests unitaires des classes
   void tests_application_cas_01();
   void tests_application_cas_02();
   void tests_application(); // Appel de tous les tests applicatifs
};

#endif
