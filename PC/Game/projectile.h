#include <iostream>

using namespace std;


struct Vitesse
{
    float module;
    float orientation; // L'angle est en degrés, convertis éventuellement en radians.
};

class Projectile
{
     /*Attributs*/
    private:
    float x;
    float y;
    Vitesse vitesse;
    float degats;
    bool etat;

    public:
    /*Constructeur (État Initial)*/
    Projectile(float abscisse, float ordonnee, Vitesse velocite, float dommages);

    /***********************************COLLECTES DES ATTRIBUTS************************************/

    /***********************************MODIFICATIONS DES ATTRIBUTS************************************/

    void ModifierPosition(float nova_abscisse, float nova_ordonnee, float nova_velocite, float nova_tiempo);
    void ModifierDegats(float dommages);


    /***********************************RESTRICTIONS************************************/
    void Hors_jeu();
    void AngleDroit(Vitesse velocite);
    /***********************************CONVERSION************************************/
    Vitesse ConversionP_Bargrah_Vitesse(float Puissance);
    float ConversionV_Bargrah_Puissance(Vitesse v);
    float ConversionDegats_Puissance(float Puissance);
    float ConversionPuissance_Degats(float dommage);
    
        
};

/***********************************MESSAGES D'ERREURS (PROTOTYPE)************************************/
void MessagesErreur1();
void MessagesErreur2();
void MessagesErreur3();
void MessagesErreur4();

/***********************************MESSAGES D'APPROBATION (PROTOTYPE)************************************/
void MessagesApprob1();
void MessagesApprob2();