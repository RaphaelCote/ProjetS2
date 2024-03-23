#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "Game/Boat.h"
#include "Controls/EventParameters.h"
#include "Controls/EventListener.h"
#include "Controls/keyBoardControls.h"
#include "Controls/controls.h"
#include "Game/levelGetter.h"
#include "Affichage/AffichageConsole.h"

// INCLUDE POUR LES TESTS DE PERSONNAGES/PROJECTILES
#include "Game/character.h"
#include "Game/playerCharacter.h"
#include "Game/enemyCharacter.h"

#include "Game/projectile.h"
#include "Game/canonball.h"
#include "Game/rocket.h"
#include "Game/grenade.h"

#include <iostream>
#include <iomanip>
using namespace std;

class Tests : public EventListener
{
private:
   Controls *testControls;

public:
   // Methodes pour EventListener
   void OnEnable();
   void OnDisable();

   // Methodes pour les tests unitaires des classes
   void test_unitaire_Controls();
   void test_unitaire_Boat();
   friend void test_unitaire_Controls_OnMainActionCall(EventParameters);
   friend void test_unitaire_Controls_OnJoystickCall(EventParameters);
   friend void test_unitaire_Controls_OnAngleCall(EventParameters);
   void OnMainAction(EventParameters);
   void OnJoystick(EventParameters);
   void OnAngle(EventParameters);
   void test_unitaire_levels();
   void test_unitaire_characterAndprojectile();
   void tests_unitaires_levelGetter();
   void test_unitaires_affichage();
   void tests_unitaires(); // Appel de tous les tests unitaires

   // Methodes pour les tests unitaires des classes
   void tests_application_cas_01();
   void tests_application_cas_02();
   void tests_application(); // Appel de tous les tests applicatifs
   void testjson();
   void testAffichage();
};

#endif
