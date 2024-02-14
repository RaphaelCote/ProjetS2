#include "projectile.h"
/*DIMENSIONS MAXIMALES DE L'ÉCRAN*/
#define HAUTEUR_ECRAN 1000  //Ordonnée
#define LONGUEUR_ECRAN 1000  //Abscisse

/*DIMENSIONS MINIMALES DE L'ÉCRAN*/
#define HAUTEUR_MINIMALE -200  //Ordonnée
#define LONGUEUR_MINIMALE -200 // Abscisse

/*DIMENSIONS DU COURS D'EAU (RECTANGLE)*/
#define EAU_X1 -200
#define EAU_Y1 -200
#define EAU_X2 -200
#define EAU_Y2 -200
#define EAU_X3 -200
#define EAU_Y3 -200
#define EAU_X4 -200
#define EAU_Y4 -200

    /*Méthodes*/
    /*Constructeur (État Initial)*/
    Projectile::Projectile(float abscisse, float ordonnee, Vitesse velocite, float dommages)
        {
            x = abscisse; 
            y = ordonnee;
            vitesse.module = velocite.module;
            vitesse.orientation = velocite.orientation;
            degats = dommages;
            etat = 1;

        }

    void Projectile::ModifierPosition(float nova_abscisse, float nova_ordonnee, float nova_velocite, float nova_tiempo)
        {
            
        }
    void Projectile::ModifierDegats(float dommages)
        {
            degats = dommages;
        }

    void Projectile::Hors_jeu()
    {
       

        if (x<LONGUEUR_MINIMALE|| x>LONGUEUR_ECRAN)
            {   
                etat = 0;
                MessagesErreur1();
            }

        if (y<HAUTEUR_MINIMALE || y>HAUTEUR_ECRAN)
            {
                etat = 0;
                MessagesErreur2();
            }

        if ((x>EAU_X1 && x<EAU_X2) && (x>EAU_X3 && x<EAU_X4) && (y>EAU_Y1 && y<EAU_Y2) && 
        (y>EAU_Y3 && y<EAU_Y4)) //Si le projectile est à l'extérieur de l'eau
            {
                etat = 0;
                MessagesErreur3();
            }
    }

    /***********************************MESSAGES D'ERREURS************************************/
    void MessagesErreur1()
        {
            cout <<"Le projectile est hors-jeu (LONGUEUR) ! Veuillez ajuster son abscisse !"<< endl;
        }

    void MessagesErreur2()
        {
            cout << "Le projectile est hors-jeu (HAUTEUR) ! Veuillez ajuster son ordonnée !"<< endl;
        }

    void MessagesErreur3()
        {
            cout << "Le projectile est dans l'eau !(HAUTEUR) !"<< endl; 
            cout << "Sortez-le de l'eau en ajustant son abscisse et son ordonnée!"<< endl;
        }
 
