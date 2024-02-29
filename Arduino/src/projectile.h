#include <arduino.h>

struct Vitesse
{
    float module;
    float orientation; // L'angle est en degrés.
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
};