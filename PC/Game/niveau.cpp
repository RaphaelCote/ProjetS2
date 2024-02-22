#include "niveau.h"

class niveau
{
private:
    int nbraft;
public:
    niveau();
    niveau(int);
    ~niveau();
    int hight=1080;
    int wight=3000;

    int backimge[1080*3000];
    void creerListeRfat();

};

niveau::niveau()
{
    nbraft=2;
    creerListeRfat();
}
niveau::niveau(int t){
    nbraft=t;
    creerListeRfat();
}

niveau::~niveau()
{
}

void niveau::creerListeRfat(){
    raft listeraft[nbraft];
}
