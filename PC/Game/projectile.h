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
    float getAbscisse () const;
    float getOrdonnee() const;
    float getModule() const;
    float getOrientation() const;
    float getDegats() const;
    bool getEtat() const;

    /***********************************MODIFICATIONS DES ATTRIBUTS************************************/

    void ModifierPosition(float nova_abscisse, float nova_ordonnee, float nova_velocite, float nova_tiempo);
    void ModifierDegats(float dommages);


    /***********************************RESTRICTIONS************************************/
    void On_Off();
    void Hors_jeu();
    void AngleDroit(Vitesse velocite);

    /***********************************CONVERSION************************************/
    Vitesse ConversionPuissance_Joystick_Vitesse(float Puissance);
    float ConversionV_Joystick_Puissance(Vitesse v);
    float ConversionDegats_Puissance_Joystick(float Puissance);
    float ConversionPuissance_Joystick_Degats(float dommage);
    float MRUA_X(float VI_X, float delta_t);
    float MRUA_Y(float VI_X, float delta_t);
 
};

/***********************************MESSAGES D'ERREURS (PROTOTYPE)************************************/
void MessagesErreur1();
void MessagesErreur2();
void MessagesErreur3();
void MessagesErreur4();
void MessagesErreur5();

/***********************************MESSAGES D'APPROBATION (PROTOTYPE)************************************/
void MessagesApprob1();
void MessagesApprob2();