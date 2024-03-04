#include <iostream>

class Shield
{

    public:
        Shield(int shieldpoint);
        Shield();
        ~Shield();
        int getShieldPoint();
        void setShieldPoint(int shieldpoint);

    private:
        int shieldLevel;
        int shieldPoint;
   
};
