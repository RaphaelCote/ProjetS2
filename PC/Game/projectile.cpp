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


    /***********************************COLLECTES DES ATTRIBUTS************************************/
    
    float Projectile::getAbscisse() const
        {
            cout << "L'attribut Abscisse est égal à"<< x << endl;
            return x;
        }
    float Projectile::getOrdonnee() const
        {
            cout << "L'attribut Ordonnée est égal à"<< y << endl;
            return y;
        }
    float Projectile::getModule() const
        {
            cout << "L'attribut Module est égal à"<< vitesse.module << endl;
            return vitesse.module;
        }
    float Projectile::getOrientation() const
        {
            cout << "L'attribut Orientation est égal à"<< vitesse.orientation << endl;
            return vitesse.orientation;
        }
    float Projectile::getDegats() const
        {
            cout << "L'attribut Dégâts est égal à"<< degats << endl;
            return degats;
        }
    bool Projectile::getEtat() const
        {
            cout << "L'attribut Etat est égal à"<< etat << endl;
            return etat;
        }


    /***********************************MODIFICATIONS DES ATTRIBUTS************************************/
    void Projectile::ModifierPosition(float nova_abscisse, float nova_ordonnee, float nova_velocite, float nova_tiempo)
        {
            
        }
    void Projectile::ModifierDegats(float dommages)
        {
            degats = dommages;
        }



/***********************************RESTRICTIONS************************************/
    void Projectile::On_Off()
        {
            if (getEtat() == 1)
                {
                    MessagesApprob2();
                }
            else 
                {
                    MessagesErreur5();
                }
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
    void Projectile::AngleDroit(Vitesse velocite)
        {
            if (velocite.orientation > 90.0)
                {
                    MessagesErreur4();
                }
            else 
            {
                MessagesApprob1();
            } 
        }

/***********************************CONVERSION************************************/

    Vitesse ConversionP_Bargrah_Vitesse(float Puissance)
        {
            Vitesse v; 
            v.module = 1.0;
            v.orientation = 0.0;
            v.module = Puissance/10.0; // À modifier selon les propriétés du barGraph et les équations MRUA
            
            cout << "Le niveau de puissance " << Puissance << " correspond à une vitesse de module " << v.module << " et d'orientation de " << v.orientation << " degrés" << endl;
            return v;
        }

    float ConversionV_Bargrah_Puissance(Vitesse v)
        {
            float Puissance = 0.0;
            Puissance = v.module * 10.0; // À modifier selon les propriétés du barGraph et les équations MRUA
            
            cout << "La vitesse" << v.module << " correspond à un niveau de puissance " << Puissance << endl;
            return Puissance;
        }

    float ConversionDegats_Puissance(float Puissance)
        {
            float dommage = 0.0;

            dommage = Puissance * 2.0; // À Ajuster selon les décisions de l'équipe

            cout << "Le niveau de puissance" << Puissance << " Correspond à un niveau de dommages de " << dommage << endl;
            return dommage;
        }
    float ConversionPuissance_Degats(float dommage)
        {
            float Puissance = 0.0;

            Puissance = dommage/2.0; // À Ajuster selon les décisions de l'équipe

            cout << "Le niveau de dommages" << dommage << " Correspond à un niveau puissance de " << Puissance << endl;
            return dommage;
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
    void MessagesErreur4()
        {
            cout << "Votre angle n'est pas situé entre 0 et 90 degrés. Veuillez rentrer un angle valide !"<< endl; 
        }
    void MessagesErreur5()
        {
            cout << "Le projectile est INACTIF (État = 0). Veuillez modifier son état"<< endl; 
        }
/***********************************MESSAGES D'APPROBATION************************************/
    void MessagesApprob1()
        {
            cout << "Votre angle est valide !"<< endl;
        }
    void MessagesApprob2()
        {
            cout << "Le projectile est ACTIF (État = 1)."<< endl;
        }