#include "tests.h"

void Tests::test_unitaire_Controls()
{
   // Tests unitraires de la classe Controls
}

void Tests::test_unitaire_Boat()
{
   cout << "TESTS UNITAIRES BOAT" << endl << endl;
   // création des personnages et du bateau
   cout << "créer les personnages et les bateaux" << endl;
   character* pers1 = new PlayerCharacter();
   character* pers2 = new PlayerCharacter();
   character* adv1 = new EnemyCharacter();
   Boat joueur(3);
   Boat adversaire(3);

   // ajouter adversaire
   cout << "ajouter les ennemis" << endl;
   adversaire.addCharacter(adv1);
   adversaire.affichageAdversaire(cout);

   // ajouter les personnages
   cout << "ajouter les deux personnages" << endl;
   joueur.addCharacter(pers1);
   joueur.addCharacter(pers2);

   // retourner les informations des bateaux
   joueur.affichageJoueur(cout);
   cout << "size: " << joueur.getNbCharacters()<< endl;
   cout << "capacité: " << joueur.getCapacite() << endl;

   // retirer le personnage 0
   cout << "retirer index 0" << endl;
   joueur.removeCharacters(0);

   // retourner les informations du bateau
   joueur.affichageJoueur(cout);
   cout << "size: " << joueur.getNbCharacters()<< endl;
   cout << "capacité: " << joueur.getCapacite() << endl;

   // delete
   delete pers1;
   delete pers2;
   delete adv1;
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   test_unitaire_Controls();
   test_unitaire_Boat();
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
