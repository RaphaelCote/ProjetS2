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
    void ModifierPosition(float nova_abscisse, float nova_ordonnee, float nova_velocite, float nova_tiempo);
    void ModifierDegats(float dommages);
    void Hors_jeu();
    void AngleDroit();
        
};

/***********************************MESSAGES D'ERREURS (PROTOTYPE)************************************/
void MessagesErreur1();
void MessagesErreur2();
void MessagesErreur3();


