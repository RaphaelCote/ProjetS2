#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "Controls/EventParameters.h"

using namespace std;

class Tests
{
public:
   // Methodes pour EventListener
   void OnEnable();
   void OnDisable();

   // Methodes pour les tests unitaires des classes
   void test_unitaire_Controls();
   void OnEvent1(EventParameters);
   void tests_unitaires(); // Appel de tous les tests unitaires

   // Methodes pour les tests unitaires des classes
   void tests_application_cas_01();
   void tests_application_cas_02();
   void tests_application(); // Appel de tous les tests applicatifs
};

#endif
